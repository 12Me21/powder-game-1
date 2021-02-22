#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "elements.h"
#include "menu.h"
#include "bg.h"
#include "part.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>

enum EntityType {Entity_FIGHTER=10, Entity_BOX=20, Entity_PLAYER=30, Entity_CREATE=40};

typedef struct Ball {
	Vector pos;
	Vector vel;
	bool used;
	int meta;
	int held;
	int type;
} Ball;

#define Ball_MAX 50

static Ball balls[Ball_MAX];

void Ball_create(double x, double y, int type) {
	int i;
	forRange (i, =0, <Ball_MAX, ++) {
		if (!balls[i].used) {
			balls[i] = (Ball){
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

#define Entity_MAX 50
#define Entity_PARTS 28

typedef struct EntityNode {
	Vector pos;
	Vector oldPos;
	int touching;
} EntityNode;

typedef struct Entity {
	int type;
	int meta2;
	int meta1;
	bool held;
	Vector Pe;
	int decay;
	EntityNode parts[Entity_PARTS];
} Entity;

Entity entitys[Entity_MAX];
static Entity* next = entitys;

void Entity_create(double x, double y, int type, int meta2) {
	if (next >= entitys+Entity_MAX)
		return;
	Entity* oldPlayer = NULL;
	if (type==Elem_PLAYER || type==Elem_PLAYER2) {
		Entity* e;
		int totalPlayers=0;
		forRange (e, =entitys, <next, ++) {
			if (e->type == Entity_PLAYER) {
				totalPlayers++;
				oldPlayer = e;
			}
		}
		if (totalPlayers>=2 || (meta2 && !ELEMENTS[meta2].playerValid))
			return;
	}
	int i;
	forRange (i, =0, <20, ++) {
		next->parts[i].pos = (Vector){x+Random_(4), y+Random_(4)};
		Vec_copy(&next->parts[i].oldPos, &next->parts[i].pos);
	}
	forRange (i, =0, <Entity_PARTS, ++)
		next->parts[i].touching = 0;
	next->Pe = (Vector){0,0};
	next->type = Entity_FIGHTER;
	next->decay = 0;
	next->held = 0;
	next->meta2 = meta2;
	next->meta1 = 0;
	if (type==Elem_BOX) {
		if (meta2 != 10) {
			next->type = Entity_BOX;
		} else {
			next->type = Entity_CREATE;
			next->meta2 = 0;
			next->parts[0].pos = (Vector){x,y};
			next->parts[0].oldPos = (Vector){x,y};
		}
	} else if (type==Elem_PLAYER) {
		next->type = Entity_PLAYER;
		if (oldPlayer)
			next->meta1 = 1-oldPlayer->meta1;
		//next->meta1 = q;
	} else if (type==Elem_PLAYER2) {
		next->type = Entity_PLAYER;
		if (!oldPlayer)
			next->meta1 = 0;
		else {
			Vec pos = &oldPlayer->parts[0].pos;
			int b = (int)pos->x>>2<<2;
			int c = (int)pos->y>>2<<2;
			if (x<b)
				next->meta1 = 1;
			else if (x>b)
				next->meta1 = 0;
			else if (y<c)
				next->meta1 = 1;
			else
				next->meta1 = 0;
			oldPlayer->meta1 = 1-next->meta1;
		}
	}
	next++;
}

void Entity_remove(Entity* entity) {
	Entity* last = next-1;
	*entity = *last;
	next--;
}

// update node position
void Entity_moveNode(EntityNode* node, double gravity, double slowdown) {
	Vector movement;
	Vec_sub2(&movement, &node->pos, &node->oldPos);
	node->oldPos = node->pos;
	movement.y += gravity;
	Vec_mul(&movement, slowdown);
	Vec_add(&node->pos, &movement);
}

// this appears to deal with some interaction between 2 nodes
void Entity_Se(EntityNode* node1, EntityNode* node2, double b, double c, double e) {
	Vector f;
	Vec_sub2(&f, &node2->pos, &node1->pos);
	double g = Vec_fastNormalize(&f);
	if (g) {
		b -= g;
		Vector move;
		Vec_mul2(&move, &f, b*c);
		Vec_sub(&node1->pos, &move);
		Vec_mul2(&move, &f, b*e);
		Vec_add(&node2->pos, &move);
	}
}

void Entity_Ue(EntityNode* node, double d, double b, double c) {
	Vector e;
	Vec_sub2(&e, &node->pos, &node->oldPos);
	node->pos = node->oldPos;
	if (d!=0) {
		Block* cell = &Part_blocks[(int)node->pos.y/4][(int)node->pos.x/4];
		e.x += cell->vel.x*d;
		e.y += cell->vel.y*d;
	}
	if (c==0) {
		double f = Vec_fastDist(&e)+1;
		if (f>=8) {
			Vec_mul(&e, 3.8/f);
			d = 2;
		} else if (f>=4) {
			Vec_mul(&e, 0.5);
			d = 2;
		} else {
			d = 1;
		}
	} else {
		d = floor(Vec_fastDist(&e)/3)+1;
		Vec_mul(&e, 1/d);
	}
	node->touching = 0;
	if (b==1) {
		Vec_mul(&e, d);
		Vec_add(&node->pos, &e);
		node->pos.x = clamp(node->pos.x, 4, WIDTH-5);
		node->pos.y = clamp(node->pos.y, 4, H+11);
	} else {
		forRange (c, =0, <d, ++) {
			b = node->pos.y + e.y;
			if (b<4 || b>=H+12) {
				node->touching = Elem_EMPTY;
				break;
			}
			//added
			if (node->pos.x<0 || node->pos.x>=W) {
				node->touching = Elem_EMPTY;
				break;
			}
			Part* part = Part_at[(int)b][(int)node->pos.x];
			int type = part->type;
			if (part <= Part_BGFAN) {
				node->pos.y = b;
			} else if (part <= Part_BLOCK) {
				e.x *= 0.5;
				e.y = -e.y;
				node->touching = type;
			} else {
				e.x *= ELEMENTS[type].friction;
				node->touching = type;
				if (e.y<0)
					node->pos.y = b;
				else if (ELEMENTS[type].state==State_LIQUID && type != Elem_MERCURY)
					node->pos.y = b;
				else
					e.y = -e.y;
			}
			b = node->pos.x + e.x;
			if (b<4 || b>=WIDTH-4) {
				node->touching = Elem_EMPTY;
				break;
			}
			part = Part_at[(int)part->pos.y][(int)b];
			type = part->type;
			if (part <= Part_BGFAN) {
				node->pos.x = b;
			} else if (part <= Part_BLOCK) {
				e.y *= 0.5;
				e.x = -e.x;
				node->touching = type;
			} else {
				e.y *= ELEMENTS[type].friction;
				e.x = -e.x;
				node->touching = type;
				if (ELEMENTS[type].state==State_LIQUID || type==Elem_WOOD)
					node->pos.x = b;
			}
		}
	}
}

int Entity_checkTouching(EntityNode* start, EntityNode* end) {
	int b=0;
	for (; start<end; start++) {
		int touching = start->touching;
		if (touching == Elem_EMPTY)
			return -5;
		else if (touching<0)
			b = 1;
		else if (ELEMENTS[touching].state == State_HOT)
			return 3;
		else if (touching==Elem_ACID)
			return -5;
		else if (touching)
			b = 1;
	}
	return b;
}

static void Ball_render(void) {
	int i;
	forRange (i, =0, <Ball_MAX, ++) {
		Ball* ball = &balls[i];
		if (!ball->used)
			return;
		int type = ball->type;
		Color color = ELEMENTS[type].color;
		if (Menu_bgMode == Bg_SILUET)
			color = 0;
		int x = ball->pos.x;
		int y = ball->pos.y;
		Draw_ball(x, y, color);
		if (y<H+8) {
			if (Menu_bgMode==Bg_DARK) {
				if (ELEMENTS[type].ballLight)
					Bg_pixels[y][x].light = 255000;
			} else if (Menu_bgMode==Bg_TG) {
				Bg_pixels[y][x].light = 2*ELEMENTS[type].temperature;
			}
		}
	}
}

static void line(Entity* e, int a, int b, Color c) {
	Draw_vline(&e->parts[a].pos, &e->parts[b].pos, c);
}

static void rectangle(Entity* e, int a, int w, int h, Color c) {
	Draw_rectangle(e->parts[a].pos.x, e->parts[a].pos.y, w, h, c);
}

void Entity_render(void) {
	Color tan = 0xFFE0AE, white=0xFFFFFF;
	if (Menu_bgMode==Bg_SILUET)
		white=tan=0;
	Entity* e;
	forRange (e, =entitys, <next, ++) {
		switch (e->type) {
		when(Entity_FIGHTER):
		case Entity_FIGHTER+1:
		case Entity_FIGHTER+2:
			line(e, 0, 1, tan);
			line(e, 1, 2, white);
			line(e, 1, 3, white);
			line(e, 2, 4, white);
			line(e, 3, 5, white);
			rectangle(e, 0, 3, 3, tan);
		when(Entity_FIGHTER+3):
			line(e, 1, 2, white);
			if (e->decay>145) break;
			line(e, 3, 5, white);
			if (e->decay>140) break;
			line(e, 4, 7, white);
			if (e->decay>135) break;
			line(e, 6, 9, white);
			if (e->decay>130) break;
			line(e, 8, 10, white);
			if (e->decay>125) break;
			rectangle(e, 0, 2, 2, tan);
		when(Entity_BOX):
		case Entity_BOX+1:
			line(e, 0, 1, tan);
			line(e, 1, 2, tan);
			line(e, 2, 3, tan);
			line(e, 3, 0, tan);
			//draw dead box
		when(Entity_BOX+2):
		case Entity_BOX+3:
			line(e, 0, 1, tan);
			if (e->decay>145) break;
			line(e, 2, 3, tan);
			if (e->decay>140) break;
			line(e, 4, 5, tan);
			if (e->decay>135) break;
			line(e, 6, 7, tan);
			if (e->decay>130) break; //???
		when(Entity_PLAYER):
		case Entity_PLAYER+2:
		case Entity_PLAYER+3:; //dead
			int f,g,q,n;
			if (e->type != Entity_PLAYER+3) {
				line(e, 1, 2, white);
				line(e, 1, 3, white);
				line(e, 2, 4, white);
				line(e, 3, 5, white);
				f=-2;
				g=2;
				q=-1;
				n=3;
			} else { //dead
				line(e, 3, 5, white);
				if (e->decay>140) break;
				line(e, 4, 7, white);
				if (e->decay>135) break;
				line(e, 6, 9, white);
				if (e->decay>130) break;
				line(e, 8, 10, white);
				if (e->decay>125) break;
				f=-1;
				g=1;
				q=-1;
				n=1;
			}
			Color headcolor = ELEMENTS[e->meta2].color ?: tan;
			if (Menu_bgMode==Bg_SILUET)
				headcolor = 0x000000;
			Draw_head(e->parts[0].pos.x, e->parts[0].pos.y, f, q, g, n, e->meta1==1, headcolor);
			// add light to region around player
			if (Menu_bgMode==Bg_DARK) {
				int y,x;
				f = clamp(e->parts[0].pos.x,8,407);
				q = clamp(e->parts[0].pos.y,8,304);
				forRange (y, =q-4, <=q+4, +=4)
					forRange (x, =f-4, <=f+4, +=4)
						Bg_pixels[y][x].light = 0x1FFFFFFF;
			}
			break;
		}
		// lights in TG mode
		switch(e->type){
		case Entity_FIGHTER:
		case Entity_FIGHTER+1:
		case Entity_FIGHTER+2:
		case Entity_FIGHTER+3:
		case Entity_PLAYER:
		case Entity_PLAYER+2:
		case Entity_PLAYER+3:
			if (Menu_bgMode == Bg_TG) {
				int d;
				forRange (d, =0, <6, ++)
					Bg_pixels
						[(int)clamp(e->parts[d].pos.y,8,304)]
						[(int)clamp(e->parts[d].pos.x,8,407)].light = 3000;
			}
		}
	}
	Ball_render();
}

typedef struct Player {
	int Xe; //walk animation cooldown
	int Ye; //jump  "
	int facing;
} Player;

Player players[2];

void Entity_update(void) {
	Entity* a;
	forRange (a, =entitys, <next, ++) {
		if (a->type == Entity_PLAYER) {
			bool left = a->meta1==0 ? Keys[37].pressed : Keys[65].pressed||Keys[97].pressed;
			bool right = a->meta1==0 ? Keys[39].pressed : Keys[68].pressed||Keys[100].pressed;
			bool up = a->meta1==0 ? Keys[38].pressed : Keys[87].pressed||Keys[119].pressed;
			bool down = a->meta1==0 ? Keys[40].pressed : Keys[83].pressed||Keys[115].pressed;
			Player* player = &players[a->meta1 != 0];
			a->decay++;
			bool w = Part_at[(int)a->parts[4].pos.y+1][(int)a->parts[4].pos.x]>Part_BGFAN || Part_at[(int)a->parts[4].pos.y][(int)a->parts[4].pos.x]>Part_BGFAN;
			bool rightFoot = Part_at[(int)a->parts[5].pos.y+1][(int)a->parts[5].pos.x]>Part_BGFAN || Part_at[(int)a->parts[5].pos.y][(int)a->parts[5].pos.x]>Part_BGFAN;
			if (down && a->meta2 == Elem_BIRD) {
				int b;
				for (b=0;b<6;b++)
					Entity_moveNode(&a->parts[b], 0.01, 0.997);
			} else {
				Entity_moveNode(&a->parts[0], -0.2, 0.995);
				Entity_moveNode(&a->parts[1], -0.1, 0.995);
				Entity_moveNode(&a->parts[2], 0, 0.995);
				Entity_moveNode(&a->parts[3], 0, 0.995);
				Entity_moveNode(&a->parts[4], 0.3, 0.995);
				Entity_moveNode(&a->parts[5], 0.3, 0.995);
			}
			Vec_add(&a->parts[0].pos, &a->Pe);
			Vec_mul(&a->Pe, 0.5);
			if (a->Pe.x!=0)
				a->type = Entity_PLAYER+2;
			if (player->Xe>0)
				player->Xe--;
			if (player->Xe!=0 || w!=1 || rightFoot!=1) {
				if (right) {
					if (a->parts[1].pos.x - a->parts[1].oldPos.x < 0)
						a->parts[1].pos.x += 0.1;
					player->facing = 1;
				} else if (left) {
					if (a->parts[1].pos.x - a->parts[1].oldPos.x > 0)
						a->parts[1].pos.x -= 0.1;
					player->facing = 0;
				}
			} else {
				double b = 0.8;
				if (right) {
					player->Xe = 15;
					if (a->parts[4].pos.x < a->parts[5].pos.x) {
						a->parts[2].pos.x += 4*b;
						a->parts[2].pos.y -= 3*b;
					} else {
						a->parts[3].pos.x += 4*b;
						a->parts[3].pos.y -= 3*b;
					}
					player->facing = 1;
				} else if (left) {
					player->Xe = 15;
					if (a->parts[4].pos.x > a->parts[5].pos.x) {
						a->parts[2].pos.x -= 4*b;
						a->parts[2].pos.y -= 3*b;
					} else {
						a->parts[3].pos.x -= 4*b;
						a->parts[3].pos.y -= 3*b;
					}
					player->facing = 0;
				}
			}
			if (player->Ye>1)
				player->Ye--;
			if (player->Ye>0 && (w==1||rightFoot==1))
				player->Ye--;
			if (player->Ye==0 && up) {
				player->Ye=50;
				a->parts[4].pos.y -= 6;
				a->parts[5].pos.y -= 6;
			}
			double b=0.5;
			Entity_Se(&a->parts[0], &a->parts[1], 4, b, b);
			Entity_Se(&a->parts[1], &a->parts[2], 4, b, b);
			Entity_Se(&a->parts[1], &a->parts[3], 4, b, b);
			Entity_Se(&a->parts[2], &a->parts[4], 5, b, b);
			Entity_Se(&a->parts[3], &a->parts[5], 5, b, b);
			Entity_Se(&a->parts[2], &a->parts[3], 5, 0.1, 0.1);
			int i;
			for (i=0;i<4;i++)
				Entity_Ue(&a->parts[i], 0.1, 1, a->held>0 ? 1 : 0);
			for (;i<6;i++)
				Entity_Ue(&a->parts[i], 0.1, 0, a->held>0 ? 1 : 0);
			int x,y;
			for (y=0;y<3;y++) {
				for (x=-1;x<2;x++) {
					Part* p = Part_at[(int)a->parts[0].oldPos.y+y][(int)a->parts[0].oldPos.x+x];
					if (p == Part_BGFAN)
						a->meta2 = Elem_FAN;
					else if (p >= Part_0 && ELEMENTS[p->type].playerValid==1)
						a->meta2 = p->type;
				}
			}
			if (!(up && (left||right)) && down && a->meta2) {
				int w = a->parts[0].pos.x;
				int b = a->parts[0].pos.y+1;
				// nitro fly
				if (a->meta2 == Elem_NITRO) {
					w += player->facing ? -8 : 8;
					b += 12;
				}
				w=clamp(w,8,W+8-1);
				b=clamp(b,8,H+8-1);
				// fan blow air
				if (a->meta2 == Elem_FAN) {
					Block* cell = &Part_blocks[b>>2][w>>2];
					if (cell->block == 0)
						cell->vel.x += player->facing ? 1 : -1;
					//spit
				} else if (a->meta2 != Elem_BIRD && Part_at[b][w] == Part_EMPTY) {
					Part* f = Part_create(w, b, a->meta2);
					if (f>=Part_0) {
						if (player->facing==0)
							f->vel.x -= 20;
						if (player->facing==1)
							f->vel.x += 20;
						f->vel.y += Random_(3)+1;
						switch (a->meta2) {
						when(Elem_FIRE):
							f->vel.x *= 3;
							f->vel.y += 18;
							f->meta = 2;
						when(Elem_SUPERBALL):
							f->vel.y = 20;
						when(Elem_STONE):
							f->vel.x *= 0.1;
							f->vel.y *= 0.1;
						when(Elem_LASER):
							f->meta = player->facing ? 1 : 5;
						}
					}
				}
			}
			// damage
			if (Entity_checkTouching(&a->parts[0], &a->parts[6])==3 || Entity_checkTouching(&a->parts[0], &a->parts[6])==-5)
				a->type = Entity_PLAYER+2;
			// edge
			if (Menu_edgeMode==1) {
				int r;
				for (r=4;r<=5;r++) {
					int w=0,b=0;
					if (a->parts[r].pos.x<8) {
						w = W+6;
						b = a->parts[r].oldPos.y;
					} else if (a->parts[r].pos.x>=W-8) {
						w = 10;
						b = a->parts[r].oldPos.y;
					}
					if (w+b!=0) {
						a->type = Entity_PLAYER;
						Part* part = Part_at[b][w];
						if (part > Part_BGFAN) {
							if (part < Part_0) {
								a->parts[r].pos = a->parts[r].oldPos;
								continue;
							} else if (ELEMENTS[part->type].state != State_LIQUID) {
								a->parts[r].pos = a->parts[r].oldPos;
								continue;
							}
						}
						Vector e;
						Vec_sub2(&e, &a->parts[r].pos, &a->parts[r].oldPos);
						Vec_fastNormalize(&e);
						int d;
						for (d=0; d<=10;d++) {
							a->parts[d].pos.x = w+e.x+Random_2(-0.1,0.1);
							a->parts[d].pos.y = b+e.y+Random_2(-0.1,0.1);
							a->parts[d].oldPos = (Vector){w,b};
						}
						break;
					}
				}
			}
		} else if (a->type == Entity_PLAYER+2) {
			void copyPos(int dest, int src) {
				a->parts[dest].pos = a->parts[src].pos;
				a->parts[dest].oldPos = a->parts[src].oldPos;
			}
			copyPos(10, 5);
			copyPos(9, 4);
			copyPos(8, 3);
			copyPos(7, 3);
			copyPos(6, 2);
			copyPos(5, 2);
			copyPos(4, 1);
			copyPos(3, 1);
			copyPos(2, 1);
			copyPos(1, 0);
			copyPos(0, 0);
			a->Pe.y -= 1;
			a->decay = 0;
			a->type = Entity_PLAYER+3;
		} else if (a->type == Entity_PLAYER+3) {
			a->decay++;
			int b;
			for (b=0;b<11;b++) {
				Entity_moveNode(&a->parts[b], 0.1, 0.999);
				Vec_add(&a->parts[b].pos, &a->Pe);
			}
			Vec_mul(&a->Pe, 0.5);
			double e = (150-a->decay)/150;
			Entity_Se(&a->parts[1],&a->parts[2],4*e,0.5,0.5);
			Entity_Se(&a->parts[3],&a->parts[5],4*e,0.5,0.5);
			Entity_Se(&a->parts[4],&a->parts[7],4*e,0.5,0.5);
			Entity_Se(&a->parts[6],&a->parts[9],5*e,0.5,0.5);
			Entity_Se(&a->parts[8],&a->parts[10],5*e,0.5,0.5);
			for (b=0;b<11;b++)
				Entity_Ue(&a->parts[b], 0.1, 0,0);
			if (a->decay>150)
				Entity_remove(a--);
		}/* else if (a->type==Entity_BOX) {
			a->decay++;
			int b;
			for (b=0;b<4;b++)
				Entity_moveNode(&a->parts[b],0.1,1);
			//Entities_drag(d,c,c+4);
			for (b=0;b<4;b++) {
				for(r=0;r<Entities.used;r++){
					if(Entities.type[r]==Entities_FIGHTER||Entities.type[r]==Entities_FIGHTER+1||Entities.type[r]==Entities_PLAYER){
						f=r*Entities.PARTS;
						g=abs(Entities.pos[f+4].x-Entities.pos[c+b].x);
						q=abs(Entities.pos[f+4].y-Entities.pos[c+b].y);
						if(g<=3&&q<=3){
							Entities.pos[c+b].x+=1*(Entities.pos[f+4].x-Entities_oldpos[f+4].x);
							Entities.pos[c+b].y+=2*(Entities.pos[f+4].y-Entities_oldpos[f+4].y);
						}
						g=abs(Entities.pos[f+5].x-Entities.pos[c+b].x);
						q=abs(Entities.pos[f+5].y-Entities.pos[c+b].y);
						if(g<=3&&q<=3){
							Entities.pos[c+b].x+=1*(Entities.pos[f+5].x-Entities_oldpos[f+5].x);
							Entities.pos[c+b].y+=2*(Entities.pos[f+5].y-Entities_oldpos[f+5].y);
						}
					}
				}
			}
			b=0.5;
			r=4*(Entities.meta2[d]+1);
			Entities_Se(c+0,c+1,r,b,b);
			Entities_Se(c+1,c+2,r,b,b);
			Entities_Se(c+2,c+3,r,b,b);
			Entities_Se(c+3,c+0,r,b,b);
			Entities_Se(c+0,c+2,1.4142135*r,b,b);
			Entities_Se(c+1,c+3,1.4142135*r,b,b);
			w=0.5;
			for(b=0;b<4;b++){
				Entities_Ue(c+b,w,0,1);
			}
			if(Entities_hurt(c,c+6)==3||Entities_hurt(c,c+6)==-5){
				Entities.type[d]=Entities_BOX+1;
			}
		}else if(Entities.type[d]==Entities_BOX+1){
			Entities.pos[c+7].copy(Entities.pos[c+0]);
			Entities_oldpos[c+7].copy(Entities_oldpos[c+0]);
			Entities.pos[c+6].copy(Entities.pos[c+3]);
			Entities_oldpos[c+6].copy(Entities_oldpos[c+3]);
			Entities.pos[c+5].copy(Entities.pos[c+3]);
			Entities_oldpos[c+5].copy(Entities_oldpos[c+3]);
			Entities.pos[c+4].copy(Entities.pos[c+2]);
			Entities_oldpos[c+4].copy(Entities_oldpos[c+2]);
			Entities.pos[c+3].copy(Entities.pos[c+2]);
			Entities_oldpos[c+3].copy(Entities_oldpos[c+2]);
			Entities.pos[c+2].copy(Entities.pos[c+1]);
			Entities_oldpos[c+2].copy(Entities_oldpos[c+1]);
			Entities.pos[c+1].copy(Entities.pos[c+1]);
			Entities_oldpos[c+1].copy(Entities_oldpos[c+1]);
			Entities.pos[c+0].copy(Entities.pos[c+0]);
			Entities_oldpos[c+0].copy(Entities_oldpos[c+0]);
			Entities.held[d]=0;
			Entities_decay[d]=0;
			Entities.type[d]= Entities_hurt(c,c+4)==-5 ? Entities_BOX+3 : Entities_BOX+2;
		}else if(Entities.type[d]==Entities_BOX+2||Entities.type[d]==Entities_BOX+3){
			Entities_decay[d]++;
			Entities_drag(d,c,c+8);
			for(b=0;b<8;b++){
				Entities_Re(c+b,0.1,0.999);
			}
			b=0.5;
			r=(150-Entities_decay[d])/150*(Entities.meta2[d]+1)*4;
			Entities_Se(c+0,c+1,r,b,b);
			Entities_Se(c+2,c+3,r,b,b);
			Entities_Se(c+4,c+5,r,b,b);
			Entities_Se(c+6,c+7,r,b,b);
			if(Entities.type[d]==Entities_BOX+2&&Parts_limits[Menu_dotLimit]-Parts_used>=1000){
				for(b=0;b<5;b+=2){
					e.sub2(Entities_oldpos[c+b+1],Entities_oldpos[c+b]);
					e.mul(random(1));
					e.add(Entities_oldpos[c+b]);
					f=floor(e.y)*WIDTH+floor(e.x);
					if(parts[f]<=Parts_BGFAN){
						Parts_create(floor(e.x),floor(e.y),4);
					}
				}
			}
			w=0.1;
			for(b=0;b<8;b++){
				Entities_Ue(c+b,w,0,0);
			}
			if(Entities_decay[d]>150){
				Entities_remove(d--);
			}
			}*/
	}
}
