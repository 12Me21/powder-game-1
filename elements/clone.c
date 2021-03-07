break; case Elem_CLONE:
{
#ifdef UPDATE_PART
	Part_blow(p, (Point){0,0});
	// if not cloning
	if (!p->meta) {
		// check random nearby part
		axis x = Random_int(5)-1; // 5-1, really?
		Part* near = Part_pos2(p->pos)[Part_ofs(x, Random_int(5)-1)];
		if (near>=Part_0) {
			if (near->type == Elem_CLONE)
				p->meta = near->meta;
			else
				p->meta = near->type;
		}
	} else if (Part_limit1000()) { // create particles
		int x = p->pos.x + Random_int(3)-1;
		int y = p->pos.y + Random_int(3)-1;
		if (*Part_pos(x,y)<=Part_BGFAN && Rnd_perchance(10))
			Part_create(x,y,p->meta);
	}

#elif defined UPDATE_BALL
	if (ball->meta==0 && touched>0)
		ball->meta = touched;
	else if (ball->meta && Part_limit1000()) {
		int x = ball->pos.x;
		int y = ball->pos.y;
		if (ELEMENTS[ball->meta].state==State_POWDER || ball->meta==Elem_MAGMA || ball->meta==Elem_SPARK)
			y+=4;
		if (Part_pos(x, y)[0]<=Part_BGFAN)
			Part_create(x, y, ball->meta);
	}

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return 1;
#endif
}
