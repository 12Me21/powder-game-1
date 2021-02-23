#include "menu.h"
#include "part.h"
#include <string.h>
#include <stdlib.h>
#include "elements.h"
#include <math.h>
#include "vector.h"
#include "entity.h"
#include "ball.h"
#include <stdio.h>

static int number(char x) {
	if (x>='0' || x<='9')
		return x-48;
	return -1;
}

int saveDataArray[W*H]; //todo:
int saveMetaArray[W*H];

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
	int e[W*H], eIndex=0, qIndex=1;
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
			free(q[i]);
	e[eIndex++] = 0;
	e[eIndex++] = 0;
	int a=0;
	int d;
	for (d=0; d<W*H; ) {
		int b = e[a++];
		if (b==Elem_FAN || b==Elem_FIREWORKS || b==Elem_BOX || b==Elem_SAVE_BALL) {
			saveDataArray[d] = b;
			saveMetaArray[d++] = e[a++];
		} else if (b==Elem_PLAYER2) {
			saveDataArray[d] = Elem_PLAYER;
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
	for (y=0; y<H; y++) {
		for (x=0; x<W; x++) {
			int xy = W*y+x;
			int t = saveDataArray[xy];
			switch (t) {
			when(0):
				xy=(y+8)*WIDTH+(x+8);
				Part_at[y+8][x+8] = Part_EMPTY;
			when(Elem_BLOCK):
				Part_blocks[y/4+2][x/4+2].block = 1;
				Part_at[y+8][x+8] = Part_BLOCK;
			when(Elem_WHEEL):
				//Wheels.create(x+8,y+8);
			when(Elem_WHEEL2):
				//Wheels.create(x+8,y+8);
			when(Elem_BOX):
				Entity_create(x+8,y+8,Elem_BOX,saveMetaArray[xy]);
			when(Elem_PLAYER):
				Entity_create(x+8,y+8,Elem_PLAYER2,saveMetaArray[xy]);
			when(Elem_SAVE_BALL):
				Ball_create(x+8, y+8, saveMetaArray[xy]);
			otherwise:
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
				} else if (t == Elem_FIREWORKS)
					a->meta = meta;
			}
		}
	}
	Part_shuffle();
}

void Load_test(void) {
	char* data = "10300000e100000000100*02102*01*03*06*05*01w00q00004000v00u01u0B*0200Du0F00Cv0E10E00Ku0J*0Hv0Lu0G*0Bv0Q00N10M*0Pu0O*0Su0X00I10V*0Y10b00au0R00e00Uu0fv0T*0W10dv0j*0cu0iu0Zv0m00g*0ku0o10lu0pu0v10u10xu0tu0z00h00**0s010*0n01200r*13*11*17*16*1901501Bv0qv1Du0wu0.*1801Cu1F014v1E10y01Ku1J*1Hv1Lu1G*1Av1Q01N11M*1Pu1O*1Su1X01I11V*1Y11b01au1R01e01Uu1fv1T*1W11dv1j*1cu1iu1Zv1m01g*1ku1o11lu1pu1v11u11xu1tu1z01h01**1s020*1n02201r*23*21*27*26*2902502Bv1qv2Du1wu1.*2802Cu2F024v2E11y02Ku2J*2Hv2Lu1.r00x0062S00Ey0Js00w2Tz00n0Br00y0Jt0D602o0Bo2b10Vu2Tw00p0Gx0Jw0E62jq0Bx2S10Ms2mn2j000t2To2Z00Ex0Jn2mt00o0Sn2un2ax0Jy2t600z2vx2z62zn2fx2ct2in0072sp2j636002w0Jr32t2Z72X000r3Cn2vy2X10Mp32r2vo3Az0Bt3Cm2vw3Mu0Bz00s2Tp2f62Zn0Bs3An2vt3C.0Sw31s2*02X73Z02Sp2Tx3e10Mx3W600.0B.3Av0B70D033p2Tu3lu0Bw3nz0G72t03W70Vp2Ts0Bu3U02Xs3k03Z73W02z73r02j746m0A646u42v3nx0Bn3Hv4872z04703Ar0Gp2Tr41w0Ju4E03673303A047s4L63J00Ew2cs44o4Gn3pp4002tw2Ws2Y000m3Ho2v73rr4a646t42s3x00270An4Hr0By3Ct3Rw3Fs2T.3p72q73z746y3Cu4s10Mq3n*4vu0S74V73rq3wp3u04W14*s2T*3V73sv3At5400Ep2Tv3v00As2Tm3473Iw3Ax3Rp5F02Xw4t60Hw3Ay52x3ap56y42t3ns3Yr52y48u3Aw5T60Mz5Vs4bo4M00E74fn3R73rv0Bp3Cv3pw4X64Vp5fs3Ap3c73sp4z04fx4d646p5fr4So3bn5i03Au4Fp56n2pu3as4bp6472s73iu5*02Zp56o6203Js4bq4b753n2vu4S73z.35v5kx5Ps2a65o74o03ht3po56r6Bq5W03nr2f74o44Iw5C02bo56s6Ss4bs5f73Wn4H02t73zw6J02tx0Jp6Tt4M70En0B44173zv6iu6Bp6l63.s4h04St6Yu35u3wx0Jo6Tu4070Dn6pt3Ro56x6Bo6Tv6mu2vv3Aq3ro2ao5Ny75s5fw6mv6G74i00Ao56.6Bn6Tw7Fn6p04K02jo56*7Ks4bw6my3ry52s2fo56m2gu4Fs5fx6Et7A05R00D74Ao5Nn7Y02Zs7a64673N72b07es0Gn56p7hm7L70B60023X06Yo6Hy7V03on56q7qs7S77sr3rs6Vv7Hv3As3Vn6Ry0Jm4Ps0046ds8207Ov8402Sn5Ns7.67mq6H60A08Do3A*7xw2Z60Mu8Gy0Bq4S63.t3r*7xv8Nu0Sy87s2Ty8Q77ss3q047x52t3Rn5Nw7hn3nw3a78073I72Uv6Ys8Nv2oy2xt8976mr3T746s8V033y8p78a76Ow8Dr8u.7hp32s3A43Ao7873zp8n002y6.t89070o8q*3w75wn61z0Jq6g63J78qn7Gs2fn5No3310Mr9078qo2vr6Yn95p9Lu2at70s4hu0Bm8Nw8Qz2Wt70q6v76I63Is9S03Wt2u72T79hz2vz44t9eu2t29g.3L63Iv9et32o89649x3462Uw9qt4M43qn2o62Uy9es2t44I62z49hu3T62U.9emA002mr8D74Rx44m3o10MvA760A72Uo8Nx4F.2lt3X72T05a05h62UpACu3wtAL63.28D.44rAP02Xt5In4q62UtAVx9r24u23Cp3Yx0S.0Jx32p6X.31t5Io4q.87u3903o.4OuAX04f*87v5e*2O*2Av2Q02N18O*00W0B002uAu02I12M*2PuB0vAw*B310x*071041B9*B8w0A0mO6";
	loadSaveString(data);
	load1();
}

static bool onscreen(int x, int y){
	return x>=8 && x<W+8 && y>=8 && y<H+8;
}

static int wrap(int a, int b) {
	if (a<0)
		return b;
	if (a>b)
		return 0;
	return a;
}

void save1(void) {
	memset(saveDataArray, 0, sizeof(saveDataArray));
	memset(saveMetaArray, 0, sizeof(saveMetaArray));
	// blocks
	int x,y;
	for (y=0;y<H;y++)
		for (x=0;x<W;x++)
			if (Part_blocks[(int)y/4+2][(int)x/4+2].block == 1)
				saveDataArray[W*y+x]=Elem_BLOCK;
	// particles
	Part* p;
	for (p=Part_0; p<Part_next; p++) {
		int x = p->pos.x;
		int y = p->pos.y;
		if (onscreen(x,y)) {
			int xy=W*(y-8)+(x-8); //w must be 400 to be compatible with vanilla pg
			saveDataArray[xy] = p->type;
			if (p->type == Elem_FAN) {
				saveMetaArray[xy] = wrap(64*Vec_angle(&p->vel)/TAU, 63);
			} else if (p->type == Elem_FIREWORKS) {
				saveMetaArray[xy] = p->meta%100;
				//fix thunder saving badly :(
			} else if (p->type==Elem_THUNDER){
				if ((p->meta&0xFFFC)==6000)
					saveDataArray[xy] = Elem_METAL;
				else if (p->meta >= 7000)
					saveDataArray[xy] = Elem_GLASS;
				else if ((p->meta&0xFFFC)==6100)
					saveDataArray[xy] = Elem_MERCURY;
			}
		}
	}
}
