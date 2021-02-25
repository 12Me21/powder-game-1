break; case Elem_CLONE:
{
#ifdef UPDATE_PART
	Part_blow(p, &(Vector){0,0});
	// if not cloning
	if (!p->meta) {
		// check random nearby part
		axis x = Random_int(5)-1; // 5-1, really?
		Part* near = Part_pos2(&p->pos)[Part_ofs(x, Random_int(5)-1)];
		if (near>=Part_0) {
			if (near->type == Elem_CLONE)
				p->meta = near->meta;
			else
				p->meta = near->type;
		}
	} else { // create particles
		// todo: check part limit
		int x = p->pos.x + Random_int(3)-1;
		int y = p->pos.y + Random_int(3)-1;
		if (Part_pos2(&p->pos)[Part_ofs(x, y)] <= Part_BGFAN && Random_(100)<10)
			Part_create(x,y,p->meta);
	}
#endif
}
