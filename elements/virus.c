break; case Elem_VIRUS:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0, 0.1);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	
	if (p->charge==0) {
		Dot* f = Dot_rndNear(p->pos,3);
		if (f>=Dot_0 && f->type!=Elem_VIRUS)
			p->Cvirus.type = f->type;
	} else if (p->charge<=0x800) { //this should've been <
		int x = Random_int(3)-1;
		int y = Random_int(3)-1;
		Dot* f = Dot_pos3(p->pos, x, y);
		if (x&&y && f>=Dot_0 && (f->type!=Elem_VIRUS || f->charge==0)) {
			f->type = Elem_VIRUS;
			f->charge = 0;
			f->Cvirus.type = p->Cvirus.type;
			f->pumpType = 0;
		}
		p->Cvirus.age++;
	} else {
		p->Cvirus.age++;
		if (p->Cvirus.age>=128) {
			p->type = p->Cvirus.type;
			p->charge = 0;
			p->vel = (Point){0,0};
		}
	}

#elif defined UPDATE_BALL
	// nothing

#elif defined UPDATE_BALL_PART
	if (part->type>0) {
		if (ball->charge==0)
			ball->charge = part->type;
		else {
			part->type = ball->charge;
			part->charge = 0;
			part->pumpType = 0;
		}
	}
#endif
}
