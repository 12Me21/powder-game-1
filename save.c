#include "menu.h"
#include "part.h"
#include <string.h>
#include <stdlib.h>
#include "elements.h"
#include <math.h>
#include "vector.h"
#include "entity.h"
#include <stdio.h>

static int number(char x) {
	if (x>='0' || x<='9')
		return x-48;
	return -1;
}

int saveDataArray[120000];
int saveMetaArray[120000];

void loadSaveString(char* data) {
	static char base64[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,62,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0};
	int version = number(data[0]);
	char* bgmode_str = "0123456789:;ABCDEF";
	char* index = strchr(bgmode_str, data[2]);
	int bgmode=-1;
	if (bgmode_str)
		bgmode = index-bgmode_str;
	if (bgmode==0)
		Menu_bgMode = 2;
	else if (bgmode!=-1)
		Menu_bgMode = bgmode-1;
	Menu_dotLimit = number(data[3]);
	Menu_gridSize = number(data[4]);
	Menu_gameSpeed = number(data[5]);
	Menu_edgeMode = number(data[6]);
	if (version==0) {
		Menu_carefully = 100;
		data += 8;
	} else if (version>=1) {
		Menu_carefully = base64[data[8]] | base64[data[9]]<<6;
		data += 16;
	}

	int* q[0x1000] = {0};
	int qSize[0x1000] = {0};
	int e[120000], eIndex=0, qIndex=1;
	for (; *data;) {
		int q_size=1;
		int q_read = base64[*data]<<6 | base64[data[1]];
		data+=2;
		if (q_read>0) {
			int i;
			for (i=0; i<qSize[q_read]; i++)
				e[eIndex++] = q[q_read][i];
			q_size = qSize[q_read]+1;
		}
		e[eIndex++] = base64[*data++];
		if (qIndex<0x1000) {
			if (q[qIndex]) {
				free(q[qIndex]);
				q[qIndex] = NULL;
			}
			q[qIndex] = malloc(sizeof(int)*q_size);
			qSize[qIndex] = q_size;
			int i;
			for (i=0; i<q_size; i++)
				q[qIndex][i]=e[eIndex-q_size+i];
			qIndex++;
		}
	}
	int i;
	for (i=0; i<0x1000; i++)
		if (q[i])
			free(q[qIndex]);
	e[eIndex++] = 0;
	e[eIndex++] = 0;
	int a=0;
	int d;
	for (d=0; d<120000; ) {
		int b = e[a++];
		if (b==Elem_FAN || b==Elem_FIREWORKS || b==22 || b==Elem_SAVE_BALL) {
			saveDataArray[d] = b;
			saveMetaArray[d++] = e[a++];
		} else if (b==32) {
			saveDataArray[d] = 30;
			saveMetaArray[d++] = e[a++];
		} else if (e[a]<48) {
			saveDataArray[d++] = b;
		} else {
			//1 or 2 digits in hexadecimal
			int w = e[a++]-48; //low nibble
			if (e[a]>=48) //if next digit
				w += (e[a++]-48)<<4; //get high nibble
			int i;
			for (i=0; i<w; i++)
				saveDataArray[d++] = b;
		}
	}
}

void load1(void) {
	int total=0;
	Part_reset(1);
	int x,y;
	for (y=0; y<300; y++) {
		for (x=0; x<400; x++) {
			int xy = 400*y+x;
			int t = saveDataArray[xy];
			switch (t) {
			case 0:
				xy=(y+8)*WIDTH+(x+8);
				Part_at[y+8][x+8] = Part_EMPTY;
				break;
			case 1:
				Part_blocks[y/4+2][x/4+2].block = 1;
				Part_at[y+8][x+8] = Part_BLOCK;
				break;
			case 9:
				//Wheels.create(x+8,y+8);
				break;
			case 18:
				//Wheels.create(x+8,y+8);
				break;
			case Elem_BOX:
				Entity_create(x+8,y+8,Elem_BOX,saveMetaArray[xy]);
				break;
			case Elem_PLAYER:
				Entity_create(x+8,y+8,Elem_PLAYER2,saveMetaArray[xy]);
				break;
			case Elem_SAVE_BALL:
				Ball_create(x+8, y+8, saveMetaArray[xy]);
				break;
			default:
				total++;
				if (Menu_dotLimit<=0 && Part_LIMITS[0]<total)
					Menu_dotLimit=1;
				if(Menu_dotLimit<=1 && Part_LIMITS[1]<total)
					Menu_dotLimit=2;
				Part* a = Part_create(x+8, y+8, t);
				int meta = saveMetaArray[xy];
				if (t == Elem_FAN) {
					a->vel = (Vector){0.1*cos(meta*PI/32), 0.1*-sin(meta*PI/32)};
					Part_at[y+8][x+8] = Part_BGFAN;
				} else if (t == Elem_FIREWORKS) {
					a->meta = meta;
				}
			}
		}
	}
	Part_shuffle();
}

void Load_test(void) {
	char* data = "10120000RE00000000100*02102*01*03*06*05*01w00q00004000v00u01u0B*0200Du0F00Cv0E10E00Ku0J*0Hv0Lu0G*0Bv0Q00N10M*0Pu0O*0Su0X00I10V*0Y10b00au0R00e00Uu0fv0T*0W10dv0j*0cu0iu0Zv0m00g*0ku0o10lu0pu0v10u10xu0tu0z00h00**0s010*0n01200r*13*11*17*16*1901501Bv0qv1Du0wu0.*1801Cu1F014v1E10y01Ku1J*1Hv1Lu1G*1Av1Q01N11M*1Pu1O*1Su1X01I11V*1Y11b01au1R01e01Uu1fv1T*1W11dv1j*1cu1iu1Zv1m01g*1ku1o11lu1pu1v11u11xu1tu1z01h01**1s020*1n02201r*23*21*27*26*2902502Bv1qv2Du1wu1.*2802Cu2F024v2E11y02Ku0Js0Ej00p2Q002y2Ou00j00T00t00o0Bw2U02S10Ms2PT0Bu2Zt00n01q2UT2Uo0Fj0Gy2Tj2V02P02Ut0G10Aj2Vj2X12n*00y2lT2dj0Bj00H00r2Z*2gj2ro2j02au0Bs2c02nj2y00An2*T2Q12ty2v035H0Bq2f10A00Lq2.y3Bu2Zj36q3Eq2d12q032000s34u3JH3Dn2g03Gj2k12bu2h03C03713Fu2*03Os3Qj2xH3S13a13N*2u13Wj2mu3R03Zq3Mq3H13jT2w02UH3fq3nj3Vu33u3Xu3lq3L03U03cu3wj3e03m00Ae00S0Bp3b*3iu3vj3kj40q3yu45y3Ij49n3Tu4B10My2Wj00x4803r041u4Fu0By4H00Dc2Rt3xn01m2fj3u02ut2Zu00c2z03Pj4D100m4T03Oy4Ou4Xr33j4am4c*4604Vj2dc4Ys4R14bn3ou4Nt4Wc4mj40n2f90Bo4iy0Jy4Ov4Xp0Bt3xo4p04k02Qn4*j4Uy4Op4cj3Ko50y55n5304dt2Zp56H3Do58t5Cn5A*4jy59j49o5Fj44n5Hy4xt5Gj5Kj54t5PH4Kq2Xj4Ur00333n5W05Yq5Ys5Yr5Yp5an5Yz5Yu2f30Sj5Mj2yj57j3u33Ps4zn5Yo5Sj5k03232Qs4Xv4cp4TH3ro44o4p32Xs4Xw5un3rj2yp0B36202Q363q5g02Qj5ln3Pc4In5pH5WH64.2fc0Mw4634bs4Xy5*j5jH5Wp2yo5Ws6Em2f00Dy0F302r4Xz4Tc2X02fn60H5Wr6M300.4Xu6Pt6G.2zc6an2Zc0Bn5vj2y33PH0A34Ic0En6L05Wm6V36q06oo5Wo62o4v32R362q6336Vo6Y06.o5Y36qo6v02X37234bo62n0A10E36ar4X.6JH3r30DH64t5tn5Wu6dr7An2Uc6Vr00W0B02QW7Mt6X34IH6lr7F32Wy6Rz6e*4Tr2fH7C.6130025Wc0Dn5Wt6Gz6e.7Xt5vr6Ev5gt7er4fo5W*6K02zn6bn7dy6R.6eq73*7nr6Et5gu7Hc2Qo6pn7un4Xs7b*5Wv7xp73m7Xj36r6Ep7bo8036Q178*6eo83n7.c64p4Xm5gv6Gm69m73n84H5Xc2Xn5Wy6Gn69.5go8K06nc02300z6Go69y5gp8Rw6Ex7my6Rr69p6tc52337H7Cq03u5Wx69n5gr8K30A*6Ru2Wc7Gn6K38m178n7Dj6jq8h32fv8qq8vn8tH5Wq8yv8x*6Rn8z38ru5Wn92q8*H8g*91v9018sv99u94v9B38wH9719AH9Fu9CH7Cu3PZ73w0Q39Ej6jw2zZ5W.00Z73v9Mn92x0AZ7mZ5WZ73t9R39Rq7Gu98H7Cw9V39Z*9Zv9Rr81u9cj9Oq9Rp7dZ64q9Ro7GZ2z300w9Tv8qw9eZ73Z6tZ7RZ64o9Zr9l34Iu9jH81q9Rt9Xo9X32WZ9v39Ko8Nu6Rm9Vq5Wz0AH5w02XH73r9VuA4o9Zo9ZZ6lu9.w9Mm9VoA4zACj3KH6Nq9.Z9qoAIZ3P32XZ9wr8.Z6Nu6R*2QZ9qp2fZ81p7nq6jpAW32fo9h3AWoA339a3ASp9Xr9wq6YuAap9R09o36WZ64Z7GpAfH6LoAtoAk39anAloAJqAZ18Ap9.pAd39gpAx3AiZ73qAWx9XtAHZAvtB2uABpAjqB5w2QH2Us6j.Adr6YoA234IZATZ9wp9Xq6Lu8npAtqAJ37oZ9Sp2yu8pZA6q9.tAdo9w39rZ9q.9Rm8Xu6RtAbq6LZ8EZ9po9m39Zt9P3Az2AluAdqAOZ6DZ9wo9XvBS178tAboA32Bj29R2Atr9gZ9X2A4ZA4p9Zx9Vr7aZAKn9RuA4uAm*CA09.r9MqAhnB5p9Rz7ao5W2Al2C0oAtZ9r3AJr7GqASoBv32unAmZAFZ9vp9WwAlq9MoAWr8NZ6lp9RvBQ29R.5gwAG302nBNr9.nAdy8.u6RpAhZAv3Be3CUvC4wC4pA4q0BZ9vq8Nq9Rs6toAn3AzZ8CZBB3CN32QuA9oAUpBR30DZ2Q2AhoCNpAY3BNpC.rBNz9Vt94oC*qDB*CP3Cy30AuAan9ZpBNxCf3AWq81Z9qZBl3AmpB5Z5WwAbpAyZ78oAtmAdpBko9XpBE3CiZAVo9.*9a29Rw9QZ9nZ3FZ94nC*39rpD2oCosAYoDR3Abz7du91oC0ZAVmAduDs3Auu4vZ7zZ9vo8ipAjnAWpCSqBVwAS3E538UuDwZCJZ9YnAmrAInCDZ9WoAlsC1p9.oAWtDc3DA39KqCS.AMo9o2AmtBs3BpmDVtCvoDkpBdrCEpBUoAmqENZD.oB1302uD4Z2X2AmuETr9.zCd0BVsAJ2Ca39Kr8.pCEoBgnBkv6pvEgu6YZB9ZA6u9.sD2w9a0AW0F0oAtsDj39ur6Yp9.qAWyDd3Co3ENvBouEBsBdZ9qrEEZ64rAjx9o0AsoAsZ9qsCUqC5ZC4qDBZBM27326t2Bz30AoCI3Es3A5pDesE9oCEZAVqAtu9h2C33C03ElZ73p9ZsAtpFKqC8sB0Z6lx2f2FSpCK.9fn9zZ7c0C2oDv178uDQ2AJo7a3CNqBkpBdqCN.EW3BNoFfoFjZ6VZAo3F3wFo37aqAd2BUZBnoBc39Vx7jZCYZEx34It6RxAWm5gqBVZBCz73oFM3Dxo6tn7asGBqB4ZAKZEhZDtpGVyGMZAVZAYpA4y2W18AnFz2FR3Eh3D8pFSoCKrFVZ2QpG2ZBCo8N2Cc252ZD8rF6ZFGZCOrASq9w*8QZE23FTqCNoDWtCnnFzr7axGLpEC2DipCKqFSrAW2A739VpBnZG.oC1Z6lZ9v.8XZ6loF2ZAlxGeu8.2CK30A2GhoGgxAb2C0pCMZ2z2Cd2F729P2C0*FxoGVq9w2DUZBloEwsGPZF8ZDlqAlvHM2CKtHYq9l2Bz2Ak2HSZEhoC0vAbuC43AUqAX3AN3FzZC4.Exu81t0F22Xu2V275T7a*Cd3C8oBCpF8o9apCvqC4oFztFzqCJ3ID28inFzoFzuIF3H32HOrIJuFzy3EuGAuI2.2fT7apDbr7atAV26YnI0q0ET7a.IRpGAzHO29q26l10E22Qw2VpCJ.I0p9rTEhp6a1IfpIkoIS.Ijw2VoIp1InwI2qImuISwIu.I0*0220e20420a*071041J2*J1w0A*";
	loadSaveString(data);
	load1();
}
