break; case Elem_FUSE:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	
	if (!p->Cfuse.burning) {
		axis x = Random_int(3)-1;
		axis y = Random_int(3)-1;
		Dot* near = Dot_pos3(p->pos, x, y);
		if (near>=Dot_0) {
			if (ELEMENTS[near->type].state==State_HOT && near->type!=Elem_SPARK)
				p->Cfuse.burning = 1;
			else if (near->type==Elem_WATER || near->type==Elem_SEAWATER)
				p->type = Elem_GUNPOWDER;
		}
	} else {
		p->Cfuse.burning++;
		if (p->Cfuse.burning>=3) {
			int g;
			switch (p->Cfuse.type) {
			case Elem_OIL:
				g = Elem_FIRE;
			when(Elem_NITRO):;
				g=Elem_NITRO;
			when(Elem_SOAPY):;
				g=Elem_STEAM;
			otherwise:
				g=Elem_SPARK;
			}
			Dot** at = Dot_pos2(p->pos);
			void create(axis x, axis y) {
				if (at[Dot_ofs(x,y)]<=Dot_BGFAN)
					Dot_create(p->pos.x+x, p->pos.y+y, g);
			}
			if (at[1]>=Dot_0) {
				create(-1, 0);
				create(-1, -1);	
				create(-1, 1);
			}
			if (at[-1]>=Dot_0) {
				create(1, 0);
				create(1, -1);	
				create(1, 1);
			}
			if (at[Dot_ofs(0,1)]>=Dot_0) {
				create(0, -1);
				create(-1, -1);	
				create(1, -1);
			}
			if (at[Dot_ofs(0,-1)]>=Dot_0) {
				create(0, 1);
				create(-1, 1);	
				create(1, 1);
			}
			for (int b=0; b<8; b++) {
				Dot* near = Dot_pos2(p->pos)[(Offset[]){1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1}[b]];
				if (near>=Dot_0) {
					if (near->type==Elem_FUSE && !near->Cfuse.burning)
						near->Cfuse.burning = 1;
					else if (near->type==Elem_FIREWORKS) {
						near->vel.y -= 50;
						near->charge += 100;
					} else if (near->type==Elem_OIL || near->type==Elem_C4 || near->type==Elem_GAS)
						near->charge = 1;
					else if (near->type==Elem_NITRO)
						near->vel.y -= 20;
				}
			}
			p->type = g;
			p->charge = 0;
		}
	}

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (touched[ELEMENTS].state==State_HOT) {
			if (ball->charge==Elem_OIL)
				Ball_break(i,2,Elem_FIRE,0,0,0,0);
			else if (ball->charge==Elem_NITRO)
				Ball_break(i,0,Elem_NITRO,0,0,0,1);
			else if (ball->charge==Elem_SOAPY)
				Ball_break(i,0,Elem_STEAM,0,0,0,1);
			else
				Ball_break(i,0,Elem_SPARK,0,0,0,0);
		} else if (touched==Elem_WATER || touched==Elem_SEAWATER)
			Ball_break(i,0,Elem_GUNPOWDER,0,0,0,0);
		else if (touched==Elem_ACID)
			Ball_break(i,0,Elem_FUSE,0,0,0,0);
	}

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_OIL||part->type==Elem_NITRO||part->type==Elem_SOAPY)
		ball->charge = part->type;
#endif
}
