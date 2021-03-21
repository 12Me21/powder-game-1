break; case Elem_SEED:
{
#ifdef UPDATE_PART
	if (p->charge==0) {
		Point airvel = c->vel;
		airvel.y += Random_2(0.01, 0.09);
		airvel.xy += p->vel.xy;
		p->vel.xy *= 0.8;
		Dot_blow(p, airvel);
	} else
		Dot_toGrid(p);
	
	if (p->charge==0) {
		Dot* below = Dot_pos3(p->pos, 0, 1);
		if (below<Dot_0)
			break;
		if (below->type!=Elem_POWDER && below->type!=Elem_WOOD && below->type!=Elem_VINE)
			break;
		if (!Dot_limit1000())
			break;
	}
	
	p->charge=1;
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y - (int)Random_(1.5);
	if (Dot_at[y][x] <= Dot_BGFAN) {
		if (Dot_at[y+1][x] <= Dot_BGFAN) {
			*Dot_pos2(p->pos) = Dot_EMPTY;
			p->pos = (Point){x,y};
			Dot_at[y][x] = p;
			Dot_create(x, y+1, Elem_WOOD);
		}
		if (Rnd_perchance(5))
			Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched<0) break;
	// destroyed by acid
	if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SEED, 0, Point(0.5*ball->vel.xy), 0.5);
	// burned by hot elements (except spark)
	else if (touched!=Elem_SPARK && touched[ELEMENTS].state==State_HOT)
		Ball_break(ball, 0, Elem_FIRE, 0, Point(0.5*ball->vel.xy), 0.5);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_POWDER):;
		if (ball->charge==1)
			// when hydrated, turn into wood ball
			*newType = Elem_WOOD;
		else {
			// otherwise, turn powder into seed
			part->type = Elem_SEED;
			part->charge = 0;
		}
	when(Elem_WATER):;
		// hydrated
		ball->charge = 1;
	when(Elem_VINE):;
		// turn vine into wood
		part->type = Elem_WOOD;
		part->charge = 0;
	}
#endif
}
