break; case Elem_SEED:
{
#ifdef UPDATE_PART
	Point airvel;
	if (p->meta==0) {
		airvel = c->vel;
		airvel.y += Random_2(0.01, 0.09);
		airvel.xy += p->vel.xy;
		p->vel.xy *= 0.8;
	} else
		airvel = (Point){0,0};
	Part_blow(p, airvel);

	if (p->meta==0) {
		Part* below = Part_pos3(p->pos, 0, 1);
		if (below<Part_0 || (below->type!=Elem_POWDER && below->type!=Elem_WOOD && below->type!=Elem_VINE)) //TODO: !IMPORTANT! check part limit here
			break;
	}
	
	p->meta=1;
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y - Random_int(1.5); //yes
	if (Part_at[y][x] <= Part_BGFAN) {
		if (Part_at[y+1][x] <= Part_BGFAN) {
			*Part_pos2(p->pos) = Part_EMPTY;
			p->pos = (Point){x,y};
			Part_at[y][x] = p;
			Part_create(x, y+1, Elem_WOOD);
		}
		if (Rnd_perchance(5))
			Part_KILL();
	}

#elif defined UPDATE_BALL
	if (touched<0) break;
	// destroyed by acid
	if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SEED, 0, 0.5*ball->vel.x, 0.5*ball->vel.y, 0.5);
	// burned by hot elements (except spark)
	else if (touched!=Elem_SPARK && touched[ELEMENTS].state==State_HOT)
		Ball_break(ball, 0, Elem_FIRE, 0, 0.5*ball->vel.x, 0.5*ball->vel.y, 0.5);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_POWDER):;
		if (ball->meta==1)
			// when hydrated, turn into wood ball
			*newType = Elem_WOOD;
		else {
			// otherwise, turn powder into seed
			part->type = Elem_SEED;
			part->meta = 0;
		}
	when(Elem_WATER):;
		// hydrated
		ball->meta = 1;
	when(Elem_VINE):;
		// turn vine into wood
		part->type = Elem_WOOD;
		part->meta = 0;
	}
#endif
}
