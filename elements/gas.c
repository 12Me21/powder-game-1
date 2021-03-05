break; case Elem_GAS:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0, -0.02);
	Vec_add(&airvel, p->vel);
	Vec_mul(&p->vel, 0.9);
	Part_blow(p, airvel);
	int g = Random_int(4);
	Part* near = Part_pos2(p->pos)[(Offset[]){Part_ofs(0,-1),-1,1,Part_ofs(0,-1)}[g]];
	if (near>=Part_0) {
		if (g<3 && (ELEMENTS[near->type].state == State_POWDER || ELEMENTS[near->type].state == State_LIQUID)) {
			Part_swap(p, near);
		} else if (near->type==Elem_GAS) {
			p->vel.x += Random_2(-0.2, 0.2);
			p->vel.y += Random_2(-0.2, 0.2);
		} else if (near->type==Elem_PUMP && near->pumpType==0) {
			near->meta = 0b100 | (char[]){0b10, 0b01, 0b11, 0b00}[g];
			near->pumpType = Elem_GAS;
			Part_remove(p--);
			break;
		}
	}
	if (p->meta==0) {
		int x = Random_int(5)-2;
		int y = Random_int(5)-2;
		Part* near = Part_pos2(p->pos)[Part_ofs(x,y)];
		if (near < Part_0 || ELEMENTS[near->type].state!=State_HOT)
			break;
	} else if (p->meta<2) {
		p->meta++;
		break;
	}
	void func(axis x, axis y, axis sx, axis sy) {
		Part* near = Part_pos(x, y)[0];
		if (near>=Part_0 && near->type==Elem_GAS)
			near->meta = 1;
		if (near<=Part_BGFAN && Rnd_perchance(1))
			Part_create(x, y, Elem_FIRE);
	}
	Part_doRadius(p->pos.x, p->pos.y, 10, func);
	Cell_addPressure(c,2);
	p->type = Elem_FIRE;
	p->meta = 0;

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (ELEMENTS[touched].state==State_HOT) {
			Ball_break(ball, 0, Elem_GAS, 0, 0, 0, 1);
			if (ball->meta<2) {
				ball->meta++;
				ball->used=true; //resurrect!
			}
		} else if (touched==Elem_ACID)
			Ball_break(ball, 0, Elem_GAS, 0, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
