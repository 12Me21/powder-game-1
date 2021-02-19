#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "elements.h"
#include "menu.h"
#include "bg.h"
#include "part.h"
#include "draw.h"
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
	for (i=0; i<Ball_MAX; i++) {
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
		for (e=entitys; e<next; e++) {
			if (e->type == Entity_PLAYER) {
				totalPlayers++;
				oldPlayer = e;
			}
		}
		if (totalPlayers>=2 || meta2 && !ELEMENTS[meta2].playerValid)
			return;
	}
	int i;
	for (i=0; i<20; i++) {
		next->parts[i].pos = (Vector){x+Random_(4), y+Random_(4)};
		Vec_copy(&next->parts[i].oldPos, &next->parts[i].pos);
	}
	for (i=0; i<Entity_PARTS; i++)
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
	if (d) {
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
		node->pos.y = clamp(node->pos.y, 4, 311);
	} else {
		for (c=0; c<d; c++) {
			b = node->pos.y + e.y;
			if (b<4 || b>=312) {
				node->touching = Elem_EMPTY;
				break;
			}
			Part* part = Part_at[(int)b][(int)part->pos.x];
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
	for (i=0;i<Ball_MAX;i++) {
		Ball* ball = &balls[i];
		if (!ball->used)
			return;
		int type = ball->type;
		Color color = ELEMENTS[type].color;
		if (Menu_bgMode == Bg_SILUET)
			color = 0;
		int x = ball->pos.x;
		int y = ball->pos.y;
		int j;
		for (j=-1;j<=1;j++) {
			grp[y-2][x+j] = color;
			grp[y+2][x+j] = color;
			grp[y+j][x-2] = color;
			grp[y+j][x+2] = color;
		}
		if (y<308) {
			if (Menu_bgMode==Bg_DARK) {
				if (type==Elem_FIRE||type==Elem_MAGMA||type==Elem_TORCH||type==Elem_THUNDER||type==Elem_LASER||type==Elem_SPARK)
					Bg_pixels[y][x].light = 255000;
			} else if (Menu_bgMode==Bg_TG) {
				Bg_pixels[y][x].light = 2*ELEMENTS[type].temperature;
			}
		}
	}
}

void Entity_render(void) {
	Color tan = 0xFFE0AE, white=0xFFFFFF;
	if (Menu_bgMode==Bg_SILUET)
		white=tan=0;
	Entity* e;
	for (e=entitys; e<next; e++) {
		switch (e->type) {
		case Entity_FIGHTER:
		case Entity_FIGHTER+1:
		case Entity_FIGHTER+2:
			Draw_line(e->parts[0].pos.x,e->parts[0].pos.y,e->parts[1].pos.x,e->parts[1].pos.y,tan);
			Draw_line(e->parts[1].pos.x,e->parts[1].pos.y,e->parts[2].pos.x,e->parts[2].pos.y,white);
			Draw_line(e->parts[1].pos.x,e->parts[1].pos.y,e->parts[3].pos.x,e->parts[3].pos.y,white);
			Draw_line(e->parts[2].pos.x,e->parts[2].pos.y,e->parts[4].pos.x,e->parts[4].pos.y,white);
			Draw_line(e->parts[3].pos.x,e->parts[3].pos.y,e->parts[5].pos.x,e->parts[5].pos.y,white);
			
			Draw_rectangle(floor(e->parts[0].pos.x)-1,floor(e->parts[0].pos.y)-1,3,3,tan);
			break;
		case Entity_FIGHTER+3:
			Draw_line(e->parts[1].pos.x,e->parts[1].pos.y,e->parts[2].pos.x,e->parts[2].pos.y,white);
			if (e->decay>145)
				break;
			Draw_line(e->parts[3].pos.x,e->parts[3].pos.y,e->parts[5].pos.x,e->parts[5].pos.y,white);
			if (e->decay>140)
				break;
			Draw_line(e->parts[4].pos.x,e->parts[4].pos.y,e->parts[7].pos.x,e->parts[7].pos.y,white);
			if (e->decay>135)
				break;
			Draw_line(e->parts[6].pos.x,e->parts[6].pos.y,e->parts[9].pos.x,e->parts[9].pos.y,white);
			if (e->decay>130)
				break;
			Draw_line(e->parts[8].pos.x,e->parts[8].pos.y,e->parts[10].pos.x,e->parts[10].pos.y,white);
			if (e->decay>125)
				break;
			Draw_rectangle(floor(e->parts[0].pos.x)-1,floor(e->parts[0].pos.y)-1,2,2,tan);
			break;
		case Entity_BOX:
		case Entity_BOX+1:
			Draw_line(e->parts[0].pos.x,e->parts[0].pos.y,e->parts[1].pos.x,e->parts[1].pos.y,tan);
			Draw_line(e->parts[1].pos.x,e->parts[1].pos.y,e->parts[2].pos.x,e->parts[2].pos.y,tan);
			Draw_line(e->parts[2].pos.x,e->parts[2].pos.y,e->parts[3].pos.x,e->parts[3].pos.y,tan);
			Draw_line(e->parts[3].pos.x,e->parts[3].pos.y,e->parts[0].pos.x,e->parts[0].pos.y,tan);
			break;
			//draw dead box
		case Entity_BOX+2:
		case Entity_BOX+3:
			Draw_line(e->parts[0].pos.x,e->parts[0].pos.y,e->parts[1].pos.x,e->parts[1].pos.y,tan);
			if (e->decay>145)
				break;
			Draw_line(e->parts[2].pos.x,e->parts[2].pos.y,e->parts[3].pos.x,e->parts[3].pos.y,tan);
			if (e->decay>140)
				break;
			Draw_line(e->parts[4].pos.x,e->parts[4].pos.y,e->parts[5].pos.x,e->parts[5].pos.y,tan);
			if (e->decay>135)
				break;
			Draw_line(e->parts[6].pos.x,e->parts[6].pos.y,e->parts[7].pos.x,e->parts[7].pos.y,tan);
			if (e->decay>130) //lol
				break;
			break;
		case Entity_PLAYER:
		case Entity_PLAYER+2:
		case Entity_PLAYER+3:;
			int f,g,q,n;
			if (e->type != Entity_PLAYER+3) {
				Draw_vline(&e->parts[1].pos, &e->parts[2].pos, white);
				Draw_vline(&e->parts[1].pos, &e->parts[3].pos, white);
				Draw_vline(&e->parts[2].pos, &e->parts[4].pos, white);
				Draw_vline(&e->parts[3].pos, &e->parts[5].pos, white);
				f=-2;
				g=2;
				q=-1;
				n=3;
			} else {
				Draw_vline(&e->parts[3].pos, &e->parts[5].pos, white);
				if (e->decay>140)
					break;
				Draw_vline(&e->parts[4].pos, &e->parts[7].pos, white);
				if (e->decay>135)
					break;
				Draw_vline(&e->parts[6].pos, &e->parts[9].pos, white);
				if (e->decay>130)
					break;
				Draw_vline(&e->parts[8].pos, &e->parts[10].pos, white);
				if (e->decay>125)
					break;
				f=-1;
				g=1;
				q=-1;
				n=1;
			}
			Color headcolor = ELEMENTS[e->meta2].color ?: tan;
			if (Menu_bgMode==Bg_SILUET)
				headcolor = 0x000000;
			int r,w,y,z;
			
			for (r=q;r<=n;r++) {
				for (w=f;w<=g;w++) {
					if (f+1>w || w>g-1 || q+1>r || r>n-1) {
						y = e->parts[0].pos.x+w;
						z = e->parts[0].pos.y+r;
						if (
							!(
								y<8||y>=408||z<8||z>=308||
								(e->meta1==1&&w==f&&r==q)||
								(e->meta1==1&&w==g&&r==q)||
								(e->meta1==1&&w==f&&r==n)||
								(e->meta1==1&&w==g&&r==n)
							  )) {
							Color* dest = &grp[z][y];
							if (*dest == headcolor)
								*dest=0;
							else
								*dest=headcolor;
						}
					}
				}
			}
			if(Menu_bgMode==Bg_DARK){
				f=clamp(e->parts[0].pos.x,8,407);
				q=clamp(e->parts[0].pos.y,8,304);
				for(r=q-4;r<=q+4;r+=4){
					for(w=f-4;w<=f+4;w+=4){
						Bg_pixels[r][w].light = 0x1FFFFFFF;
					}
				}
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
				for (d=0;d<6;d++) {
					Bg_pixels
						[(int)clamp(e->parts[d].pos.y,8,304)]
						[(int)clamp(e->parts[d].pos.x,8,407)].light = 3000;
				}
			}
		}
	}
	Ball_render();
}
