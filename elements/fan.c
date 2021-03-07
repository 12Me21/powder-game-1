break; case Elem_FAN:
{
#ifdef UPDATE_PART

	c->vel.xy += p->vel.xy;

	// fan is special because other particles can pass through it.
	// this is achieved by putting a special value onto the part grid,
	// rather than a pointer to itself.
	Part** n = Part_pos2(p->pos);
	if (*n == Part_EMPTY)
		*n = Part_BGFAN;
	
#elif defined UPDATE_BALL

	if (touched>0) {
		Block* cell = &Part_blocks[(int)ball->pos.y/4][(int)ball->pos.x/4];
		Cell_addPressure(cell, 10);
	}
#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
