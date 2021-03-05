break; case Elem_FIREWORKS:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	p->vel.x += 0.1*airvel.x;
	p->vel.y += 0.1*airvel.y;
	airvel.y += Random_2(0.1,0.2);
	Vec_mul(&p->vel, 0.9);
	Vec_add(&airvel, p->vel);
	Part_blow(p, airvel);
	if (!p->meta) {
		// this is bad
		p->meta = Menu_BUTTONS[Menu_leftSelection].firework ?: Menu_BUTTONS[Menu_rightSelection].firework ?: Elem_POWDER;
	} else if (p->meta<100) {
		int x = p->pos.x+Random_int(3)-1;
		Part* near = Part_at[(int)p->pos.y+Random_int(3)-1][x];
		if (near>=Part_0 && ELEMENTS[near->type].state==State_HOT) {
			p->vel.y -= 0.1;
			Vec_fastNormalize(&p->vel);
			Vec_mul(&p->vel, 50);
			p->meta += 100;
		}
	} else if (p->meta<5000) {
		p->meta += 100;
		break;
	} else if (Random_(100)>5) {
		break;
	} else if (0/*there are NOT enough parts left*/) {
		Part_remove(p--);
	} else {
		int i;
		for (i=0; i<512; i+=32) {
			Point angle = Vec_unit[i];
			int x = p->pos.x+2*angle.x;
			int y = p->pos.y+2*angle.y;
			x = clamp(x,8,W+8);
			y = clamp(y,8,H+8);
			if (Part_at[y][x] <= Part_BGFAN) {
				Part* new = Part_create(x, y, p->meta%100);
				if (new) {
					new->vel.x += 20*angle.x;
					new->vel.y += 20*angle.y;
				}
			}
		}
		Part_remove(p--);
	}
#endif
}
