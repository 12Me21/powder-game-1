break; case Elem_METAL:
{
#ifdef UPDATE_PART
	Part_at[(int)p->pos.y][(int)p->pos.x] = p;
	p->vel = (Vector){0,0};
	int x = p->pos.x+Random_int(5)-2;
	Part* near = Part_at[(int)p->pos.y+Random_int(5)-2][x];
	if (near>=Part_0) {
		switch (near->type) {
		when(Elem_WATER):;
			if (Random_(100)<2) //todo: this comes up a lot. maybe optimize
				p->type = Elem_POWDER;
		when(Elem_MAGMA):;
			if (Random_(100)<2)
				p->type = Elem_MAGMA;
		}
	}
#endif
}
