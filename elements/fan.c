break; case Elem_FAN:
{
#ifdef UPDATE_PART
	Vec_add(&c->vel, &p->vel);
	Part** n = Part_pos2(&p->pos);
	if (*n == Part_EMPTY)
		*n = Part_BGFAN;
#elif defined UPDATE_BALL
	if (touched>0) {
		Block* cell = &Part_blocks[(int)ball->pos.y/4][(int)ball->pos.x/4];
		cell->pres += 10;
		pd -= 10;
	}
#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
