break; case Elem_FAN:
{
#ifdef UPDATE_PART

	c->vel.xy += p->vel.xy;

	// fan is special because other particles can pass through it.
	// this is achieved by putting a special value onto the part grid,
	// rather than a pointer to itself.
	Dot** n = Dot_pos2(p->pos);
	if (*n == Dot_EMPTY)
		*n = Dot_BGFAN;
	
#elif defined UPDATE_BALL

	if (touched>0) {
		Block* cell = &Dot_blocks[(int)ball->pos.y/4][(int)ball->pos.x/4];
		Block_addPressure(cell, 10);
	}
#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
