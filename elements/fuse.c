break; case Elem_FUSE:
{
#ifdef UPDATE_PART
	Part_blow(p, &(Vector){0,0});
	if (p->meta<0x100) {
		axis x = Random_int(3)-1;
		axis y = Random_int(3)-1;
		Part* near = Part_pos3(&p->pos, x, y);
		if (near>=Part_0) {
			if (ELEMENTS[near->type].state==State_HOT && near->type!=Elem_SPARK)
				p->meta += 0x100;
			else if (near->type==Elem_WATER || near->type==Elem_SALTWATER)
				p->type = Elem_GUNPOWDER;
		}
	} else {
		p->meta += 0x100;
		if (p->meta>=0x300) {
			int g;
			switch (p->meta & 0xFF) {
			case Elem_OIL:
				g = Elem_FIRE;
			when(Elem_NITRO):;
				g=Elem_NITRO;
			when(Elem_SOAPY):;
				g=Elem_STEAM;
			otherwise:
				g=Elem_SPARK;
			}
			Part** at = Part_pos2(&p->pos);
			void create(axis x, axis y) {
				if (at[Part_ofs(x,y)]<=Part_BGFAN)
					Part_create(p->pos.x+x,p->pos.y+y,g);
			}
			if (at[1]>=Part_0) {
				create(-1, 0);
				create(-1, -1);	
				create(-1, 1);
			}
			if (at[-1]>=Part_0) {
				create(1, 0);
				create(1, -1);	
				create(1, 1);
			}
			if (at[Part_ofs(0,1)]>=Part_0) {
				create(0, -1);
				create(-1, -1);	
				create(1, -1);
			}
			if (at[Part_ofs(0,-1)]>=Part_0) {
				create(0, 1);
				create(-1, 1);	
				create(1, 1);
			}
			for (int b=0; b<8; b++) {
				Part* near = Part_pos2(&p->pos)[(Offset[]){1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1}[b]];
				if (near>=Part_0) {
					if (near->type==Elem_FUSE && near->meta<0x100)
						near->meta += 0x100;
					else if (near->type==Elem_FIREWORKS) {
						near->vel.y -= 50;
						near->meta += 100;
					} else if (near->type==Elem_OIL || near->type==Elem_C4 || near->type==Elem_GAS)
						near->meta = 1;
					else if (near->type==Elem_NITRO)
						near->vel.y -= 20;
				}
			}
			p->type = g;
			p->meta = 0;
		}
	}

#elif defined UPDATE_BALL

#elif defined UPDATE_BALL_PART
#endif
}
