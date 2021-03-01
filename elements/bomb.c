break; case Elem_BOMB:
{
#ifdef UPDATE_PART
	p->vel.y += 0.03;
	Vec_mul(&p->vel, 0.92);
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Part_blow(p, &airvel);
	if (p->meta) {
		if (p->meta==Elem_BOMB) {
			Part_remove(p--);
			break;
		} else if (Random_(100)>5) { //GREATER than?
			break;
		} else {
			switch (p->meta) {
			case Elem_ICE:
				p->type = Elem_SNOW;
				p->meta = 0;
			when(Elem_WOOD): case Elem_STONE: case Elem_VINE:
				p->type = Elem_POWDER;
				p->meta = 0;
			when(Elem_NITRO): case Elem_TORCH:
				p->type = Elem_FIRE;
				p->meta = 1;
			when(Elem_SOAPY):;
				p->type = Elem_STEAM;
				p->meta = 0;
			when(Elem_METAL):;
				p->type = Elem_METAL;
				p->meta = 0;
			when(Elem_GLASS):;
				p->type = Elem_STONE;
				p->meta = 0;
			when(Elem_PUMP):;
				p->type = Elem_SPARK;
				p->meta = 0;
			otherwise:
				Part_remove(p--);
				goto BOMB_brk;
			}
		}
		break;
	}
	int x = Random_int(3)-1;
	int y = Random_int(3)-1;
	Part* near = Part_pos3(&p->pos, x, y);
	if (near<Part_0 || near->type==Elem_BOMB || near->type==Elem_CLONE)
		break;
	airvel = (Vector){0,0};
	void func1(axis x, axis y, axis sx, axis sy) {
		Part* c = *Part_pos(x,y);
		if (c>=Part_0 && c->type!=Elem_BOMB) {
			airvel.x += p->pos.x-x;
			airvel.y += p->pos.y-y;	
		}
	}
	Part_doRadius(p->pos.x, p->pos.y, 4, func1);
	Vec_fastNormalize(&airvel);
	void func2(axis x, axis y, axis sx, axis sy) {
		Part* c = *Part_pos(x,y);
		if (c>=Part_0 && c->type!=Elem_CLONE) {
			c->vel.x += airvel.x+1*(p->pos.x-x);
			c->vel.y += airvel.y+1*(p->pos.y-y);
			if (c->type!=Elem_BOMB||c->meta==0) {
				c->pumpType = 0;
				c->meta = c->type;
				c->type = Elem_BOMB;
			}
		}
	}
	Part_doRadius(p->pos.x, p->pos.y, 4, func2);
	Part_remove(p--);
 BOMB_brk:;

#elif defined UPDATE_BALL
	if (touched>=0 && touched!=Elem_BOMB && touched!=Elem_FIRE && touched!=Elem_GAS && touched!=Elem_LASER && ELEMENTS[touched].state>0) {
		Vector airvel = {0,0};
		void func1(axis x, axis y, axis sx, axis sy) {
			Part* c = *Part_pos(x,y);
			if (c>=Part_0 && c->type!=Elem_BOMB) {
				airvel.x += ball->pos.x-x;
				airvel.y += ball->pos.y-y;	
			}
		}
		Part_doRadius(ball->pos.x, ball->pos.y, 10, func1);
		Vec_fastNormalize(&airvel);
		void func2(axis x, axis y, axis sx, axis sy) {
			Part* c = *Part_pos(x,y);
			if (c>=Part_0) {
				c->meta = c->type;
				c->type = Elem_BOMB;
				c->pumpType = 0;
				c->vel.x += 0.5*airvel.x+0.5*(ball->pos.x-x);
				c->vel.y += 0.5*airvel.y+0.5*(ball->pos.y-y);
			}
		}
		Part_doRadius(ball->pos.x, ball->pos.y, 10, func2);
		ball->used = false;
	}

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
