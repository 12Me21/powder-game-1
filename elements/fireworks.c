break; case Elem_FIREWORKS:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	p->vel.xy += 0.1*airvel.xy;
	airvel.y += Random_2(0.1,0.2);
	p->vel.xy *= 0.9;
	airvel.xy += p->vel.xy;
	Dot_blow(p, airvel);
	
	if (p->charge==0) {
	// this is bad. if elem is not set, use the menu selection
		p->charge = Menu_BUTTONS[Menu_leftSelection].firework ?: Menu_BUTTONS[Menu_rightSelection].firework ?: Elem_POWDER;
	// has not been set off yet:
	} else if (p->charge<100) {
		Dot* near = Dot_rndNear(p->pos, 3);
		// light the fireworks if near a hot element
		if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT) {
			p->vel.y -= 0.1;
			Vec_fastNormalize(&p->vel);
			p->vel.xy *= 50;
			p->charge += 100;
		}
	// for 50 frames after being lit, do nothing
	} else if (p->charge<5000) {
		p->charge += 100;
	// after that, there's a 5% chance of exploding per frame
	} else if (Random_(100)<=5) {
		if (Dot_limit1000()) {
			// create a ring of 16 particles
			for (int i=0; i<512; i+=512/16) {
				Point angle = Vec_unit[i];
				int x = p->pos.x + 2*angle.x;
				int y = p->pos.y + 2*angle.y;
				x = clamp(x,8,W+8);
				y = clamp(y,8,H+8);
				if (Dot_at[y][x] <= Dot_BGFAN) {
					Dot* new = Dot_create(x, y, p->charge%100);
					if (new)
						new->vel.xy += 20*angle.xy;
				}
			}
		}
		Dot_KILL();
	}
#endif
}
