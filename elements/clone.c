break; case Elem_CLONE:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	
	// if not cloning
	if (!p->meta) {
		// check random nearby part
		axis x = Random_int(5)-1; // 5-1, really?
		Dot* near = Dot_pos2(p->pos)[Dot_ofs(x, Random_int(5)-1)];
		if (near>=Dot_0) {
			if (near->type == Elem_CLONE)
				p->meta = near->meta;
			else
				p->meta = near->type;
		}
	} else if (Dot_limit1000()) { // create particles
		int x = p->pos.x + Random_int(3)-1;
		int y = p->pos.y + Random_int(3)-1;
		if (*Dot_pos(x,y)<=Dot_BGFAN && Rnd_perchance(10))
			Dot_create(x,y,p->meta);
	}

#elif defined UPDATE_BALL
	if (ball->meta==0 && touched>0)
		ball->meta = touched;
	else if (ball->meta && Dot_limit1000()) {
		int x = ball->pos.x;
		int y = ball->pos.y;
		if (ELEMENTS[ball->meta].state==State_POWDER || ball->meta==Elem_MAGMA || ball->meta==Elem_SPARK)
			y+=4;
		if (Dot_pos(x, y)[0]<=Dot_BGFAN)
			Dot_create(x, y, ball->meta);
	}

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return 1;
#endif
}
