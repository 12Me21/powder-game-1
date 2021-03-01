#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "menu.h"
#include "part.h"
#include "elements.h"
#include "vector.h"
#include "entity.h"
#include "ball.h"
#include "cell.h"


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
	char* data = "0012011000100*02102*01*03*06*05*01w00q00000.00u00T00p0B*00r01q00H00y00n0By0HH0Kn01u0Bx00t0E00Rn0ST0Bq0LT0Br0A10AH0Bw0LH0BH0F00Jp0cp0f00e00hH0dH0jp0gH0js0lp0n00ip0oH0k00J000w0b10D00tt0Sv0W000s0yq0Yq0sH0Dn0c010013H12H15014017H16H1900Js1AH1C01801EH1DH1100J10v.00o0Sz1KT0Xn0Sn0yp0yt0H10Z00ss0b01F01VH1G01W010s1XH1a01YH1As1UH0P000z1M002o0Sp1Pn1On1jn0Sq0*H15q0L01c01rH1bH19s1t01s01sq1qH0c10vw0tT0Xq0IH16o1e01wH1vH1ts2502401Yo23H1fm1gT0Bt0St0L11SH15m1y028H27H1as2K02J01Fm2IH1zu0Gy0xT0Bs2Fq1E.2NH2MH2L02W02ZH12.1810vm03q1F.2X02a018s2gH2j010.1C12d*21017m2A02hH2Xs2kH2km2qH1fv1*p0BT0dT2zp2yp2*00Ep30T2.000m1K12G010o2P02r02Js2t02Wo38H1fw1*00FT0Bp1jT3HT3J03G03Lp3I00Lo2oH12q2v039H2603S01wq2A12n136H0zn3BH2js3a024s2P13Xq13u3RH3cH1Gs3i01ru1e13fH0cw3D03UH3j03q01Ww1y13n00OH0qp3x00p03zH0dq3.p3yH0rH4203w13vH0O00Dr0Jy3uu0VT0Bo0Su0C12Gv0A01Bq2Q03Lq1Ov1nT2DT0Bu1o000v36s0Z10vv4OT2TT0XT4Bp0Ss2UH0cv4FH0zq4Hu2C00T136.0DH4Hm2eH4Yq0cs4Z13vv4Pq1Iu0Bm4h00Jv4Zs4ku4o*3P00Cu1014Rv0So1PT3Kp3Np4*T3Kq0S.4X04qq4jq4Hw4S034n31059T33T5Bp32p4BT0Gn2ov4mH2B*3Pv4rq4g*4u.4f04n034*5Jq5505Om4pv5H145v5K05Oo0KT4U01hq35q13.5NH1fo5Y00AT4A00Fo5Q04G05Ox0HT2Ts1Lo5Gq13s4Qu0Qr0Sw5g04Oq21q4O10vy5m03ZT4VT0Bv0*00KH16y0Jo4BH6501KH66o0so0sp69H68H6C06706EH12o6B06Eo6Ho6Hp6JH6Do6Bo0QH16w1fp0RT5*034p4Cn0I062013y6L06F06IH66H6MH6GH6cp6c06Zo6YH6fH6fw6Yv5et1np0Sm3Lt2U000x6Yx13o6KH6fo6Yp6Yo6wH6Dp6x06a06Ep6h00tH1Av1ft5fm1Qn6Vx1Ex6406.o6zp6zo6zH6d079H6fp7BH6Co60H6b06Eu1fu5ft5b07106gH0aH6i07E07C07So0ho7To70o7XH6Dv1Vu5I14Fw1Vw6sH66p7G06.p7go7AH6uH6yH6DH4MH7JH66t7bq7I06ZH66v78o7iH3HH7k07SH7Do7v00FH7xo6N05d01Et1fr1*m1K06qo6Vv1Yv7WH7m07y07UH0do8A06.H7Ro6Ys7uH1Ao78r1fq5fx7Nt8J017o78v6vH80H7fH8T07Sp7.o6AH6Ds78p4q07*o3H10vq8No6Vr8aH4O08c00zH8Vo8Y08D08CH8lH8U08no6to7wq6Cq7wo0B10vs0Wp5D05Ap30z5uw52p0Sx7Np8hq8u08jp8Fo6HH8HH6e08nH9908G07Ep8v07s07eo7w10vt4z03MT4.T3Kx5uu0S*0Wz1qp2ET3Ho6VH86p8PH8KH9VH86H1gr9Fo7VH8EH9do4B11Jo4Cp59v0yn1ho0Sr8y06oT9T11Sp8Jp65p9r067o7wp3kH1Ap8h096H9v014o0co65o65q0cqA009t10vo57p1lT1NT0dp4WT0Vo3PoA3o0JqA209t0AGH0j03sH22H9X0AJ018o9bH9dp9so7u10vp57T4Bn9ln59p92o2op9q067pAQH9Yp9zH19o1CoAd01FqAO01Eo8h19Jw0Eo3J*3Jp9No9UoAiH9Xo9FH9Z0AMH9*0AN0Av0Axo9406aq9F1ASw4K00Ln3IpAp14FpA.o6Bq9Fp78HAgHAwp9.07*0AyHAwq8hvB918ewAVTAo03Lx7NrBH08jrBA0BFpAwH0loBB03708ko7o081r7LsAm02Co0GoA7057x8OH86oAjH86tBVHAgoBQo81HBXH3io12u1Yt73sBd.1M*3KvAX14Fv89HBn03SoBS06ao15oBUo0su9806Ht1fs3F.Bap2S0871BwHBXo0sv8Yo9zo10qA3H4Z09GH2to7w04OH1Du84w0U00CT3Jx0Qo6Vw7dH7DHBo081p8Jo6boCEH12vC3oC211Jv9S002T60pCSH7Jo0sw6Lo3koCWH0jo8BHCJ06.w1Ev1f*57s0yv0F14Fx77HCKoAJo2DHC.oCZ0BEw6k1A5s1jr0xp76H6DxCF0AH039oAE0A*0CI03C067q12x17w1fn0zT0Vr0Em1qw7Ny17y5qH9voCG0CX03ss13x8mwDIs52u6Vy8my1Z0D9H3Bq17q3qo65s12y0hx7q01gH0dz0stC3HDcH16q3soDlH0anDiz1euDRH2kqDdH3ao65u0cx2Fu4Mw2Eq21.2Iw3UqDw039w3q18xTAUT9M09L03Ls6R05us1oo9vwDu02JoDuoEGH2Ko65w3i1E7o4on8.0EPT33sECwEE03UxDm03A0DaH2ko0sx3S1CdT2Tq5t10Zo9vyEJ01roDBoB80DDH1ao65yEMu0BzCtn1Op0x1Ee03s.2ZuC2H2g.E6u60w9iT0ap21o9v.EgH2YH4j0EH067.En05P1EsH3c*EVH3THF3H2Mo0s*Eau2Dw0xo52nE*03qm1qoBQH1bp9xp9xH1to65m3pH2X10vn5zr9Pq4Co4CT2TnFJHCln24pBSrBSp27o3h02J12drCe.5up1joC8s4XoDQnF1013pBjrB.p1coA0nF6x0DT5E00OT0Mo2EnFa039p1Uo1cpC000JrB.HAIH1Do6AnFF00xu4yT4Mn3Nr92n4yoF*H3aqFLHAuHAK06Fo0crFsH1GoA1nEnT5hrFw01huCuTDrT0aTBinGG039s3hoG3H9ZrFe01YsFgH2K18eT2TuGB011T3Kr0xn0SyF.1F803SsGIoAe013t78t1WoDfnFvuGjy0.qGYH2ktG1HALHGM0BAr1boDlnG9xGSo6UT51qG.02auGr0BDH12rBQr1FoDynGxTFxu9K*0ys1LnHAH2kw3Ro13q0i07*p1DwGf02410vz9mxDJ0GTn3Nm5aT0B.Fn03qwHCHGbpAtpCooELnF6z0yzHYoGnn2SoHcT4L01h*HdH3cxH008QH4FoEjHCBH0QnG9t1juGju9KuBdv5bHGJ02ryHf0BVqBAo0VHGJoEmnF6uBanH7TGCT4MqHN02Z.2vo0XHAwr17.HUH2514RT86mGSx9KqETH3i.I6H0z0EX08J.FS0FhuGWp4Bq92rH800FnGoqFM02h*HuHFC01B07e002nG9zIDpFY0HmnE0TIFo0Bn0Wo2DnIHH2XmBgH86uEvoFRoF6*0ErCRTGW0HYmIv00KuIx02No67u15u4BoEx01Kn0Eq0azJ8HEKo66r17r6NoF6q9mv1g1GpH3BpDCH19q7foG9s9PT4Bw4WpJH024qIz029H0AoF6s4yv59zHLpJYH27sDb0BVsEk0Ia0ECn0y.ECpHnT2TpJh01ssJaH9XsI4H2j11.nGnt9lT4BrJsH1btB*0BVoDloH6nC7sBax0yo1RqIhH2jwJu06BwJw0Jmz9jsF.T5Zn5go4MT86rK001V.Aa00Co2r10vuA6T0VnAAo0Xo5tT0X1JP02Zp4qrCKHJxu60v59r1QTJr1KYHEYH0aoCjoFA0Jm*0y*0yuKorBazCvqKA0DEoG4rFpHIOu4oq4Wn4CvKMHH4H4MoC2oKlHFTu0VxK7T86zI3o9zp0Jn0H0BEH3a18ex1LT4Ln1qrHs0DpH2To1ToL202W11.yBaqL70Cz067zHwHKEHKc01gn4WvB2mKnn9l1Kh03Uo0sq6Eq9DHHkn1LsFXTBgT86*1MoKXqKsH3cp540LB0JD.0yyJ5q0E*1N1LaHClHJCHLx0JlH2t19JsBat0D1Lv0Bz067rLSoBB1L*T60n9lo5tn5o1M2HLw034o0smLe0AJ12duBa*BKoIt01goK.02NpL9qKb0Av1FUv52rMNH2go0s.1U.Ij0BF1ASo4Wo4WqJqy1q.2FyLm0LQo0Jz9e0BF05OqLk05iT0VqJF0IfTIc162oBUHALy1UyMYHMt1BJT2DoGE1Ms0MkH16p4qpMQHMxu0QyK7n01yMgHC1HDrHNA0Lz0MHu0XvM0n0EyMenN7HLT0BFo65rMjHMt04wuM8T0atGjm1RyN80MkoC2nNVHByHN404On92s92T5ZmNSHNJHNNpL9pN30N005Ov0ywHYyB2nNdoNNH1Xo1TnNqHNX0N01JyT2Tt4WrNIoNo0HG0LRoKv0MZu2Tv1OrNx0NiHNpHKTHO60NCHNYnCtrO3HNyH1Dp4qoNhHOC05Sp0EsEorJ2034rOB0O401Vo69nOPHNsHOC12dpB2y0Wr1qy1hp6nrOMHOGHGsoG4oN*HNo1OTT5hx0.nK7oHarOZ0ONHG7HEOHOn0O80O410vx1MsOgn1nnOiT3KmNn0Ol01YpL9oOF0OyH4HxOXT60TIwT3Z00KoOKx0.pOkHOa0Bh00CHHcHOR0P01Oro3Nu92t1jpP90P00BDoMinOd0Ol1PGTOwo0Et1qz1hTIurPKHPAHMuH0MHPEHPX1FiT86T2yo0GTEooCOnOxHPX0OzHNZ0LpHPjH191GS*5uT2y0JV0P6TOwrPW0PLHALwCjHPa0Pw10vTJ3qHcnCOTPenFzTPu1M*HPn0Gv0M4nPOHPbu0GqBaTPe092pOj1Q60Pw0EhH7n05NoQIH1t10v*Pq00Uo0MpQGyNTHQ7H12pL9nO*HQU0NO00CqQ2091TQ5yQT0QM0Ims1THPzHQU11JqQD0Ba.EAmPi0QfHEl0LR0JjHQYHPouHcqQbT3HvPvHQt0Hv01SqLLHQzH4H.5gtQx1QHHR101Vp8bpQp01s1FUoQmx4W1R50R9HK*08o0RF01F1RBT0GxRDyQeHR6HIzrQA0RF1RK0Mnp8zT5C059mFwo2T1REHRO0OOH9d0RIHQNuIuo4yuPspCvyRN01sp41pRl09c09E0400RpH42pF6oHmqLE00ApQy028z6EzOpH1a1D3T0XuRwH25zLAHL.u3HqEQpRUp30q9luS101soFQ0Dj0BExEZHCKzRNoLCu4BsS91RZ02hoQ8z17xSF013zNToJDoHYrM1yRjH1voQ8y6YwPy06.ySRHJM.1jHM1qSV0Ft0SXH1AwSZH63HNe0SfH1G10vrCP06Es1IqSm0Q8HGO06qHCiH7rvCbH6OoQqHSI00Hq4ywQh1MC02ZoNzx1VvCCH1DxMgoND00DpRus5zw1SsSrHSlHMVHAf07OoQ.uEv09GoPyoOm0JDv3L.Kf01gp0xqT2qSsHS.0Axw1YuTLHHTHNeo9v1KRrIqs5NsTFoAdoSuu9W09H08k0BW0DDo78uN8oTcu4MrM0tKyH2THMU0QJ0BDsBOp78qLcH9Yv9FsKsoMRu0MT4otQDo3JoQEtU503GoU7TPdoU60MJnGjp1UsTg0AyoAxqB7HA108joCmq95pTzHKEoU206qT9TT0MqJ.0UUrUUT5ZrUW05znOXn6VpUGHTh0AzH9YoNso8hrAr0HvoAOoTIHTq03Fr1ht6q1B6HTvHTWHGb0ULHAP0KOoFOHIzpAbpA3pBj0HD0TPTMzT2TxUbHUr0TwHG5oADH4ZqV8tV8qAFoDSHG50Rz0KmT4Ms9PsV41T3H3BoV0pAZo9cpU.HAOpUz0AGpU*HQi0Jm.Jq00KqVI1Uq1VK02aoObHUf0JloUh0Uu0BhoUk0V0HUmzFIT0QqVYq9IqTV0SB0BDqUJ0DF0VgoVsoDBpUOoGsHAd1HWoGnqUVT5ZTUXTW105z*Kr07*1VaHVLHAwsTyH86qT.o7wvU0HAuoNtu0QtU8tU8pWITUB0U90Bam61pUc0NUHAwuTjH6doTu0TmoVh04foCU0UQq5uyKpTPg1VZqVpH25oG3wTYHQKHTaoUtHVzuMoT86wNkrGnoVJqWe0VqHAwwEVoTLuWuH7QoWk0TAxUR0P61WdHTG0LbH86xT6H7rH1AxWS0UQn1hw4yqBarWNt5w1W70DAHX3HSw0CL0XIoImxX7HWl01KoIqp5ut6nt2oqBm0N0oAwy1EwSj06XH9ZoOeuUS0HYzUpqDBHRQHCpH86ySYH7Q0SaHXY0WG00D.V40XSHOGzSOH6O0SQHOa15yTABTV310ZqWT0PLz8mxSPp0szPFuEoTJCT2DxXRHXe02rpPDpPZ062pY80OquHp0MET4Mx5w0Xo0N0pEonY0nHRHNY*4CzXnHY6H3azG60Xl.5YpIw1Xx0YHHNoo3ipCVHOSu4MtQmsY50Qs0Rd0YfHUm*HYwLg1YVHYP0M3H2tpDx0Y1002sTs1Uq0YW0Yg0YuHS*u4DqXd0YeHOCoYn0Vb0P.uNPoHcv52oYdoWrHRaHZ70RJuJ4*52v59yI3qXyHQUo2jp2joQju0QTYDz0K1YsHYlHZ8HZO0Z905fz1LyYGHZN0LQH2Kp2XoQt14Rz521Q*HZUHZPHZd0QZv4c.ZT0Yz0PwoZW024oR11Soy59nJo1ZM0ZiHZeHZs01W1KR.ZhoZ60ZV0G20Ws0RRu4M.Z5HX1HZtHa30QZuYxHCHoZxHUdH1apSCHRO1Zv1Zqoa80Yv0aGH4HzBavJOqYyoaFHa901FpUs0Rd1HWTJG1Zb0Zr0aH0aVHRe04cwaKHa7Ha20QMo1GpSuHZO1aR00tzYO0aUHa4Hak05Oua6qZE0aWo1CpUl0aH1aDqT.0aj0aW0awH2mua01Yk0avHR1o19pVy0aW1at0LpoaM0ax0aQuFZT8iu5u*XQ1a.ob6HYX010pWyHZd1ASnEzoEcTL6TIQta1oalHbP0ZQnJ6.59qZLqD8obE0O4oBT0b7H4Hn9jn1nybO0bZ0beHR.uEOTE8o3HyZwH0Av2Bn1mTbj1Zqz1St5r0Cf00Hn4yybko8iHCsTb900Lya100tq0sr2G11JTP4o4oybkwCHHT005O.IembU0Lpx3Y0T0H1f.c9yc5q15r4s04cv1Qt59s4Nq6Hw1Src1uY20NZTNvTGlqcG010rcIrCevLrqVWxUUqWOHDGqJKq5OrcXn92qVl058TMo1bDHb*0cVq4HrIquNkq6noC8r1nqb.wcOqQZrcon4WtGDqcUHGMqR2TP400DtcLqaixcCrbr*KyTIuycz0G4q4H*BK01Kyctqc0qQZ*LOn52TIf00Lwd8Hc7H8MoPsn9jwd3qcdH5en6nndSTIunMATJ4x0R1ckwc6rcIpHlT86nK8T1g01hvLrTHzT0R08NqdDH20H4HqJNT3HnGjxI0ndH0GkwJ4y1oq6dwdZq4Hs0Wq5EqKTTFxxGjqCundTyKK01gqdPH16rbrwJ6udd0W.obn0cR0cim9RrdKrcIq3LoGBtFxo4ynGmTbhoFLrYdzbqqMlpGjoUUoGypdHr4UtNP0C9q48vC5TPgTeJT5ZodqT0VpMpoOI00EudoTCR10Dw4T0MMTeb09kTenvK8oeKT2zqeV0DJpKKoeju0t0XboeRTenoGjweqT0C05mrP3s4Ar4Tpewwelzeo0f8oez00Cp0E.4UpZJq4A*f60HYpe1Te.TfJ002pfC01hrGBpFxrGB*0MyeZ0Mq0eCofAofAm5g.5EoQEoOKoWJTLATHWy3EneL05zofVTUTT0dtPS0Fwq4Mz8MpeSTfKz5gx3Jz60zfnTdiofh0QaT8ir0ExaSuE.TfKoer0btTV2rKKv0Qz3EpfvoeBpKn*Dr11.pg6Td.0B3T0G*Hz1gATf*TgE01Kqg5TgH0040gJ1gG0fNTFx*020gNuf.0gP0Hr*MruZJ02CpS70EPweI0gV0gS0W..f8rGjvSqH66zHus1UuMWnG405iHJJH66sSqnEZp1fxZ4Te3oFHH7rzgjnTL.1Uq69o6HuLKHFZH0QpgsT3HpBaoggoBVp6HsFP0KOqVO0I7HRcp8mHCKqhCpMQo0hs6HrMFn8mp6BpCyHIK0VSH9ssK3HWBH3*HAup0hthIH9u00ZpI9pMQn35uP4pgZT33oe9ogvo6frCk06*H8qo81o6t0hLH7Dr8Po8mo8PpTLrhKHCKpFqH6Drhn08mrDSohmohlHCKrhyHhkHhN0BEo7uo2BqfAvhj06.rc0HhuHgpH8qsKloDP0i4Hi3p8muiA0B3HALp6YrauH8qrhxsh.HCKviJsh8HiHoi6TepohqHgo00N07*rhXphmpEiH9XpWUp6Br8UrQKr0snHPHLAohJHI90ig0iZphnqi2rTuqhOpVwHA9HilH9ouE806TTFzHi3oiJrDVH7l0i8oPBoiJpiT0BEyiJnik0TloiJqImvhxoiX0iG0XIpiJo8msj6phb0CfqOJHi3u8S0jFpjOoCm0BEpim0jPH8qpTLqG8HiB0jFoj0HjYrjDHV80AGoi10AGrhiojEp6Ko2BtjEoQhohFHhTpAt0jSHhUHjYpaup8YpjnpWUogmq7gp8mq0hpjTrT.pifHiBoQVHjrpC*0j5Hk40hY0jSoCs*60ukA04OukCvM1u0aq9P*Hcp1fz3LzkH0TS11JpRux1SoY0HdoH7fn9xoYKH9TH7ru1UxMvH66wD.0fLTTrHgiHkR06InjHH0Mn8aoT70RvH0GHg9uKxTBcHhSpjYo7ephZ00NpG3qhBr0hqhBH9sthBpYLokst8RH86shRoksphCok3piBpAUHhOHIzoksqBQphW00hvka*jAHi20iGolGpkgoj2ok60j3HinplLolJ07hHhOoDq0jm0jeHi2o6colGo8mn1UrhzHlXHJapkg00tnCsslOHiHHk10iZojIHiYsjEqkjpjTojiHhOwiFplk0lM0BEsj6nlZHjYsiQ0BErcNnlfHitHlGqj.HLAricHLS08kp7wrgoplioldpiork006.shxpid0jU07*q8UqdUHm00jqqir0ljHkm04Oo9lqlg0jFt6HvlypmTHiC05NrjErlyvT7rmKpmUHlIHj2nlw0jq0ltpmV06EwkauUoTkIHlKHjdplp0mN0jZHJarmpojtHmKomAHiOH7tHlipjhHi*HJaohpHA3nmfpjlHn0HlcHlRHmOt9PnC8.8jqkwHWFHlAH0dslBHjpo8LHjo0nBHfjHiv00Nok30HS00RHWnHmzHnHHk20CD08s08XHmbHjppnGpjwHnD06EnkasOuTby*gRs1Ru5ZsKoTgIp0z1Gh0Gk0HYuWpT4F*gRxjKpX9TKjT3KylzHmWvEZnijnjX0PC0JcHmJ0o0t6HqMvnCsoFHT3KokPHOox1UngznkQ0o10iK002Hnb00An0sykav5zp1lHi3Hl90LBoVP0DSsmCHBCHCY0mgpiXpksokzHaopRnpauoDqpKboOnpod0GpqoW0UwHnFHm80hG0oP0mgoj.nbmTIGTHwniXojdola0lUoiYrh*0K2o6YqhE0mGoiQo7H0i8HCKulgo66.os07EolNHnOohmvlPop008npOP1ASTcQzipHjVHpI0i8pja0ltojEHWUHlGsmc0luH7JvmRpOQ0mhHl80pMHiRHn70pR0ltHCKskaqRuzHrnZCHlh0mGpm40iZrlyoohs7eribHNL0pKH8t06ZvpTHklqmd0iZHlbr7rrm4qi2pl3n84TcQrml03OTXrppjojc0mgrmw0lQ0i9H7Dw8IHkqHoN0XIrmp.mtHi0H7Dp6Yzq8oqH0gh0JE1E700LpC8x0.TXrohrHphppjrqLHlb0TlpqMoqHop1pSZrqGHmoHp1sq6o8mvqX0lU0mr0j3nfeTkhTLJT5hyBlHqD0onHjbHIKop9HpvrmCqm2o9spWC0nVHpcH7pHnMpjyHncpr00Tlqqz0KOsiTonOpqr0o*HA9ngsnC8u4IT0arMWokjqiZxCvugXuCet5tpMpwiZ.6EvLcroJp3ETe3vUU*gRrnmuP30GSqHLT2Dsh8nDlz7LTe3sqS0JcTLA*jFs1UtJOu60oeRrh9onCp9sHBGHhDHMQp6AzcEonf00tpm.0rD0qkoo.po.oLcz0PT0dy9knZ4Hn5o7Jrq6shmsiEHHEz0IE00X9VTrap1hmJoooxo8Pr8Yrpo0pqqByo0hraKEsFoU30Pt0fTnnx0D1Hmn0jFHGKos310AEsS09n0KPTdUT4VHj2pplHm*ojsH66qsRXsG0LsTeeH9Y0k8qr8HnUHsl0jSz081041sy*071syw0A0";
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
