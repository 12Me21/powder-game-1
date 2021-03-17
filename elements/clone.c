break; case Elem_CLONE:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	
	// if not cloning
	if (!p->charge) {
		// check random nearby part
		axis x = Random_int(5)-1; // 5-1, really?
		axis y = Random_int(5)-1;
		Dot* near = Dot_pos3(p->pos, x, y);
		if (near>=Dot_0) {
			if (near->type == Elem_CLONE)
				p->charge = near->charge;
			else
				p->charge = near->type;
		}
	} else if (Dot_limit1000()) { // create particles
		int x = p->pos.x + Random_int(3)-1;
		int y = p->pos.y + Random_int(3)-1;
		if (*Dot_pos(x,y)<=Dot_BGFAN && Rnd_perchance(10))
			Dot_create(x,y,p->charge);
	}

#elif defined UPDATE_BALL
	if (ball->charge==0 && touched>0)
		ball->charge = touched;
	else if (ball->charge && Dot_limit1000()) {
		int x = ball->pos.x;
		int y = ball->pos.y;
		if (ELEMENTS[ball->charge].state==State_POWDER || ball->charge==Elem_MAGMA || ball->charge==Elem_SPARK)
			y+=4;
		if (*Dot_pos(x,y)<=Dot_BGFAN)
			Dot_create(x, y, ball->charge);
	}

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return 1;
#endif
}
