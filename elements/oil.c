break; case Elem_OIL:
{
#ifdef UPDATE_PART
	p->vel.x += 0.2*c->vel.x;
	p->vel.y += 0.2*c->vel.y;
	if (Part_at[(int)p->pos.y+1][(int)p->pos.x] != Part_EMPTY) {
		if (Part_at[(int)p->pos.y][(int)p->pos.x-1] == Part_EMPTY)
			p->vel.x -= Random_2(0.1, 0.2);
		if (Part_at[(int)p->pos.y][(int)p->pos.x+1] == Part_EMPTY)
			p->vel.x += Random_2(0.1, 0.2);
	}
	p->vel.x += Random_2(-0.01, 0.01);
	p->vel.y += Random_2(0.01, 0.05);
	Vec_mul(&p->vel, 0.9);
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Part_blow(p, &airvel);
	int dir = Random_int(8);
	
	Part* g;
	if (dir<5)
		g = Part_at[(int)p->pos.y-1][(int)p->pos.x];
	else if (dir<6)
		g = Part_at[(int)p->pos.y][(int)p->pos.x-1];
	else if (dir<7)
		g = Part_at[(int)p->pos.y][(int)p->pos.x+1];
	else
		g = Part_at[(int)p->pos.y+1][(int)p->pos.x];
	if (g>=Part_0) {
		//powders (except stone), water, nitro, saltwater
		if (dir<7 && ((ELEMENTS[g->type].state==State_POWDER && g->type!=Elem_STONE) || g->type==Elem_WATER || g->type==Elem_NITRO || g->type==Elem_SALTWATER)) {
			if (Random_(100)<10)
				Part_swap(p, g);
			//burn
		} else if (ELEMENTS[g->type].state==State_HOT) {
			p->meta = 1;
			//oil is absorbed by FUSE
		} else if (g->type==Elem_FUSE && g->meta<256) {
			g->meta = Elem_OIL;
			Part_remove(p--);
			break;
			//and PUMP
		} else if (g->type==Elem_PUMP && !g->pumpType) {
			g->meta = 4 | (dir<5?2:dir<6?1:dir<7?3:0); //make this a func
			g->pumpType = Elem_OIL;
			Part_remove(p--);
			break;
		}
	}
	if (p->meta==1) {
		int x = p->pos.x+Random_int(3)-1;
		int y = p->pos.y+Random_int(3)-1;
		Part* near = Part_at[y][x];
		if (near<=Part_BGFAN)
			Part_create(x, y, Elem_FIRE);
		if (Random_(100)<10) {
			Part_remove(p--);
			break;
		}
	}
#endif
}
