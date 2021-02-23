break; case Elem_SEED:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	if (p->meta==0) {
		airvel.y += Random_2(0.01, 0.09);
		Vec_add(&airvel, &p->vel);
		Vec_mul(&p->vel, 0.8);
	} else
		airvel = (Vector){0,0};
	Part_blow(p, &airvel);
	if (p->meta==0) {
		Part* below = Part_at[(int)p->pos.y+1][(int)p->pos.x];
		if (below<Part_0 || (below->type!=Elem_POWDER&&below->type!=Elem_WOOD&&below->type!=Elem_VINE)) //TODO: !IMPORTANT! check part limit here
			break;
	}
	p->meta=1;
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y - Random_int(1.5); //yes
	if (Part_at[y][x] <= Part_BGFAN) {
		if (Part_at[y+1][x] <= Part_BGFAN) {
			Part_at[(int)p->pos.y][(int)p->pos.x] = Part_EMPTY;
			p->pos = (Vector){x,y};
			Part_at[y][x] = p;
			Part_create(x, y+1, Elem_WOOD);
		}
		if (Random_(100)<5)
			Part_remove(p--);
	}
#endif
}
