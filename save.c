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
#include "reset.h"


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
	Menu_gameSpeed = 1;//number(data[5]);
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
	Sim_reset(true);
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
					a->vel = (Point){0.1*(real)cos(meta*PI/32), 0.1*-(real)sin(meta*PI/32)};
					Part_at[y+8][x+8] = Part_BGFAN;
				} else if (t == Elem_FIREWORKS)
					a->meta = meta;
			}
		}
	}
	Part_shuffle();
}

void Load_test(void) {
	char* data = "0072030000100m00r00003T03*04T00*00n07r09102s04r00T04p08T07000z09T0Ho0Jo01m00s0FT08z07p00p07v0Bm0N00RT0Hx0IT0Hr0J00E000v0ZT0HT04o0L100y03005*0Go0900Ez0By0hr0aT0Hp00X00t04X04u09X0en0qp04z0u00IX0Dt0o003n0*r0c00*T0Kn0Eo01y0hp0Et0800Ev0R10gr0O01300NX04q0q00qo0FX1J000o1HX1L000q1I01Hp0w00RX0s01OX0DX0eX0so1GX0R01S01Ho1Ro1cX1Zq1PX0.T0Hn12T0Yn1ET0d01Ln1510gq04n0Jn00.07n0311o009n1k00as1Hq1QX1W01ao1z01LX1Ko20o1Hs1Hr1bX22X2700rX1.o23X1Kn0rT1lT1pn1wr1i01Eo0fy1O00V*0jq16q1Dz1wT04s1yX28p2601*X28s24X1V02102U01F01ap2To2W01an2D01En2HT0Dn2P00ao0fu2Kr0E*0Gq1NT2E00*q1601LT1L100u2mT0Hz2js2R02bX1NX1.p1zo1Tp1Rp1Hu1Rq1Mo1Yp1Kq1f021o1Wp1Yo1Tn2fT1ln2h01mT2p02jq2so1nu2Kp2n*0Ew2qT0vT3IT3P01O10g02to01u3MT1lz2j.1au0bT2q.1501wo0L02jT1G13Uo3Lq0Q*3S.3dT2qo3fT3ST3hq00b3Tq0eT2uq3rq0Mq3Sz2j*03P1Gt3m01E.3*T1lo3o03J11Ob3s03V145q3w01wz2jv0iu07x0kT1014812Ko1nq3v102q3xT3Sv05000w2Do4MT0KT3R00*z0*o4103eT3ub46o4Ib3Tm2KT2E13UT3St05q0r00Eq1ZT0bn01q4Jq3to4kb4aq3P14d01wt4NT0eo0qr1Vp0tX1.v2dq2t00at4VT0Hv4UT4ST50T3nT5202IT4Xq4k047q4Jm4b01314qT2qr05t4O00ln4nq58o4Zq49T4cy3p00bX2Ky0yu1Rm4zT0Ko2zo25X2QX30X2*02YX1No33o0*t4*00av51o3Sr3g03V05ho5K14HT5714K01k15D01Eu2zx0yt20z1qv0Ap5I15lo5wm5BT0d15pT1lu5UX1X01Up3701Uo1TX1KX1Kz3Go21r1Kp1Rs2cX2SX1.q5S04P02GT54o5gT5No5dT42T5mq4m14Gm5z00o15*00*u1Ht1Po2Tp6XX2AX5aX1To20x0Js4gT1Lr5wq6Pq5Aq4py5Nv0qq6BX5X02Yp6Y05Z01Sp04y3GT4tX1Y02Yr2do6po2B002o4rT55T0DT6J06I02jo6M05f14Gq6hb4o05oy5Nz6yX0ho4u06oX6m01az18z6g059b79T5M02ju6102Zs2dp26o7Gz0az74o7Er1Ru6Yo6bX27o04*3Gt75r4Wo6K074T70076q4l07Kq5L05Cy5Nu61o6Z02Zp6Do1.X6nx1Ax5NT4m05jT6O07j15nT7MT4MX3MX62q35X1eX5YX27p6sT2xT3xp6l000x6GT0Ht7cT72T8E07fo7u07yq78q7kT5.y5Nm0y.2tp5GT8FT6No8Ho75T4Ro7Jo5km6RT0716TT0Hm8No1Ez2jy0NT4ip04t3mp0Q05iT8f08jp8io8h00Ep8mT2pp8iT1Zo5kq8J17z07l02jz0Vv2vH0I000H8A08*x04H90H19H94o8VH5mm8X00E18Z07Tp4AT3Sw8eo0tH04x8*08AH9GH7aH9K003H7xo8*o5wy1Nr3Gz8xp9C01wy0N18z01Bu9Hp3WH0F19Wp16H9ay9Y11OH2v18zu16o71t8Pn1Zw0Bu9eu9nH9au9ey9qH9aq3rp04b0RH3Wb1Zb9v10go7100G08cT88T2qz3yn0*.5iw9mH9pHA709XH9dHAA01Bq9t09tH9wp9up8*19z00Vx8.wA60A90AMp9Z01By9r0ACb0rH9wtAHu1Nt0**9TTA2pAX01E*12.5is0Bq8gH58tAHq3rtAgbAS12KxAg09I145xAixAUo71n3Uw3fsAd0AjqAe145tAitAlxAyH4nxAoH3Wo9.T0H*AZT3YpB30AWn4Un3dwAsnAfHBA1AwH4ntAz1AkHA.HBG12vo0Ox8P02knB8n3dsAttAltAxHBDH58xBEq3rxA*1BI00V0AaTA2T3SoB000RnB5T0Hq00P8gn4Vo3fwB912KtBPHBR1BC1BF1BoqBUHBHu1Np1w*Bd02k1BWp0E.4im1Z.BNnBBqAvqAhHBmq9J1BpbAmqBq1BwT2q*BuT0e1C709*T3YT3Sm12vBhnB8T1N.B.1BkHB*bAubAu0C50C5bCPxAp0BXT1l*C902uu2pn4g.CJqC00CMtBQ1AnHBHqC6qC6uBsTC8TBZ03e11OoB10CC04TTCEn0*vCGT1Nw3d.CY0CNtCbqC11Cc1CxqCebAmuCg0BY0A00CjqCgx0hwCHo04.CttBl1BnqCwqCzxBVqCfo1DTCTTCiT3n1Ck0CS00a*CUm0Jp04v8nsD504OTCIT1NsBOHCLtCvbCQHCdbC.oDE0AWTDG02I1DIT0Rq910DfH93x92*Di00b1CK1DlqDAbCMxDCbDW1CBT1lxBf0DJT0WP5NxDtP0FnDtr1wxDtpD.PDwP6Pu9o0AN19b10gHABp2stD8qDntDpxEBHBbpD.TDZT0WT5Np00E2Kq0aPDyPClTEG0Du00ax5hpEIq1GT3huE3pAOpEV1E60APH9d0CuHC2bDoHDXxBVuC*T42E1GE1Dp3eEEh0EOTEg01OE1DPEL04s04UEEkp0apEj0En0El0Er0Evp0aqEWuEU1E5yAQpE8HDUHEbxEC1CxuEf0ExqEI0BXpEuqF9p5jEEsT04PEprFBEEiT3nEFE074EFKqE.HA8pEWyF113UtE9bCaHEdHFU1Dr00*pER01OTEF0EtEEJTEHEFc0D*nDzT2qpFYqEtTFhEFeT3SpFiTB*0CNs3rH4n003bBT0COuFotDVtF5qDBHEDT2qtFCTFaT8gEG005cEEo0BcPEM04.EFI01EtF*02jtF*1Dm0FT14503rrFtxAluFvHEbtFxbDquF7T8CEG8T1ltGAT4eEG4p09PG6TG10FATF.EG2TGO00V1GDtFwHBSHGe12KuGJ1D9bEc1CybGMoG2xFj01ExEQEFePFGT2qxGnTDsTFdqES1GcHGKHGfqC3q0t1Gx1GitGLxEeoGmTH402jxEK0G50EqTENpEE0H6TGhqEAHGz0Fu1H0qHE1GkxF5uGN0EPTH5T3SxH7pGU0H90HM0Ewx5hx99qCZtGd1Bp0HGqHWHGy1HJHFVuHLT9GTHN0HBPGr0GoTHgTGsTHDbGEqG.0HZ0Ea1H1HFVqFy1FWT07zG0z3pzFF0H8r1kzHw02PzHmtCv0COxGI1HHbHnbDqqHtuHLxFg00*xD*TGsP0FPHiTDv0HRxIC0GoPCAqHa1Hr1Hc1Gg1I5tDVxH2HFz0FXEFer1EpFn0EwpIWpFfPG6pIWrIVEFep1wpIWoI1HF4HCd09gqILqIkbI7bGl0EOtGArG9EGP0F8EEiPIF0G70BXrIq0GX02IEFKoIg1GixDC0Ij0HqqIlxIR1Hu00rE1DrIxpGt0Is0FAPIuTGWp0arJ9TG2oF9qGAoI*qDnxJ1uHD0J3bImxH30EOpIbT1lpIYTFkqES00RPJD00REIUTJTEIdTJV0FZ03u0JOtIQHIiuJNtFSxJ5uHLtIpTGQEIrT0KEFKpIZ0HRtJn0G30IyTEmqJJ1IPHIh1Cy0J2tE90JOxJloFatJuTGapJATJq0EyTIE0HzTJo0IwTKCpK702kEI.1Jz1J0HJi1IMqHIqHtqI8oFapJS0ITqJWpIeEIdPJYpKQT0pEJc0IcqJWoJKbGjqCe0IjbI6tJh1INqDD0EOxJFTGu0HTTKApHQrHj0IHTH5oKbtFx0KetHXqJLHHsbDY0KjTG6xKFTHf0JX0KB0IBTK.TKr1KIqKw1J*uHbqKMbJPHBroFaxKk0L30Km0L1pKoTKlrKppHBoKsHHs0KuHL9bKcbLB1HuzEMzH*pJsr13zLT0ElzIK0JgHJ.qKduLPtKgqKNbKypIBP8gTIGrIJ03z0L2T9GPLi0EPPK.P3q0La1KJ1L81KLbI6xK30DJpIWtKR0JerKZ0L*PIupLzTKXqJWrM0qEz1L6bLQxI4qLAtLebLRuF7tGAtJvpLETK6T0DPIutMFTMI0JtE1DqLM1Kh0LO1LvtJ5qKipMGTLoTJETG6tIpP8gP0htIATMX03E0J70KD0MV046tFStMCxAlp3v0LdHLbbMDoDZpM30FbqM5TLJPMa0L1tMc0JZqJWtL.qMH0HSqMPqLft041MSHMoxHKoDZoF9u4.TK8uM*TMdrDttD*PMvrExuN90KG02vTMYEMO1HH0K2HDXtN3qMBHN5HHdoN7E0tTMW01LENU0MN0IwPMvpNDPCloN8TNVoNd0NYpM7qIk0NN1GktNPbKfHNR1INuF7pMrT0FEJa0LFrNb0MwPClpNq0My0L*TKlqJjHCLxDptNltKvbM9HNS0DJxNHTL0rKprDtoBfsIEs0ePClxO708ATL40MiHN*1Khb4g1N41LtqLfxCRpLFtNtTMu01LP0xPOD0EqxOFxNB0OG0OI1NMtGLtO2HMn1OKxJQpOQTENrO9POVzOAPOETNVxOYxNh0J30NjqCztOd1OMqOOHLC0CSzMWzLXrOl00IPOVr0ozOy0H9zLrp3vH58pP51LvxO10OeqL7qOv1CBxDtvLp0MexNuoOB0JXsP0TLn03b08APOnP2Q1OubO41Aw0PAbPRqKO0BXx5eTL0tM.TMvtNE00rP9.xPX0OZtPZ09VqNQ1ONbCPtOtqPiqPCqMUTMdvIvpOFoNftNupNurPqTDNTMdtNGTPPqPmbPUbOLqP.tMTbLgTPpTPxTNATPaPKAtIAtGAvPv0MeoNfsPTtOc0QEHKxxEen6s13X0OZvHStPgtPtPNFTL0vQMTM40JesQG1OKtPlbNm1OfHBrnQJq1DtQATQ50NIqMFPMarQP0MfpPetML0QeE1DsQUqN20QnbLRqCfnQa0BXtQc0QiTNeEFKtLVTQ40Qv0QCEFKsQpxP91PQtQ2xAUn3tuLZpHSvQR0Ms0JetQy0QLTPYTQSq1x1R3HKxtNPHIjHRKu4kHRKyRMyRO19fy2sy0ExNXxPexOXTNanIAxRUTOnTPzbQXqPBbPk0RMv0eH5Go8*wRfwRf.Rj01LH1r0Rl.9p02ts0ktR8TRE0QMPHixRY0PGTRatO3tQF19fvRi0RlwR*o8*.RkoS20Rn09XT4j08e0RD0PfTENtRCxRvtLFsR1HNO0Re0S00SIoRh0S5oS4oSMHRmp3WT5301xTEJPHv0Pc00l03EzRWPKAT8.tDtTSZTSTsSF1Nk058m0r1FcuESu07qJWxPETPLvPFvJspSnTSmTPLuSdqOs0Sft4kT4OE0EP1AE0oqKSEFevRAqPepIWvSoTNrqJWvT0TPw0Nyq0auSsbRd12KmSgq0oH1LJ0EJ8*TEIT3tHTFT00JTHESz0JeoJIE1DvQl0BXvNIu5ePEppTRpPeoTP0TST0eENXuTAxAx0Su11OP8oHTLpTMT0QHThH0EETNqTWTT7oTYpTXENXvT30NW0K90PMoTpTToETb1RH1QV0Af819t098U0n008U28U4*G*q07E0EH05E0oEU8rTlTSj0JexRvvT600bPTVTQQTUJ0T8TU6bRbbPUH9gy0Uu58TTItTI0UCtUTTFeoTw0TvEFKvQBvTsoUXvTn0PMtGAuTcHRMu16sU60TlqUkTU7qUl04h0TOEUZTTa0TuvUaPUI0TtqQuoUcTMduUg19fuUiH8g14bsTIq07sV20UoqUGvV6TT40JevTspT2TV8qT1EFeuUzq8*uU*oPz08epPwpESqSkTT7xUFPUuxUFTL0uVF03sH00c2K.9fz9coVIsHSsV5TUKxVO0H8pRr0S9xT91TzqKN046qVU01rq8*zVX0Ph0S8xSRq1GPQQPVbTDNPTVPVs0VfTUMtRyHLNq58qVk.VW1E6oVYT0hT4gsUopBx03bzPwzVu0H8oW7vSVvSVuVSqV*c9GrVns3W0S8TV0qUDp1xnEPoJsoWNT04w3uHRL1U.1WUq8*yRPqLrqVkp03cCrn8*q58s0EuLZTQKoDtqBfpKnPC*xWhPIEo2iPEpo2kPVrpWjo1DxWl0JXo1GnUh1WVHWTqWW1RQ1EJ1EJc0FrVUo0Dc2iHAC02twUToURqEooWj0OT0XBoOATWRP1NqO.oWhnWPTFFoXAoXGP3t04OPXFPOVoFf1WxuWwqVG1W.qWzqWYc1pr8ocMbn8*p5JT07HTKJTi0JfT3XPHypPbrIAvDx0SUtHQpHQoSx0PbpDzP9.vXktDtsAdHWyHXvyWX0VjcD6q3Oc04cX*01Lc0ecY204OHX5oBfT9vJ9vTX714bq1DoXpP2QPWkP0tP9QnXI0XBpPbsBfoWsPYFoWv1EJrWG0VlT3ttVkcY0oVkoYUcWRHX5pUCHU9TWfqYBPXAuXD0PN0XN01OnYHoYC02vPXMxDtwXQq1GrYP.JeqVUpTlcYTcY3oYV00bHYXTUSEBvqWMTOVpXiPXPTPLtO.qXmnYdoYirXGTZ1PY.nV*rYPzFZwEIc8scYtcY3vXa13XEFZETO1YA00VP7DP1ZtYK0TSP0hsZOrZ3P3tPZMpMaoTQPZQPXFnZ91X000Iq3dqVUu0FcZE0Y108zpP6T0NEUooX80Sa00Nn0awXBrHQT2QnZooZZq1Gc7anNDS1rnMvsZd00RcZfoVkuZGqNUp0D1ZKoY6PZnTBfwAVna5s0JP4OoZt01OcZvPG1.RqP2Qc1Nx09HX5u4.1ZKpWQ01LqaNwJfq1tqZu008nDtyXBsX20Wa0YuoaYcAep58uaLqYz0a60aOTZrTWRoaCqVk*HQyXBqXYrBgHaKTRoT0btah1YO1Za*akoSawYS0aZ0Zgwa10NJ09X02tn0UnVjrYP*0J.3Io18cY0cZ*cYWpabTRop5H01OuaicZvT6soZmqYqTZC0axoYuvazp0EsRoq0Er9GvP68U500rnU3*Bg819uWGT0rrZCpb80ZgvbMT01*0810hq16c0a.0Jm1ec2v0Z.0ZgoYuubc108*01r3hyVUT0UvHQt00SZx0SUsZzpbKc9FpZi1bp1bf10gcXrnNDEbwtXtcaInbo*berbrcc3PbGPaHoX30bz0Zgtboq0UqaRn0EmBsc0b0bloaxua1ccB09zPESpVUranpb*q0UT1LpHvn9snZw.NFccMpcFucP04NvauP07wawcbawcHs8apIBnEt1YgPaF0SUrYq08Ancer5enBxo4Rtci0bmcY3wck00oy8qoNPnca0cqc1ZrawocFtctTDNn0ayXBTZupYr0cFoVkvbou0Oyd00DQ0ZsTGsn11102naUnWhTZ.rcU1aDTbYEcrocFvdF0BXw6Gn4zw13s2pvBs1dMP6snavcb70cy0ayHACcEzTd8T02pZuuZe0dgoa0HYw1bkp0osdaoNXTBeoHUnIV1dMTbwTYRcdfoaxwcPTcMsbuSc5PaHudnocOHdquDZq8B00an6Gu8cnUoT08oN3m0ZyZq0aDpdCcbaodEHdi04NoWNPaFnZycc7He80DJz0Jq07*DST3Yn2kT8HT9Gn1w13iTaBEdTcbavd704zscg00Nc9QcYs0docaa13X1drT2xneZ02jneAs1kyGUT6.00gT2q1ed0cKoZeve6cZfuehoeP0cR0FZpcT0bTHeTp13yewmDR00*s1ww6t03ZT8601E1e.P8gSRmtDzccccbauf3TZrPcC0X.0d5cZfwdVp1EwfFT42nbhT1ls2Ps4Eo3IyecyXMPcptfMpebHeNressb4ocwcd*cfUHf9T2Esfco0H.1Es3Jn5hT5Ny0*yfe04zPfK.cbpcEceLceoqVkrfknd9obHc0VEfT0en0Yvpb*uG2qfX01wmAbTfaT3pr4i0d9Tezyff00gndOpf7taJp4kc18rbZ0g9oeMpgB0EwT03p1l.ftT6Lnfv02jw1EyfyoH7yZqwcxoe0HdiTKaTagmbjuf10dgufVTBangbTgYTgs0fDT7u.07o55ygeT07.4E02ttghcfopgQT3Upe3.aG0ekugnobnHfp02P.gwo3cTgG05hygr05hu9UTgK06GyeIqbIEg8oaxvfP04zpbuEe40ekofipgVphETea0hH040ThDT7uuhB0EwyfyT8AogSodUHfjTXMoEtnaUoc6og00gTcg20GbuGZ00ouhbp1w.gZ0gbs8o0hwT8kThypbspKST2qyhdo07mcLvh7cY3uhOohjPfRqam0f8phUT8Hshxp8rpiE0hwuK*01rThZ05hsVUz0ksiHyi10d2tfMvi40Zgui6TEpydAwh00dgwgp0iKc0In2QTG2.huTiCcebcib0hcThIT1NPfgPX3phT1aD0eOTXMpfl0eZtiWoYuwiYT5NsVkx09cigphtTiJTivcif0S8phXT1l14doHytbv.f*0aXcg10ASpgQ0io0hPng5PBecg7cemohNHh9Ti*0csciyThC0gu0hvcia0j1Ti0TiioHyyHQqi9tgP1dRt03Eef0g9viu02ycjQsiH.id05hvhPTjS0fIygw0dNPchcfn0iXHgj0TOTipncKpdm0cNcf2HjJ04BojfTi.02jc2K*ixq3dpj200*1j40Bxnfm0hMcczHgj*04mh4neRuiRodppiB05hck0nVUqk2TjNT0HshFcY3*ix0Y1TJWT1lyiOTddPjFpeK0hn0gA1inresoesmhQ.h5saWxjXq0O1eq0kH0Zg*kPobs0JeTgtTkMThWckOnYVT98TfHTj3y0EyNWcZD0jbHhh04zokbnhkPcD0j80kXtjcT3SckqcY2Tks0iI0jOT8Hcl60Zgp8dTgKTByof00jv0goHkzokaTkBnl00f6cXZHjxTl50kjnYupfG0lA0kioajnlTT3SyfeT1ZPf.0d3vkEcb.1kZThiTXMmejT4OcjooitHlQ01wclCoWZT3lTj.TlRolXcY3plE0jkTlb0J7.j7xkfc9.olL0dy.b5T0rcllck9pkGT5Nclpchq.jgTm80lSclvTlZTlFpj5SfLPil0l2od6HlKTlh0dy0f5TdBTbJcj9vl40lo0mD0lDTlr0gumkkcZvcl7q0kqlapjUngNclPph2tjZckxojIpm70j*0mVolq0iz06UT7uoYu*mZTS7Tj3ucS0jm0fScjHcm61dR0jr0k.TlMTdl0aDule0Zh1epuhqT0Hcm90gW0l9T4RqmZ0aTcmE06*0WK00a1bkqhx.g.ob60k80dhph2o0kzcankD0lIoh8pmlTltcma0mW0mpT4R0HRT2qcm9T1m0SR0k4umwTkU0EzcjG0dDcDNHmM0n104zzc4.kdceSpnW0mUolu0kQo0ku56005.msnkrxg.TN3u0OzkwpmSHnoom1zlNsaWrnOoYutcH02D.n*cl7xo104zt3gooE0nZT5ET0Hunh00Vqi2olHpcdHo6TmNzlNqjWnoCvoIcnAp2jrZoTnbT1mcnemoGuoNpUoPlctiQ0nUci5HoS0npzlNTlk0oAcb91epq0OonE*mtmg.w510OYT1lcnezg.1eqqj5EmI0Wapimqg3TmNoeszcv0ircm50nP1or0MgTnX0nF0kQznMT0YTc20mnchqpfWTo20oO0iPPmJrop0cGHolop6TfRTmQEpQogU1pBpKkyoJomoTFhT0HyesTNVT0dopacW7T1lwnJu0OqmePcScmg1jYrhfcegHdqqQbT3PophTRmTpdTXMT0O.pv*0k1o*0mxToocmz0pAqklqm1opTmgm0oj0iSHps0GX.p.npy0Jw01EcoYThWTQJupl0k60p80pQwe1r0kwnS0bxcdrcfOHqBpGnpmmonwopb05h*FXT0Owpvu8HyWJpeE0gMPkVTmR0kXviT0npoZoPeQ0qRop30GbqG8pfSoqXcWe03yT0pTGVopv06GphG1ed.o40qjHpSTmNwo8cel0nm0jA1pYTJ8T2Eoqyoqa0BtTqw00Vwqc03gqa3y3troP0Z.vn5uqkom1woUTdP0iA1r80GXwrGT3S*rCpqWcnYoqYT5NqJF1edrmH.cbvrMHr20npwonwiscm.qkgqqrTpD*nEphF*rWT07upvsha0AP02trp0.l.nrNTr3T1rok7cq3oVkwoCpqVTrrcnesrturq0DuorBThqs5c1bkobP0pO0p20mKcbatry0rhTpU0eJTqiohgpcV0IypK7os90nBuT9TrEphrcs502Pya3urJ0mxqoVHgjtmipo5psOps30WecsWT3PyigTJp00*cqH07NT1lrWJosDPnjTq20cFwe10n0oq6TWRTn3qbycqTpsfTslTn90pJ0nBTsy0ngTJpspvz0kpsqTW4.pGtrj0q4cWenPaShRss.0g9us2Tt7coznkR0qFp0oosRT3SuIe1sCTW40qg0nkpkWosN1lg0qlTp5TPaEtHcnt1rSpJAptPcne0eATpjT1lqs7TV3ckIcFZo8Hu1EPap*r0otYqp40ta0twtr4ohmomLpt00qFTekqmaq8T0oa0H7qtm01Evtj013mt91bkTcWmi30q9okF1tZosx0nptrPpgOntK0u00Cpofvmt9T4OniLn1A0fETFh1uBsrd0ld0uEclfqtvouHoestricp9os1HpsTuQciaTcMTjjTqwq2EvpHcifT9.p1kqp*uV30nr0d3pp3cm0Ttb0uITr.0qMcs0coqqrlT8Xvun0jLTupT2Eq0koiHtKkcuo04NpgdT3S1uV0sErcrrpWcg2cuw0twoucTsKqhLcu*0bbHqBrnHr0EcvArKF.4W018nuRTuQ02j1vEPnjqsbpmhrpq0kypt0tixz0JwuP0nzT4eTDNoKFw5h1va0tVTstccjHjqqubTmNtjt0n40uY0n6qrl0nBt5eovnTJHTHyT2EwkJ0nFq4hnZmTezuusTdz0g*cuecv0cRSnVr00rStdurfpsfP3Pww5*k10vnPw20EOv15cnetoGT0H1vETss0sLEvH0kYquaTuxom1qnrneRoqppHV0HRvwR0t3TFa.vVpfAcnATFavdj0fIujtEjaomk1uGTwbTmNqty0sG0g9toCrwm0wj0EO.wlTENcneog.qecu180e*0rL0vyusIouHquJcpoqkguKlcx4nsk0owp0o.pvvwT0SPtuWtoipoRpjBrvu0twqud0qNHeTTgzcnevxMoGnzwioqt0KFtlVTo2T4gPik0sFxl*0jCoxSodj.m3ttDoufpgVT0xTdg*nETK4Tdu0espxKcodnj.1NJtxOPpPcvOoVktxBTuxqjE0tWTsMcprpxq0Bxcxy0sT0xJTx30pJTcs0nhTxg0tVqvc1ppEwscZfvdVT8Yu1DcnexoGow7cwn0EOr5qTwUqEStpm0my0suHvtTwv0xTTszcqS0tJHxW099uyQ0x0p1Er0*wlVxxbcrYcpi0mq0nJqyY0qLTd.0xVph2.0kPf.nnTpxQ1n706SuykoqtTpw0u4T3tqotnkrzo.qyuTwWqvN0r6vy30vKTrwnwe0csHyiTqeTem*mtzpG0O6TzMnYuTKPT2qwyt00VnJZcmjcyNHrgoxSPfRso9cy1chopyj0z20BXcyUpIVTkSTipTyEoz4y9DTNP00VurKpVUvwJ1wu0zG0twPi8TrQtkf0hp0zgp0acneyjjoJAx.00yF*p*q0Oux*0Wavztqwa0zvom1PpUwxocv00z.TyP0zh0.5nzl0HScziThWyZiurw0uu0zJpxRTydouHTuzTywcvOwyO0zfp.4oxcTn80DKTDZx.bcyqTBKTi013Xu.8rvGczd0r7q.BoxlTqEydA0wXc.nv.ZTzL0pvwBa14qpLFcx40LyT4pmuPuyZqyKqbstsd0r1py9T.wc.*prCT421.zTzmc.hw3p1dM0zq0q1w.F0Y4pUR0swT.UTpymq8pz0qxF0z*TzQcl7w.yyrETL0c.N0fv1*HpquTwBonNc.YHX5TC*o.q0npPy.0qRu.A0.H0.aT*U0ZgT.dTCAy*X0OZcneu7u1*bTuB0vq02DEwYvazoGno*ioesPqnthl0.S1z1T.Ip.g0pEobsu6L1*D0.M0yFot106Smv7TcXEyM0dgvazoGno*ioesPzbcr5cj9t.v1khc*AThqo2sT.fT*pobsu*wmv7TujmuDp*R0ji0.CTuxPzxpuKHzK1khc*v0741*D0.M0ylTea1*HouSqY1v*moGno*ioesP.EcwD0*L1z1T.Ip.g0pEoVkT*r02uy*tx.g0pEobssea1*HouSqY1pqpoGno*iope.xncwD0*L1z1T.Ip.g0pEobss8S1*D0.M0yFoGV05Cmv7TcMqY1p8gcj9tazoGno*iope0mP0.t0zEHzK1khc.*r5j1*D0.M0yFq*r1*HouSrY1y09f9OTXb08Orveowtq*ST.Ip.g0pEobsq.do2sT.fT*poVkT*tT*1n3tv2QoVUx09f9OTXb05io*iopem*Qcs*1z1T.Ip.g0pEoVkT*tTDHy*txyp0pEobso*tT*1n3tv2QoVUx09f9OTXb0BXo*ioesP*ktc6u*mpzfT.Ipyp0pEobso*tTDHy*tyvS0yF0ji03g1*HouSv1Bmv7TYBT*O0*j0lznzIxzzpzfT.IqvS0yF0ji0741*D0HMowMnkJT3Ip*amv7TcMv1Bmv7TYBT*O0*j0f5szc0r6t.v1eqowMnkJT3Ip5j1*D0R8o*B02P1*HouSv1Bmv7TYBT*O0*j0f5q*40*nT.wvqzT6L14dvvhnxIp*amv7TcMv1Bmv7TYBT*O0*j0mPw*Kw.v1khsuR0nIp5j1*HTOiTiwnbsv*r1*HouS12vq.Lo*iope.xncwD0*L1z1T.Ip1xcuov.do0MnN.TZgxixT9.r*amv7TcM12vq.Lo*iope0mP0.t0zEHzK1khsiwnklrox04U1*HTENq.0zDM0pC02P1*HouS12vq.LT02rveowtq*ST.Ip1xcuipr90741*HTENqSap8ip3mojlpiD0Iyr*amv7TcM12vq.LT5aT*O05Sm*Qcs*1z1TENsiD09E0kKp8ipGnr5j1*HTEGurKTGV05Cmv7TcM12vq.Lo*ioesP*ktc6u*mpzfTEGurKTGV04U1*HTkMnqaojlTHe0yVT*wmv7TcM12vq.Lo*ioesPqnthl0.S1z1TkMnguojlpIeTspT6L1*HTrrnqwojlTHe0SVT*Gmv7TcM12vq.Lo*ioesPzbcr5cj9t.vug.s3moGZz6L1*HTWRnFjojlTHe0nHT*1n3tvo2q.Lo*ioesPzxpuKHyiw0Zs3mo*r0OFT*Cm4EyuPojlTHenxMT8Ymv7TcM12vq.Lo*ioesP.EcwD0*L1z1TgM09E0kK013nxMTCAm0km8jojlpzj0u7T*1n3tvo2q.Lo*iope.xncwD0*L1z1p8jozS0u7TDHm0km8jojlp13p4Q05omv7TcM12vq.Lo*iope0mP0.t0zEHf9o3moEFp4Q0Dcm0km8jojlp*B0u7T*1n3tvo2q.LoP1qveowtqxFoos0kK0iHTT7T*Cm0VojlTEftxMT0Mn3tvo2q.LotP0.CT*Ppjup*R0hpoos0kK0vW0Dcm0VojlTC*rHC05Cmv7TcM12vq.Lo*ioesP*ktc6u*mpyjoos0kK0nc0HST0K1dlT2pojlTjQT5.mv7TcM12vq.Lo*ioesPqnthl0.S1n7oos03mzyS1dlT2pojlTpH0B31*HouS12vq.Lo*ioesPzbcr5cj9tdFoos04Vr8xT0K1dlT2pohbT8Ymv7TcM12vq.Lo*ioesPzxpuKHe8oos015o0K1dlT2poqETGV0.e099mv7TcM12vq.Lo*ioesP.EcwD0*L1n7oos0eArqv02um0Vo07t2p1*HouS12vq.Lo*iope.xncwD0*L1n7o0Ot5a1dlT5aTqETGV0eBn99mv7TcM12vq.Lo*iope0mP0.t0zEHdqynpTpH0CjmFZy2umv7TcM12vq.LopewEnczX0dgvboynpTpH0Cjm5Bope0ox0BL1*HouS12vq.Lopeo*O0vwqtIoe7pb*ynpTpH0Cjm5Bope0ox0BL1*HouS12vq.Lo*ioesP*ktc6u*mp99ynpTpH0Cjm5Bope0ox0BL1*HouS12vq.Lo*ioesPqnthl0.S1epynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*ioesPzbcr5cj9tboynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*ioesPzxpuKHdqynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*ioesP.EcwD0*L1epynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*iope.xncwD0*L1epynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*iope0mP0.t0zEHdqynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lom1T0rqveowtqkgynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lom1T5aTuxTyfu*mp99ynpT8Yq6L18vope0wgT.ym5aTcM12vq.Lo*ioesP*ktc6u*mp99ynpTpH0Ieqm1TpH01wq2tvo2q.Lo*ioesPqnthl0.S1epynpTpH0Ieq3*oymT3Sq2tvo2q.Lo*ioesPzbcr5cj9tboy2t*cM12vq.Lo*ioesPzxpuKHdqyHLr2jptp0pe0ox0Ezoquo3Wq.Lo*ioesP.EcwD0*L1epyD3vCAu5l0BXo*iope.xncwD0*L1epy9QTpH0Ieq3*oymT3Sqg*09Xq.Lo*iope0mP0.t0zEHdqy9QT2vv9pq.Lo.VqEnczX0dgvboyAVTGV0bhCbfC0Uo00C0tC0FC0DCn2oob0ox0EzobN03Tu5l0BXo.VouxTyfu*mp99m1ZpbPv2N0ji0.CTuxP*ktc6u*mp99m1Zv3ZC0DC0eC8gC8gC04C0FC0FC2FTm3011T3Sqrv02N0ji0.CTuxPqnthl0.S1epm1ZvBxuN3y5l0BXo*ioesPzbcr5cj9tbom1ZxhtC0DC0eC0Uo00C2QC0FC1GCDyTm3011T3Sq2tq*sq.Lo*ioesPzxpuKHe8pBJu*sq.Lo*ioesP.EcwD0*L1n7pG6.00C0DC0eC8gC2QC0FC1GCDyTm3011T3Sq8O0APq.Lo*iope.xncwD0*L1n7p71udr11uoGno*iope0mP0.t0zEHe8pNV.00CbfC0Uo00C4gr00C0FCDyTm3011T3Sq5iq2N0ji0.CT1sqveowtqkgy1ZpbPu0Mr.LoxST5aT*Ppjup*R0Gbyd4T0Fq3*oymT3Sq4z102r.Lo*ioesP*ktc6u*mp99yd4T1LueGr.Lo*ioesPqnthl0.S1epy1Zvtp0pe0ox01xo0Mr.Lo*ioesPzbcr5cj9tbcuuBpcMo*ioesPzxpuKHX5va.rymTtRtngo*iogfode0yx12Kva.r8ov*O0npT.W0wC0yx12Kva.t11TtRtTXT*O0y5TpVc.uHAPu0K1YAvydT1rpveowty*yoZi0nc00aC0h.00C0DCD6C7aC4guBXy.Vo*Ppjupz0y*yoZircMoza0wH.nsuzty*yo58v2jC1GC04C0FC04C0DCBsCBsC8sC0FC04C04CXFC1Zu00C0DC1Zp00C04C5aCXFC1Zp00C04C04C04C0eC8sC0FC0FCLo*za0lznzIxjXy*yo2sT1LvydPzbcr5cj9tZGy*yo2sp1wC17C04C0tC04C04C04C2QC0eC04C0eC0FC0eC0FC8gC1GC0FC0eC0FC0FC0eC0FC0eC0FC0FC0FC0eC04C04C04CNXo0Zo.D0f5qyKy*yo2sp8ovuxP.EcwD0*L10gu0K13Ur1EC1GC0eC04C0tC04C04C04C0eC0FC0eC04C0eC0FC0eC9GC1GC0FC0eC0FC0FC0eC0FC0eC0FC0FC0FC0eC04C04C04CNXr0Zope.xncwD0*L10gu0K1*HT1OvmNTsKttXcy810gu0K1*x00aCbfC0FC0DC0eC0eC0FC1NC0FC0FC04CXFC1Zu00C0DC1Zp00C0FC0FC0FC1Zp00C0FC1GC1eC0FCT7u0cxzWpse10gu0K1*xrujoi2pjupz0y*yo0MnXrCWRn00CX1TebT0DptIoe7p16u8CnbNv0Dpf7ujXy*ymPMnWao8gcj9tZGyuBocMoWax09f9OT16u0D.VUx09f9OTbd*bd*bd*bd*bd*bd*01s1O0";
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
				saveMetaArray[xy] = wrap(64*Vec_angle(p->vel)/TAU, 63);
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
