break; case Elem_GAS:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0, -0.02);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.9;
	Dot_blow(p, airvel);
	
	int g = Random_int(4);
	Dot* near = Dot_pos2(p->pos)[(Offset[]){Dot_ofs(0,-1),-1,1,Dot_ofs(0,-1)}[g]];
	if (near>=Dot_0) {
		if (g<3 && (near->type[ELEMENTS].state==State_POWDER || near->type[ELEMENTS].state==State_LIQUID)) {
			Dot_swap(p, near);
		} else if (near->type==Elem_GAS) {
			p->vel.xy += Rnd_point(-0.2,0.2, -0.2,0.2).xy;
		} else if (Dot_checkPump(p, near, g))
			Dot_KILL();
	}
	if (p->meta==0) {
		Dot* near = Dot_rndNear(p->pos, 5);
		if (near<Dot_0 || near->type[ELEMENTS].state!=State_HOT)
			break;
	} else if (p->meta<2) {
		p->meta++;
		break;
	}
	void func(axis x, axis y, axis sx, axis sy) {
		Dot* near = Dot_pos(x, y)[0];
		if (near>=Dot_0 && near->type==Elem_GAS)
			near->meta = 1;
		if (near<=Dot_BGFAN && Rnd_perchance(1))
			Dot_create(x, y, Elem_FIRE);
	}
	Dot_doRadius(p->pos.x, p->pos.y, 10, func);
	Cell_addPressure(c,2);
	p->type = Elem_FIRE;
	p->meta = 0;

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (ELEMENTS[touched].state==State_HOT) {
			// the first time, ball releases extra gas without breaking.
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
