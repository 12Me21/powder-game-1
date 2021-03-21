#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "common.h"
#include "vector.h"
#include "random.h"
#include "elements.h"
#include "menu.h" //todo: split this into sim properties (edge mode etc.) and others
#include "render/bg.h"
#include "sim.h"
#include "input.h"
#include "object.h"
#include "block.h"
#include "save.h"

Object entitys[Object_MAX];
Object* Object_next = entitys;

// `type` is an ELEMENT NUMBER, not an object type
void Object_create(real x, real y, Elem type, int meta) {
	if (Object_next >= entitys+Object_MAX)
		return;
	// check if player exists already
	Object* oldPlayer = NULL;
	if (type==Elem_PLAYER || type==Elem_PLAYER2) {
		int totalPlayers=0;
		Object_FOR (e) {
			if (e->type == Object_PLAYER) {
				totalPlayers++;
				oldPlayer = e;
			}
		}
		if (totalPlayers>=2 || (meta && !ELEMENTS[meta].playerValid))
			return;
	}
	// default object
	Object* obj = Object_next;
	*obj = (Object){
		.vel = {0,0},
		.type = Object_FIGHTER,
		.age = 0,
		.held = 0,
		.meta = meta,
		.isPlayer2 = false,
	};
	// reset all the parts
	for (int i=0; i<20; i++) // idk why this one goes to 20...
		obj->parts[i].oldPos =
			obj->parts[i].pos = (Point){x+Random_(4), y+Random_(4)};
	for (int i=0; i<Object_PARTS; i++)
		obj->parts[i].touching = 0;

	
	if (type==Elem_BOX) {
		if (meta != 10) {
			obj->type = Object_BOX;
		} else {
			obj->type = Object_CREATE;
			obj->meta = 0;
			obj->parts[0].pos = (Point){x,y};
			obj->parts[0].oldPos = (Point){x,y};
		}
	} else if (type==Elem_PLAYER) {
		obj->type = Object_PLAYER;
		if (oldPlayer)
			obj->isPlayer2 = !oldPlayer->isPlayer2;
	} else if (type==Elem_PLAYER2) { // this is used during loading, I think?
		obj->type = Object_PLAYER;
		if (!oldPlayer)
			obj->isPlayer2 = false;
		else {
			Point pos = oldPlayer->parts[0].pos;
			int px = (int)pos.x & ~3;
			int py = (int)pos.y & ~3;
			if (x<px)
				obj->isPlayer2 = true;
			else if (x>px)
				obj->isPlayer2 = false;
			else if (y<py)
				obj->isPlayer2 = true;
			else
				obj->isPlayer2 = false;
			oldPlayer->isPlayer2 = !obj->isPlayer2;
		}
	}
	Object_next++;
}

void fighterWalk(Object* a) {
	ObjectNode* left = &a->parts[4];
	ObjectNode* right = &a->parts[5];
	if (left->touching && right->touching) {
		int r = Random_int(100);
		if (r<5) {
			if (left->pos.x < right->pos.x)
				left->pos.xy += (Point){4,-4}.xy;
			else
				right->pos.xy += (Point){4,-4}.xy;
		} else if (r<10) {
			if (left->pos.x > right->pos.x)
				left->pos.xy += (Point){-4,-4}.xy;
			else
				right->pos.xy += (Point){-4,-4}.xy;
		}
	} else {
		if (left->touching) {
			if (Rnd_perchance(2))
				left->pos.xy += (Point){Random_2(-4,4), -4}.xy;
		} else if (right->touching) {
			if (Rnd_perchance(2))
				right->pos.xy += (Point){Random_2(-4,4), -4}.xy;
		}
	}
}

void fighterKick(Object* a) {
	Object_FOR (r) {
		if (r==a) continue;
		if (r->type==Object_FIGHTER || r->type==Object_FIGHTER_JUMPING || r->type==Object_PLAYER) {
			for (int i=4; i<=5; i++) {
				ObjectNode* foot = &a->parts[i];
				real dx = abs(foot->pos.x - r->parts[0].pos.x);
				real dy = foot->pos.y - r->parts[0].pos.y;
				if (dx<=2 && dy>=0 && dy<=6) {
					r->vel.xy += Cxy(foot->pos.x-foot->oldPos.x, 2*(foot->pos.y-foot->oldPos.y));
					if (r->type==Object_FIGHTER)
						r->type = Object_FIGHTER_JUMPING;
					r->age = 0;
				}
			}
		}
	}
}

void checkDrag(Object* e, int last) {
	// try to start grab
	if (!e->held) {
		if (Menu_dragStart) {
			// find the closest node (within 20 units)
			real closest=20;
			for (int i=0; i<last; i++) {
				Point diff = Vec_sub2(Menu_pen, e->parts[i].oldPos);
				real dist = Vec_fastDist(diff);
				if (dist<closest) {
					closest = dist;
					e->held = i+1;
				}
			}
		}
	// being held
	} else if (Menu_dragging) {
		Point* p = &e->parts[e->held-1].pos;
		p->x += 0.2*(Pen_x-p->x);
		p->y += 0.2*(Pen_y-p->y);
	// release
	} else
		e->held = 0;
}

void Object_remove(Object* entity) {
	Object* last = Object_next-1;
	*entity = *last;
	Object_next--;
}

// update node position
static void moveNode(ObjectNode* node, real gravity, real slowdown) {
	Point vel = Point(node->pos.xy - node->oldPos.xy);
	vel.y += gravity;
	
	node->oldPos = node->pos;
	node->pos.xy += (vel.xy * slowdown);
}

// try to make the nodes be a certain distance apart
// mul1 and mul2 control how much each node is pulled
// currently they are always = but perhaps you could
// use them to simulate a kind of "weight"
void pullNodes(Object* e, int n1, int n2, real length, real mul1, real mul2) {
	ObjectNode* node1 = &e->parts[n1];
	ObjectNode* node2 = &e->parts[n2];
	Point offset = Point(node2->pos.xy - node1->pos.xy);
	real dist = Vec_fastNormalize(&offset);
	if (dist) {
		length -= dist;
		node1->pos.xy -= offset.xy * (length*mul1);
		node2->pos.xy += offset.xy * (length*mul2);
	}
}

// adv: how much the node is affected by wind
// noCollide: whether to not check collisions
// fancy: whether to do a full simulation
//        if false, will limit velocity and only do 1 or 2 steps.
static void updateNode(ObjectNode* node, real adv, bool noCollide, bool fancy) {
	Point vel = Vec_sub2(node->pos, node->oldPos);
	node->pos = node->oldPos;
	if (adv!=0) {
		Block* cell = Block_at(node->pos.x,node->pos.y);
		vel.xy += cell->vel.xy*adv;
	}
	int steps;
	if (!fancy) {
		real f = Vec_fastDist(vel)+1;
		if (f>=8) {
			vel.xy *= 3.8/f;
			steps = 2;
		} else if (f>=4) {
			vel.xy *= 0.5;
			steps = 2;
		} else
			steps = 1;
	} else {
		steps = (int)(Vec_fastDist(vel)/3)+1;
		vel.xy *= 1.0/steps;
	}
	node->touching = 0;
	if (noCollide) {
		vel.xy *= steps;
		node->pos.xy += vel.xy;
		node->pos.x = clamp(node->pos.x, 4, WIDTH-5);
		node->pos.y = clamp(node->pos.y, 4, HEIGHT-5);
	} else {
		for (int c=0; c<steps; c++) {
			// check y-axis movement
			real newY = node->pos.y + vel.y;
			if (newY<4 || newY>=HEIGHT-4) {
				node->touching = Elem_EMPTY;
				break;
			}
			Dot* part = *Dot_pos(node->pos.x, newY);
			int type = part->type;
			if (part <= Dot_BGFAN) {
				node->pos.y = newY;
			} else if (part <= Dot_BLOCK) {
				vel.x *= 0.5;
				vel.y = -vel.y;
				node->touching = type; //hhh
			} else {
				vel.x *= ELEMENTS[type].friction;
				node->touching = type;
				if (vel.y<0)
					node->pos.y = newY;
				else if (ELEMENTS[type].state==State_LIQUID && type!=Elem_MERCURY)
					node->pos.y = newY;
				else
					vel.y = -vel.y;
			}
			// check x-axis movement
			real newX = node->pos.x + vel.x;
			if (newX<4 || newX>=WIDTH-4) {
				node->touching = Elem_EMPTY;
				break;
			}
			part = *Dot_pos(newX, node->pos.y);
			type = part->type;
			if (part <= Dot_BGFAN) {
				node->pos.x = newX;
			} else if (part <= Dot_BLOCK) {
				vel.y *= 0.5;
				vel.x = -vel.x;
				node->touching = type;
			} else {
				vel.y *= ELEMENTS[type].friction;
				vel.x = -vel.x;
				node->touching = type;
				if (ELEMENTS[type].state==State_LIQUID || type==Elem_WOOD)
					node->pos.x = newX;
			}
		}
	}
}

// I don't know whats up with these return values...
// 0: nothing
// 3: hot
//-5: acid, screen edge
// 1: other
static int checkTouching(Object* e, int start, int end) {
	int b=0;
	for (; start<end; start++) {
		int touching = e->parts[start].touching;
		if (touching == Elem_EMPTY)
			return -5;
		else if (touching<0)
			b = 1;
		else if (touching[ELEMENTS].state == State_HOT)
			return 3;
		else if (touching==Elem_ACID)
			return -5;
		else if (touching)
			b = 1;
	}
	return b;
}

typedef struct Player {
	int Xe; //walk animation cooldown
	int Ye; //jump  "
	bool facing;
} Player;

Player players[2];

void Object_update(void) {
	Object_FOR (obj) {
		void copyPos(int dest, int src) {
			obj->parts[dest].pos = obj->parts[src].pos;
			obj->parts[dest].oldPos = obj->parts[src].oldPos;
		}
		switch (obj->type) {
		case Object_PLAYER:;
			/// todo: held || gotPress perhaps?
			bool left = obj->isPlayer2==0 ? Keys[37].held : Keys[65].held||Keys[97].held;
			bool right = obj->isPlayer2==0 ? Keys[39].held : Keys[68].held||Keys[100].held;
			bool up = obj->isPlayer2==0 ? Keys[38].held : Keys[87].held||Keys[119].held;
			bool down = obj->isPlayer2==0 ? Keys[40].held : Keys[83].held||Keys[115].held;
			Player* player = &players[obj->isPlayer2];
			obj->age++;
			bool leftFoot =
				Dot_pos3(obj->parts[4].pos,0,1)>Dot_BGFAN ||
				*Dot_pos2(obj->parts[4].pos)>Dot_BGFAN;
			bool rightFoot =
				Dot_pos3(obj->parts[5].pos,0,1)>Dot_BGFAN ||
				*Dot_pos2(obj->parts[5].pos)>Dot_BGFAN;
			if (down && obj->meta == Elem_BIRD) {
				for (int b=0;b<6;b++)
					moveNode(&obj->parts[b], 0.01, 0.997);
			} else { //dubious
				moveNode(&obj->parts[0], -0.2, 0.995);
				moveNode(&obj->parts[1], -0.1, 0.995);
				moveNode(&obj->parts[2], 0, 0.995);
				moveNode(&obj->parts[3], 0, 0.995);
				moveNode(&obj->parts[4], 0.3, 0.995);
				moveNode(&obj->parts[5], 0.3, 0.995);
			}
			checkDrag(obj, 6);
			obj->parts[0].pos.xy += obj->vel.xy;
			obj->vel.xy *= 0.5;
			if (obj->vel.x!=0)
				obj->type = Object_PLAYER_DYING;
			if (player->Xe>0)
				player->Xe--;
			if (player->Xe!=0 || leftFoot!=1 || rightFoot!=1) {
				if (right) {
					if (obj->parts[1].pos.x - obj->parts[1].oldPos.x < 0)
						obj->parts[1].pos.x += 0.1;
					player->facing = 1;
				} else if (left) {
					if (obj->parts[1].pos.x - obj->parts[1].oldPos.x > 0)
						obj->parts[1].pos.x -= 0.1;
					player->facing = 0;
				}
			} else {
				real b = 0.8;
				if (right) {
					player->Xe = 15;
					if (obj->parts[4].pos.x < obj->parts[5].pos.x) {
						obj->parts[2].pos.x += 4*b;
						obj->parts[2].pos.y -= 3*b;
					} else {
						obj->parts[3].pos.x += 4*b;
						obj->parts[3].pos.y -= 3*b;
					}
					player->facing = 1;
				} else if (left) {
					player->Xe = 15;
					if (obj->parts[4].pos.x > obj->parts[5].pos.x) {
						obj->parts[2].pos.x -= 4*b;
						obj->parts[2].pos.y -= 3*b;
					} else {
						obj->parts[3].pos.x -= 4*b;
						obj->parts[3].pos.y -= 3*b;
					}
					player->facing = 0;
				}
			}
			if (player->Ye>1)
				player->Ye--;
			if (player->Ye>0 && (leftFoot==1||rightFoot==1))
				player->Ye--;
			if (player->Ye==0 && up) {
				player->Ye=50;
				obj->parts[4].pos.y -= 6;
				obj->parts[5].pos.y -= 6;
			}
			pullNodes(obj, 0, 1, 4, 0.5, 0.5);
			pullNodes(obj, 1, 2, 4, 0.5, 0.5);
			pullNodes(obj, 1, 3, 4, 0.5, 0.5);
			pullNodes(obj, 2, 4, 5, 0.5, 0.5);
			pullNodes(obj, 3, 5, 5, 0.5, 0.5);
			pullNodes(obj, 2, 3, 5, 0.1, 0.1);
			for (int i=0;i<6;i++)
				updateNode(&obj->parts[i], 0.1, (i<4), obj->held>0);
			for (int y=0;y<3;y++) {
				for (int x=-1;x<2;x++) {
					Dot* p = Dot_pos3(obj->parts[0].oldPos, x, y);
					if (p == Dot_BGFAN)
						obj->meta = Elem_FAN;
					else if (p >= Dot_0 && ELEMENTS[p->type].playerValid==1)
						obj->meta = p->type;
				}
			}
			if (!(up && (left||right)) && down && obj->meta) {
				int w = obj->parts[0].pos.x;
				int b = obj->parts[0].pos.y+1;
				// nitro fly
				if (obj->meta == Elem_NITRO) {
					w += player->facing ? -8 : 8;
					b += 12;
				}
				w=clamp(w,8,W+8-1);
				b=clamp(b,8,H+8-1);
				// fan blow air
				if (obj->meta == Elem_FAN) {
					Block* cell = Block_at(w, b);
					if (cell->block==Block_EMPTY)
						cell->vel.x += player->facing ? 1 : -1;
					//spit
				} else if (obj->meta != Elem_BIRD && Dot_at[b][w] == Dot_EMPTY) {
					Dot* f = Dot_create(w, b, obj->meta);
					if (f>=Dot_0) {
						if (player->facing==0)
							f->vel.x -= 20;
						if (player->facing==1)
							f->vel.x += 20;
						f->vel.y += Random_(3)+1;
						switch (obj->meta) {
						when(Elem_FIRE):;
							f->vel.x *= 3;
							f->vel.y += 18;
							f->charge = 2;
						when(Elem_SUPERBALL):;
							f->vel.y = 20;
						when(Elem_STONE):;
							f->vel.xy *= 0.1;
						when(Elem_LASER):;
							f->charge = player->facing ? 1 : 5;
						}
					}
				}
			}
			// damage
			int touching = checkTouching(obj,0,6);
			if (touching==3 || touching==-5)
				obj->type = Object_PLAYER_DYING;
			// edge
			if (Menu_edgeMode==1) {
				for (int r=4;r<=5;r++) {
					int w=0,b=0;
					if (obj->parts[r].pos.x<8) {
						w = W+6;
						b = obj->parts[r].oldPos.y;
					} else if (obj->parts[r].pos.x>=W-8) {//CHECK
						w = 10;
						b = obj->parts[r].oldPos.y;
					}
					if (w+b!=0) {
						obj->type = Object_PLAYER;
						Dot* part = Dot_at[b][w];
						if (part > Dot_BGFAN) {
							if (part < Dot_0) {
								obj->parts[r].pos = obj->parts[r].oldPos;
								continue;
							} else if (ELEMENTS[part->type].state != State_LIQUID) {
								obj->parts[r].pos = obj->parts[r].oldPos;
								continue;
							}
						}
						Point e = Vec_sub2(obj->parts[r].pos, obj->parts[r].oldPos);
						Vec_fastNormalize(&e);
						for (int d=0; d<=10;d++) {
							obj->parts[d].pos.x = w+e.x+Random_2(-0.1,0.1);
							obj->parts[d].pos.y = b+e.y+Random_2(-0.1,0.1);
							obj->parts[d].oldPos = (Point){w,b};
						}
						break;
					}
				}
			}
			break;
		case Object_PLAYER_DYING:
			copyPos(10, 5);copyPos(9, 4);copyPos(8, 3);copyPos(7, 3);copyPos(6, 2);copyPos(5, 2);copyPos(4, 1);copyPos(3, 1);copyPos(2, 1);copyPos(1, 0);copyPos(0, 0);
			obj->vel.y -= 1;
			obj->age = 0;
			obj->type = Object_PLAYER_DEAD;
			break;
		case Object_PLAYER_DEAD:
			obj->age++;
			for (int b=0;b<11;b++) {
				moveNode(&obj->parts[b], 0.1, 0.999);
				obj->parts[b].pos.xy += obj->vel.xy;
			}
			obj->vel.xy *= 0.5;
			real e = (150-obj->age)/150;
			pullNodes(obj, 1, 2, 4*e,0.5,0.5);
			pullNodes(obj, 3, 5, 4*e,0.5,0.5);
			pullNodes(obj, 4, 7, 4*e,0.5,0.5);
			pullNodes(obj, 6, 9, 5*e,0.5,0.5);
			pullNodes(obj, 8, 10, 5*e,0.5,0.5);
			for (int b=0;b<11;b++)
				updateNode(&obj->parts[b], 0.1, false, false);
			if (obj->age>150)
				Object_remove(obj--);
			break;
		case Object_FIGHTER: case Object_FIGHTER_JUMPING:
			obj->age++;
			if (obj->type==Object_FIGHTER) {
				moveNode(&obj->parts[0],-0.2,0.995);
				moveNode(&obj->parts[1],-0.1,0.995);
				moveNode(&obj->parts[2],0,0.995);
				moveNode(&obj->parts[3],0,0.995);
				moveNode(&obj->parts[4],0.3,0.995);
				moveNode(&obj->parts[5],0.3,0.995);
			} else {
				moveNode(&obj->parts[0],0.1,0.995);
				moveNode(&obj->parts[1],0.1,0.995);
				moveNode(&obj->parts[2],0.1,0.995);
				moveNode(&obj->parts[3],0.1,0.995);
				moveNode(&obj->parts[4],0.1,0.995);
				moveNode(&obj->parts[5],0.1,0.995);
			}
			checkDrag(obj, 6);
			obj->parts[0].pos.xy += obj->vel.xy;
			obj->vel.xy *= 0.5;
			if (obj->type==Object_FIGHTER) {
				// check feets
				fighterWalk(obj);
				fighterKick(obj);
			} else if (obj->age>10 && (obj->parts[4].touching||obj->parts[5].touching) && Rnd_perchance(10)) {
				obj->type = Object_FIGHTER;
				obj->age = 0;
			}
			pullNodes(obj, 0, 1, 4, 0.5,0.5);
			pullNodes(obj, 1, 2, 4, 0.5,0.5);
			pullNodes(obj, 1, 3, 4, 0.5,0.5);
			pullNodes(obj, 2, 4, 5, 0.5,0.5);
			pullNodes(obj, 3, 5, 5, 0.5,0.5);
			pullNodes(obj, 2, 3, 5, 0.1,0.1);
			for (int i=0;i<6;i++)
				updateNode(&obj->parts[i], 0.1, (i<4), obj->held>0);
			int t = checkTouching(obj,0,6);
			if (t==3 || t==-5)
				obj->type = Object_FIGHTER_DYING;
			if (obj->type==Object_FIGHTER && checkTouching(obj,0,6))
				obj->age = 0;
			else if (obj->age>50)
				obj->type = Object_FIGHTER_JUMPING;
			if (Menu_edgeMode==1) {
				for (int r=4;r<=5;r++) {
					int w=0,b=0;
					if (obj->parts[r].pos.x<8) {
						w = W+6;
						b = obj->parts[r].oldPos.y;
					} else if (obj->parts[r].pos.x>=WIDTH-8) {
						w = 10;
						b = obj->parts[r].oldPos.y;
					}
					if (w+b!=0) {
						obj->type = Object_FIGHTER;
						obj->age = 0;
						Dot* part = Dot_at[b][w];
						if (part > Dot_BGFAN) {
							if (part < Dot_0) {
								obj->parts[r].pos = obj->parts[r].oldPos;
								continue;
							} else if (ELEMENTS[part->type].state != State_LIQUID) {
								obj->parts[r].pos = obj->parts[r].oldPos;
								continue;
							}
						}
						Point e = Vec_sub2(obj->parts[r].pos, obj->parts[r].oldPos);
						Vec_fastNormalize(&e);
						for (int d=0; d<=10;d++) {
							obj->parts[d].pos.x = w+e.x+Random_2(-0.1,0.1);
							obj->parts[d].pos.y = b+e.y+Random_2(-0.1,0.1);
							obj->parts[d].oldPos = (Point){w,b};
						}
						break;
					}
				}
			}
			break;
		case Object_FIGHTER_DYING:
			copyPos(10, 5);copyPos(9, 4);copyPos(8, 3);copyPos(7, 3);copyPos(6, 2);copyPos(5, 2);copyPos(4, 1);copyPos(3, 1);copyPos(2, 1);copyPos(1, 0);
			obj->vel.y -= 1;
			obj->age = 0;
			obj->type = Object_FIGHTER_DEAD;
			break;
		case Object_FIGHTER_DEAD:
			obj->age++;
			for (int b=0; b<11; b++) {
				moveNode(&obj->parts[b], 0.1, 0.999);
				obj->parts[b].pos.xy += obj->vel.xy;
			}
			obj->vel.xy *= 0.5;
			e = (150-obj->age)/150;
			pullNodes(obj, 1, 2, 4*e,0.5,0.5);
			pullNodes(obj, 3, 5, 4*e,0.5,0.5);
			pullNodes(obj, 4, 7, 4*e,0.5,0.5);
			pullNodes(obj, 6, 9, 5*e,0.5,0.5);
			pullNodes(obj, 8, 10, 5*e,0.5,0.5);
			for (int b=0;b<11;b++)
				updateNode(&obj->parts[b], 0.1, false, false);
			if (obj->age>150)
				Object_remove(obj--);
			break;
		case Object_BOX:
			obj->age++;
			for (int b=0;b<4;b++)
				moveNode(&obj->parts[b],0.1,1);
			checkDrag(obj, 4);
			// kick
			for (int b=0;b<4;b++) {
				Object_FOR (r) {
					if (r->type==Object_FIGHTER||r->type==Object_FIGHTER_JUMPING||r->type==Object_PLAYER) {
						for (int i=4;i<=5;i++) {
							ObjectNode* part = &r->parts[i];
							real g = abs(part->pos.x - obj->parts[b].pos.x);
							real q = abs(part->pos.y - obj->parts[b].pos.y);
							if (g<=3 && q<=3) {
								obj->parts[b].pos.x += 1*(part->pos.x - part->oldPos.x);
								obj->parts[b].pos.y += 2*(part->pos.y - part->oldPos.y);
							}
						}
					}
				}
			}
			real r = 4*(obj->meta+1);
			pullNodes(obj,0,1,r,0.5,0.5);
			pullNodes(obj,1,2,r,0.5,0.5);
			pullNodes(obj,2,3,r,0.5,0.5);
			pullNodes(obj,3,0,r,0.5,0.5);
			pullNodes(obj,0,2,1.4142135*r,0.5,0.5);
			pullNodes(obj,1,3,1.4142135*r,0.5,0.5);
			for (int b=0;b<4;b++)
				updateNode(&obj->parts[b],0.5,false,true);
			t = checkTouching(obj,0,6);
			if (t==3 || t==-5)
				obj->type = Object_BOX_DYING;
			break;
		case Object_BOX_DYING:
			copyPos(7, 0);
			copyPos(6, 3);
			copyPos(5, 3);
			copyPos(4, 2);
			copyPos(3, 2);
			copyPos(2, 1);
			obj->held = 0;
			obj->age = 0;
			obj->type = checkTouching(obj,0,4)==-5 ? Object_BOX_DEAD : Object_BOX_BURNING;
			break;
		case Object_BOX_BURNING: case Object_BOX_DEAD:
			obj->age++;
			checkDrag(obj, 8);
			for (int b=0;b<8;b++)
				moveNode(&obj->parts[b], 0.1, 0.999);
			r=(real)(150-obj->age)/150*(obj->meta+1)*4;
			pullNodes(obj, 0, 1, r, 0.5, 0.5);
			pullNodes(obj, 2, 3, r, 0.5, 0.5);
			pullNodes(obj, 4, 5, r, 0.5, 0.5);
			pullNodes(obj, 6, 7, r, 0.5, 0.5);
			// put fire on burning box
			if (obj->type==Object_BOX_BURNING && Dot_limit1000()) {
				for (int b=0;b<5;b+=2) {
					Point e = {.xy=
						(obj->parts[b+1].oldPos.xy - obj->parts[b].oldPos.xy) * Random_(1) + obj->parts[b].oldPos.xy
					};
					if (*Dot_pos2(e)<=Dot_BGFAN)
						Dot_create(e.x, e.y, Elem_FIRE);
				}
			}
			for (int b=0;b<8;b++)
				updateNode(&obj->parts[b],0.1,false,false);
			if (obj->age>150)
				Object_remove(obj--);
			break;
		case Object_CREATE:
			if (obj->parts[0].createType==0) {
				// check for touching
				Point pos = obj->parts[0].pos;
				bool touching(Point pos2) {
					return (pos.x+8>=pos2.x &&
					        pos.x-4<=pos2.x &&
					        pos.y+8>=pos2.y &&
					        pos.y-4<=pos2.y);
				}
				Object_FOR (r) {
					if (touching(r->parts[0].pos)) {
						if (r->type==Object_FIGHTER || r->type==Object_BOX) {
							obj->parts[0].createType = r->type;
							obj->meta = r->meta;
						} else if (r->type==Object_PLAYER) {
							Object_FOR (e) {
								if (e->type==Object_CREATE && e->parts[0].createType==Object_PLAYER)
									e->parts[0].createType = 0;
							}
							obj->parts[0].createType = r->type;
							obj->meta = r->meta;
						}
					}
				}
				Ball_FOR (r) {
					if (r->used && touching(r->pos)) {
						obj->parts[0].createType = Object_BALL;
						obj->meta = r->type;
					}
				}
			} else {
				// create is spawning objects:
				axis x = obj->parts[0].pos.x;
				axis y = obj->parts[0].pos.y;
				int type = obj->parts[0].createType;
				if (type==Object_PLAYER) {
					if (Rnd_perchance(10))
						Object_create(x,y,Elem_PLAYER,obj->meta);
				} else if (Rnd_perchance(1)) {
					if (type==Object_FIGHTER)
						Object_create(x,y,0,0);
					else if (type==Object_BOX)
						Object_create(x,y,Elem_BOX,obj->meta);
					else if (type==Object_BALL)
						Ball_create(x+2,y+2,obj->meta);
				}
			}
		}
	}
}

void Object_save(SavePixel save[H][W]) {
	Object_FOR (e) {
		ObjectNode* node = NULL;
		Elem type;
		int meta = 0;
		if (e->type==Object_FIGHTER || e->type==Object_FIGHTER_JUMPING) {
			node = &e->parts[4];
			type = Elem_FIGHTER;
		} else if (e->type==Object_BOX) {
			node = &e->parts[0]; //maybe avg the points instead?
			type = Elem_BOX;
			meta = e->meta;
		} else if (e->type==Object_PLAYER) {
			node = &e->parts[4];
			type = Elem_PLAYER;
			meta = e->meta;
		} else if (e->type==Object_CREATE) {
			node = &e->parts[0];
			type = Elem_BOX;
			meta = 10;
		} else
			continue;
		axis x = (int)node->pos.x & ~3;
		axis y = (int)node->pos.y & ~3;
		if (Save_onscreen(x,y))
			save[y-8][x-8] = (SavePixel){type, meta};
	}
}

void Object_reset(void) {
	Object_next = entitys;
}
