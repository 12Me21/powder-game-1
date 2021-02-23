#include "ball.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"
#include "entity.h"
#include "elements.h"

Ball balls[Ball_MAX+1];
Ball* const Ball_END = &balls[Ball_MAX];

void Ball_create(double x, double y, int type) {
	Ball* ball;
	forRange (ball, =balls, <Ball_END, ++) {
		if (!ball->used) {
			*ball = (Ball){
				{x+0.5, y+0.5},
				{0,0},
				true,
				0,
				0,
				type,
			};
			break;
		}
	}
}

static const struct neighbor {
	int offset;
	Vector breakVel;
	int breakX;
	int breakY;
} neighbors[] = {
   {-WIDTH-1,  (Vector){-0.7 ,-0.7 },-1,-1,},
   {-WIDTH,    (Vector){0    ,-1   },0, -1,},
   {-WIDTH+1,  (Vector){0.7  ,-0.7 },1, -1,},
   {-1,        (Vector){-1   ,0    },-1,0,	},
   {0,         (Vector){0    ,0    },0, 0,	},
   {1,         (Vector){1    ,0    },1, 0,	},
   {WIDTH-1,   (Vector){-0.7 ,0.7  },-1,1,	},
   {WIDTH,     (Vector){0    ,1    },0, 1,	},
   {WIDTH+1,   (Vector){0.7  ,0.7  },1, 1,	},
   {2*-WIDTH-1,(Vector){-0.44,-0.89},-1,-2,},
   {2*-WIDTH,  (Vector){0    ,-1   },0, -2,},
   {2*-WIDTH+1,(Vector){0.44 ,-0.89},1, -2,},
   {2*WIDTH-1, (Vector){-0.44,0.89 },-1,2,	},
   {2*WIDTH,   (Vector){0    ,1    },0, 2,	},
   {2*WIDTH+1, (Vector){0.44 ,0.89 },1, 2,	},
   {-2-WIDTH,  (Vector){-0.89,-0.44},-2,-1,},
   {-2,        (Vector){-1   ,0    },-2,0,	},
   {-2+WIDTH,  (Vector){-0.89,0.44 },-2,1,	},
   {2-WIDTH,   (Vector){0.89 ,-0.44},2, -1,},
   {2,         (Vector){1    ,0    },2, 0,	},
   {2+WIDTH,   (Vector){0.89 ,0.44 },2, 1,	},
   {3*-WIDTH-1,(Vector){-0.31,-0.94},-1,-3,},
   {3*-WIDTH,  (Vector){0    ,-1   },0, -3,},
   {3*-WIDTH+1,(Vector){0.31 ,-0.94},1, -3,},
   {3*WIDTH-1, (Vector){-0.31,0.94 },-1,3,	},
   {3*WIDTH,   (Vector){0    ,1    },0, 3,	},
   {3*WIDTH+1, (Vector){0.31 ,0.94 },1, 3,	},
   {-3-WIDTH,  (Vector){-0.94,-0.31},-3,-1,},
   {-3,        (Vector){-1   ,0    },-3,0,	},
   {-3+WIDTH,  (Vector){-0.94,0.31 },-3,1,	},
   {3-WIDTH,   (Vector){0.94 ,-0.31},3, -1,},
   {3,         (Vector){1    ,0    },3, 0,	},
   {3+WIDTH,   (Vector){0.94 ,0.31 },3, 1,	},
   {-2-2*WIDTH,(Vector){-0.7 ,-0.7 },-2,-2,},
   {2-2*WIDTH, (Vector){0.7  ,-0.7 },2, -2,},
   {-2+2*WIDTH,(Vector){-0.7 ,0.7  },-2,2,	},
   {2+2*WIDTH, (Vector){0.7  ,0.7  },2, 2,	},
};

static bool Ball_react(Ball* ball, Part* part, int* newType) {
	return 0;
	switch (ball->type) {
#define UPDATE_BALL_PART 1
#include "elements/All.c"
#undef UPDATE_BALL_PART
	}
	/*	switch(Balls.type[ball]){
	//water ball
	case WATER:
		switch(parttype){
		//remove fire
		case FIRE:
			remove(part);
			return 1;
		//turn wood into seeed
		break;case WOOD:
			Parts_type[part]=SEED;
			Parts_meta1[part]=0;
		//frozen by ice
		break;case ICE:
			$e=ICE;
		//...and snow
		break;case SNOW:
			if(++Balls.meta[ball]>=20){
				$e=ICE;
			}
		//??
		break;case MAGMA:case THUNDER:case LASER:
			return 1;
		//remove torch
		break;case TORCH:
			remove(part);
		//rust metal
		break;case METAL:
			if(random(100)<10){
				Parts_type[part]=Parts_POWDER;
				Parts_meta1[part]=0;
			}
		//salt turns ball into saltwater
		break;case SALT:
			if(++Balls.meta[ball]>=20){
				$e=SALTWATER;
			}
			remove(part);
		//break fuse
		break;case FUSE:
			Parts_type[part]=GUNPOWDER;
			Parts_meta1[part]=0;
		}
	//ice ball
	break;case ICE:
		switch(parttype){
		case WATER:
			Parts_type[part]=ICE;
			Parts_meta1[part]=0;
		break;case FIRE:case SPARK:case LASER:case TORCH:
			if(++Balls.meta[ball]>=20){
				$e=WATER;
			}
		break;case ICE:case SNOW:
			Balls.meta[ball]=0;
		break;case MAGMA:
			$e=WATER;
		break;case THUNDER:
			return 1;
		}
	break;case SALTWATER:
		switch(parttype){
		case WATER:
			Balls.meta[ball]=0;
		//fire heat'd
		break;case FIRE:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			remove(part);
			return 1;
		//seed wood dissolved by also metal vines too
		break;case SEED:case WOOD:case METAL:case VINE:
			Parts_type[part]=Parts_POWDER //part
			Parts_meta1[part]=0; //meta
		//ice freez
		break;case ICE:
			$e=ICE;
		//snow heat?
		break;case SNOW:
			if(++Balls.meta[ball]>=20){
				$e=ICE;
			}
		//magma evaporate
		break;case MAGMA:
			$e=SALT;
		//torch heat metla
		break;case TORCH:case SPARK:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			remove(part);
		//idk
		break;case THUNDER:
			return 1;
		//salted
		break;case LASER:
			if(++Balls.meta[ball]>=20){
				$e=SALT;
			}
			return 1;
		//eating salt
		break;case SALT:
			if(Balls.meta[ball]++<20){
				remove(part);
			}
		//dissolve fuse
		break;case FUSE:
			Parts_type[part]=GUNPOWDER;
			Parts_meta1[part]=0;
		}
	//salt ball
	break;case SALT:
		switch(parttype){
		case WATER:
			$e=SALTWATER;
		break;case MAGMA:case THUNDER:
			return 1;
		}
	//fire ball
	break;case FIRE:
		//burn fire seed wood gunpowder oil c4 nitro ant vine bird fuse
		switch(parttype){
		case Parts_POWDER:case SEED:case WOOD:case GUNPOWDER:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE;
			Parts_meta1[part]=0;
		//melt ice and snow
		break;case ICE:case SNOW:
			Parts_type[part]=WATER;
			Parts_meta1[part]=0;
		//set off fireworks
		break;case FIREWORKS:
			if(Parts_type[part]==FIREWORKS && Parts_meta1[part]>0 && Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//seed ball
	break;case SEED:
		//grow?
		switch(parttype){
		case Parts_POWDER:
			if(Balls.meta[ball]==1){
				$e=WOOD;
			}else{
				Parts_type[part]=SEED;
				Parts_meta1[part]=0;
			}
		//enter grow mode
		break;case WATER:
			Balls.meta[ball]=1;
		//turn vine to wood
		break;case VINE:
			Parts_type[part]=WOOD;
			Parts_meta1[part]=0;
		}
	//nice >:]
	break;case WOOD:
		//wood ball+seed = seed grows
		switch(parttype){
		case SEED:
			Parts_meta1[part]=1;
		//wood ball + oil makes wood ball burn longer!!! (wow)
		break;case OIL:
			Balls.meta[ball]=1;
		}
	//funpowder ball (typo unintentional but left in)
	break;case GUNPOWDER:
		//some elements increase/decrese explodeyness
		switch(parttype){
		case WATER:case SOAPY:case SALTWATER:
			if(Balls.meta[ball]<20){
				Balls.meta[ball]++;
			}
		break;case FIRE:case MAGMA:case TORCH:case THUNDER:case LASER:case SPARK:
			if(Balls.meta[ball]>0){
				Balls.meta[ball]--;
			}
		}
	//oil ball
	break;case OIL:
		switch(parttype){
		case MAGMA:case THUNDER:case LASER:
			return 1;
		//kill soaps
		break;case SOAPY:
			remove(part);
		//fuse absorb
		break;case FUSE:
			if(Parts_meta1[part]<256){
				Parts_meta1[part]=OIL;
			}
		}
	//soap ball
	break;case SOAPY:
		switch(parttype){
		//freeze
		case ICE:
			$e=ICE;
		//kill oils //kill torch //kill spark'd
		break;case OIL:case TORCH:case SPARK:
			remove(part);
		//burn
		break;case MAGMA:case THUNDER:case LASER:
			return 1;
		//absorb to fuse
		break;case FUSE:
			if(meta[part]<256){
				Parts_meta1[part]=SOAPY;
			}
		}
	//not a big fan of this... hehe
	//else if(Balls.type[a]!=FAN)
	//clone ball
	break;case CLONE:
		if(parttype==THUNDER||parttype==LASER){
			return 1;
		}
	//virus ball
	break;case VIRUS:
		if(parttype>0){
			if(Balls.meta[ball]==0){
				Balls.meta[ball]=parttype;
			}else if(Balls.meta[ball]!=0){
				Parts_type[part]=Balls.meta[ball];
				Parts_meta1[part]=0;
				Parts_pumpType[part]=0;
			}
		}
	//nitro ball
	break;case NITRO:
		if(parttype==FUSE&&Parts_meta1[part]<256){
			Parts_meta1[part]=NITRO;
		}
	//acid ball
	break;case ACID:
		//dissolve things (and clone)
		if(Parts_DISSOLVERATE[parttype]!=0||parttype==CLONE){
			remove(part);
		}
		if(parttype==THUNDER||parttype==LASER){
			return 1;
		}
	//bird ball
	break;case BIRD:
		switch(parttype){
		//eat seed/ant
		case SEED:case ANT:
			remove(part);
		//slow down near wood
		break;case WOOD:
			Balls.vel[ball].mul(0.9);
		}
	//thunder ball
	break;case THUNDER:
		//make thunders
		switch(parttype){
		case SALTWATER:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=0;
			return 0;
		break;case THUNDER:
			return 1;
		break;case METAL:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=6000;
		break;case MERCURY:
			Parts_type[part]=THUNDER;
			Parts_meta1[part]=6100;
			return 1;
		}
	//stone ball
	break;case STONE:
		switch(parttype){
		//cool
		case WATER:
			Balls.meta[ball]=0;
		//melt
		break;case MAGMA:
			if(++Balls.meta[ball]>=20){
				$e=MAGMA;
			}
		//stone + stone ball = spakrs
		break;case STONE:
			if(Parts_limits[Menu_dotLimit]-Parts_used>=1000 && Balls.vel[ball].x*Balls.vel[ball].x+Balls.vel[ball].y*Balls.vel[ball].y>10){
				var x=floor(Balls.pos[ball].x)+floor(random(5))-2;
				var y=floor(Balls.pos[ball].y)+floor(random(5))-2;
				var xy=y*WIDTH+x;
				if(parts[xy]<=Parts_BGFAN){
					Parts_create(x,y,SPARK);
				}
			}
		break;case SPARK:
			return 1;
		}
	//magma ball
	break;case MAGMA:
		switch(parttype){
		//cool into metal ball in water
		case WATER:
			if(++Balls.meta[ball]>=20){
				$e=METAL;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		//reheat
		break;case MAGMA:
			Balls.meta[ball]=0;
		//cool into glass ball with soapy
		break;case SOAPY:
			if(++Balls.meta[ball]>=20){
				$e=GLASS;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		//cool into stone ball with saltwater
		break;case SALTWATER:
			if(++Balls.meta[ball]>=20){
				$e=STONE;
			}
			Parts_type[part]=STEAM;
			Parts_meta1[part]=0;
		break;case Parts_POWDER:case SEED:case WOOD:case GUNPOWDER:case SUPERBALL:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE
			Parts_meta1[part]=0
		break;case ICE:case SNOW:
			Parts_type[part]=WATER
			Parts_meta1[part]=0
		break;case FIREWORKS:
			if(Parts_type[part]==FIREWORKS&&Parts_meta1[part]>0&&Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//metal ball
	break;case METAL:
		switch(parttype){
		//water cools metal ball
		case WATER:
			Balls.meta[ball]=0;
		//lava melts metal ball
		break;case MAGMA:
			Balls.meta[ball]++
			if(Balls.meta[ball]>=20){
				$e=MAGMA
			}
		//fast ball+metal = sparks
		break;case METAL:
			if(Parts_limits[Menu_dotLimit]-Parts_used>=1000 && Balls.vel[ball].x*Balls.vel[ball].x+Balls.vel[ball].y*Balls.vel[ball].y>10){
				var x=floor(Balls.pos[ball].x)+floor(random(5))-2;
				var y=floor(Balls.pos[ball].y)+floor(random(5))-2;
				var xy=y*WIDTH+x;
				if(parts[xy]<=Parts_BGFAN){
					Parts_create(x,y,SPARK);
				}
			}
		break;case THUNDER:case LASER:case SPARK:
			return 1;
		}
	//water balls
	break;case GLASS:
		switch(parttype){
		//water cool ball
		case WATER:
			Balls.meta[ball]=0;
		//magma heat ball
		break;case MAGMA:
			if(++Balls.meta[ball]>=20){
				$e=MAGMA;
			}
		//thunder laser fix ball in place
		break;case THUNDER:case LASER:
			return 1;
		}
	//torch ball
	break;case TORCH:
		switch(parttype){
		//burn powder, seed, gunpowder, superball, oil, c4, nitro, ant, gas, vine, bird, fuse
		case Parts_POWDER:case SEED:case GUNPOWDER:case SUPERBALL:case OIL:case C4:case NITRO:case ANT:case GAS:case VINE:case BIRD:case FUSE:
			Parts_type[part]=FIRE;
			Parts_meta1[part]=0;
		//melt ice snow cloud
		break;case ICE:case SNOW:case CLOUD:
			Parts_type[part]=WATER;
			Parts_meta1[part]=0;
		//set off fireworks
		break;case FIREWORKS:
			//make damn sure those are fireworks, really
			if(Parts_type[part]==FIREWORKS && Parts_meta1[part]>0 && Parts_meta1[part]<100){
				Parts_vel[part].y-=50;
				Parts_meta1[part]+=100;
			}
		}
	//fuse bal
	break;case FUSE:
		//soak oilnitrosoapy
		if(parttype==OIL||parttype==NITRO||parttype==SOAPY){
			Balls.meta[ball]=parttype;
		}
	//could
	break;case CLOUD:
		switch(parttype){
		//rain
		case WOOD:case C4:case FUSE:case VINE:case TORCH:
			$e=WATER;
		//snow
		break;case ICE:
			$e=ICE;
		//lightning
		break;case METAL:
			$e=THUNDER;
		//ded?
		break;case THUNDER:case LASER:
			return 1;
		}
	//pump;
	break;case PUMP:
		//set
		if(Balls.meta[ball]==0){
			if(parttype==WATER||parttype==OIL||parttype==MAGMA||parttype==NITRO||parttype==GAS||parttype==SOAPY||parttype==ACID||parttype==SALTWATER||parttype==MERCURY||parttype==CLOUD){
				Balls.meta[ball]=parttype;
			}p
		//absorbd
		}else{
p			var storing=Balls.meta[ball]&0xFF;
			var amount=Balls.meta[ball]>>8;
			if(parttype==storing){
				Balls.meta[ball]=amount+1<<8|storing;
				remove(part);
			}
		}
		//kil?
		if(parttype==MAGMA||parttype==THUNDER||parttype==LASER){
			return 1;
		}
	}
	return states[parttype]==State_LIQUID&&states[Balls.type[ball]]==State_LIQUID&&Balls.type[ball]!=parttype || states[parttype]==State_LIQUID&&states[Balls.type[ball]]!=State_LIQUID || states[parttype]==State_GAS&&states[Balls.type[ball]]!=State_GAS || parttype==FIRE?1:0;*/
}

static void Ball_break(Ball* ball, int mode, int createType, int meta, double vx, double vy, double speed) {
	Part** pc = &Part_at[(int)ball->pos.y][(int)ball->pos.x];
	int i;
	if (mode==0) {
		for (i=9;i<21;i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					floor(ball->pos.x)+neighbors[i].breakX,
					floor(ball->pos.y)+neighbors[i].breakY,
					createType
				);
				if (near) {
					near->vel.x += vx+neighbors[i].breakVel.x*speed;
					near->vel.y += vx+neighbors[i].breakVel.y*speed;
					near->meta = meta;
				}
			}
		}
		ball->used = false;
	} else if (mode==1||mode==2) {
		for (i=mode==1?9:0; i<21; i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					floor(ball->pos.x)+neighbors[i].breakX,
					floor(ball->pos.y)+neighbors[i].breakY,
					createType
				);
				if (near) {
					near->vel.x += vx+neighbors[i].breakVel.x*speed;
					near->vel.y += vx+neighbors[i].breakVel.y*speed;
					near->meta = meta;
				}
			} else if (near>=Part_0) {
				near->type = createType;
				near->meta = 0;
				near->pumpType = 0;
			}
		}
		ball->used = false;
	}
}

void Ball_update(void) {
	//	var d,b,c=new Vector;
	Ball* i;
	forRange (i, =balls, <Ball_END, ++) {
		if (!i->used) continue;
		// remove invalid balls
		if (!ELEMENTS[i->type].ballValid) {
			i->used = false;
			continue;
		}
		Part** p = &Part_at[(int)i->pos.y][(int)i->pos.x];
		int d;
		for (d=0;d<21;d++)
			if (p[neighbors[d].offset] == Part_BALL)
				p[neighbors[d].offset] = Part_EMPTY;
		double weight = ELEMENTS[i->type].ballWeight;
		i->vel.y += weight;

		double adv = ELEMENTS[i->type].ballAdvection;
		if (adv) {
			Block* cell = &Part_blocks[(int)i->pos.y>>2][(int)i->pos.x>>2];
			i->vel.x += cell->vel.x*d;
			i->vel.y += cell->vel.y*d;
			if (Vec_fastDist(&cell->vel)>0.3)
				Vec_mul(&i->vel, 0.9+(1-d)/10);
		}
		// dragging
		if (!i->held) {
			if (Menu_leftSelection==Menu_DRAG&&Mouse_rising.left||Menu_rightSelection==Menu_DRAG&&Mouse_rising.right) {
				if (Vec_fastDist(&(Vector){Pen_x-i->pos.x, Pen_y-i->pos.y})<20)
					i->held = true;
			}
		} else {
			if (Menu_leftSelection==Menu_DRAG&&Mouse_old.left||Menu_rightSelection==Menu_DRAG&&Mouse_old.right) {
				i->vel.x += 0.05*(Pen_x-i->pos.x);
				i->vel.y += 0.05*(Pen_y-i->pos.y);
				Vec_mul(&i->vel, 0.9);
			} else {
				Vec_mul(&i->vel, 0.3);
				i->held = false;
			}
		}
		// kicked by player/fighter
		Entity* en;
		forRange (en, =entitys, <Entity_next, ++) {
			if (en->type==Entity_FIGHTER||en->type==Entity_FIGHTER+1||en->type==Entity_PLAYER) {
				int f;
				for (f=4; f<=5; f++) {
					double dx = abs(en->parts[f].pos.x - i->pos.x);
					double dy = abs(en->parts[f].pos.y - i->pos.y);
					if (dx<=9 && dy<=9) {
						i->vel.x += 0.1*(en->parts[f].pos.x - en->parts[f].oldPos.x);
						i->vel.y += 0.2*(en->parts[f].pos.y - en->parts[f].oldPos.y);
					}
				}
			}
		}
		int touched = 0;
		int newType = 0;
		// chcek movement
		int q = (int)(Vec_dist(&i->vel)/2)+1;
		double n = 1/q;
		int v,g;
		for (v=g=0; v<q; v++) {
			double nextx = i->pos.x+i->vel.x*n;
			double nexty = i->pos.y+i->vel.y*n;
			// way offscreen
			if (nextx<4 || nextx>=WIDTH-4 || nexty<4 || nexty>=H+12) {
				i->used = false;
				break;
			}
			// edge loop
			if (Menu_edgeMode==1) {
				if (nextx<8) {
					if (Part_at[(int)nexty][(int)nextx+W]<=Part_BGFAN) {
						i->pos.x += W;
						i->vel.x *= 0.8;
					} else
						i->vel.x *= -0.8;
					nextx = i->pos.x+i->vel.x*n;
				} else if (nextx>=W+8) {
					if (Part_at[(int)nexty][(int)nextx-W]<=Part_BGFAN) {
						i->pos.x -= W;
						i->vel.x *= 0.8;
					} else
						i->vel.x *= -0.8;
					nextx = i->pos.x+i->vel.x*n;
				}
				if (nexty<8) {
					if (Part_at[(int)nexty+H][(int)nextx]<=Part_BGFAN) {
						i->pos.y += H;
						i->vel.y *= 0.8;
					} else
						i->vel.y *= -0.8;
					nexty = i->pos.y+i->vel.y*n;
				} else if (nexty>=H+8) {
					if (Part_at[(int)nexty-H][(int)nextx]<=Part_BGFAN) {
						i->pos.y -= H;
						i->vel.y *= 0.8;
					} else
						i->vel.y *= -0.8;
					nexty = i->pos.y+i->vel.y*n;
				}
			}
			Vector z = {0,0};
			Part** pc = &Part_at[(int)nexty][(int)nextx];
			int d;
			int y=0;
			for (d=0;d<37;d++) {
				Part* near = pc[neighbors[d].offset];
				if (near<=Part_BGFAN) continue;
				// here we set a var named g but idk where it's used yet..
				if (near>=Part_0) {
					touched = near->type;
					if (Ball_react(i, near, &newType))
						continue;
				} else {
					touched = near-Part_0;
				}
				Vec_sub(&z, &neighbors[d].breakVel);
				y++;
			}
			if (y==0) {
				i->pos.x = nextx;
				i->pos.x = nexty;
			} else {
				Vec_normalize(&z);
				i->vel.y -= weight;
				double d = 0.999*Vec_dist(&i->vel);
				Vec_mul(&z, -(z.x*i->vel.x + z.y*i->vel.y));
				Vec_add(&i->vel, &z);
				Vec_mul(&i->vel, 0.999);
				Vec_mul(&z, 0.1);
				Vec_add(&i->vel, &z);
				Vec_normalize(&i->vel);
				Vec_mul(&i->vel, d);
				i->pos.x += i->vel.x*n;
				i->pos.y += i->vel.y*n;
				i->vel.y += weight;
			}
			pc = &Part_at[(int)i->pos.y][(int)i->pos.x];
			z = (Vector){0,0};
			y=0;
			for (d=0;d<21;d++) {
				Part* near = pc[neighbors[d].offset];
				if (near<Part_BGFAN) continue;
				if (near>=Part_0) {
					int btype = i->type;
					int ptype = near->type;
					if (
						(ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state==State_LIQUID && btype!=ptype) ||
						(ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state!=State_LIQUID) ||
						(ELEMENTS[ptype].state==State_GAS && ELEMENTS[btype].state!=State_GAS) ||
						(ptype==Elem_LASER && ELEMENTS[btype].state==State_LIQUID) ||
						(ptype==Elem_FIRE) ||
						(ptype==Elem_FIRE && btype==Elem_THUNDER)
					)
						continue;
				}
				Vec_sub(&z, &neighbors[d].breakVel);
				y++;
			}
			if (y) {
				Vec_normalize(&z);
				Vec_add(&i->pos, &z);
			}
		}
		if (i->pos.x<4 || i->pos.x>=WIDTH-4 || i->pos.y<4 || i->pos.y>=H+12) {
			i->used = false;
			break;
		}
		Ball* ball = i;
		switch (i->type) {
#define UPDATE_BALL 1
#include "elements/All.c"
#undef UPDATE_BALL
		}
	}
}
