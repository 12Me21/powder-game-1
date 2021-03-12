break; case Elem_WOOD:
{
#ifdef UPDATE_PART
	Point airvel = p->vel;
	p->vel.xy *= 0.3;
	Dot_blow(p, airvel);
	
	//not burning
	if (p->meta==0) {
		int x = p->pos.x + Random_int(5)-2;
		int y = p->pos.y + Random_int(7)-3;
		Dot* near = Dot_at[y][x];
		if (near >= Dot_0) {
			switch (near->type) {
			when(Elem_FIRE): case Elem_MAGMA:
				if (Rnd_perchance(50))
					p->meta = 1;
				//wood creates seed when near water
			when(Elem_WATER):;
				if (Dot_limit1000()) {
					axis x = p->pos.x + Random_int(3)-1;
					axis y = p->pos.y + Random_int(3)-1;
					if (Dot_at[y][x] <= Dot_BGFAN && Rnd_perchance(10))
						Dot_create(x, y, Elem_SEED);
				}
			}
		}
		//burning
	} else if (p->meta==1) {
		axis x = p->pos.x + Random_int(3)-1;
		axis y = p->pos.y + Random_int(3)-1;
		Dot* near = *Dot_pos(x,y);
		//make fires
		if (near <= Dot_BGFAN) {
			if (Rnd_perchance(30)) {
				Dot* g = Dot_create(x, y, Elem_FIRE);
				if (g>=Dot_0)
					g->meta = 1;
			}
			//water puts out the fire and breaks the wood into powder
		} else if (near->type==Elem_WATER) {
			p->meta = 0;
			p->type = Elem_POWDER;
		}
		//generate powder sometimes
		if (Random_(1000)<5)
			p->type = Elem_POWDER;
	}

#elif defined UPDATE_BALL
	if (touched==Elem_TORCH)
		Ball_break(ball, 0, Elem_TORCH, 0, 0, 0, 0);
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_POWDER, 0, 0, 0, 0);
	else if (touched==Elem_THUNDER)
		Ball_break(ball, 0, Elem_POWDER, 0, 0, 0, 1);
	else if (touched>=0 && ELEMENTS[touched].state==State_HOT) {
		if (ball->meta==1) //if oiled
			Ball_break(ball, 0, Elem_WOOD, 1, 0, 0, 0);
		else
			Ball_break(ball, 0, Elem_FIRE, 1, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_SEED)
		part->meta = 1; // make seed grow
	else if (part->type==Elem_OIL)
		ball->meta = 1; // make ball burn longer
#endif
}
