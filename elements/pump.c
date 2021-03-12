break; case Elem_PUMP:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	
	if (p->pumpType==0)
		break;
	int dir = p->Cpump.dir;
	int r = Random_(1)<0.5 ? 1 : -1;
	for (int b=0;b<4;b++) {
		if (b==2) continue;
		Dot* f = Dot_pos2(p->pos)[(Offset[]){WIDTH,-1,-WIDTH,1}[(dir+b*r)&3]];
		if (f>=Dot_0 && f->type==Elem_PUMP) {
			if (f->pumpType==0) {
				Dot_swap(p,f);
				p->Cpump.dir += b*r;
			} else if (p->pumpType == f->pumpType) {
				f->Cpump.amount += p->Cpump.amount;
				p->meta = 0;
				p->pumpType = 0;
			} else {
				p->Cpump.dir += 2;
			}
			goto pumped;
		}
	}
	// if there wasn't another pump to transfer to:
	if (Dot_pos2(p->pos)[2*(Offset[]){WIDTH,-1,-WIDTH,1}[dir]]<=Dot_BGFAN && Dot_limit1000()) {
		axis x = p->pos.x+0.5;
		axis y = p->pos.y+0.5;
		switch (dir) {
		case 0: y+=2; break;
		case 1: x-=2; break;
		case 2: y-=2; break;
		case 3: x+=2; break;
		}
		Dot_create(x,y,p->pumpType);
	}
	if (p->Cpump.amount<=1) {
		p->meta = 0;
		p->pumpType = 0;
	} else {
		p->Cpump.amount--;
	}
 pumped:;

#elif defined UPDATE_BALL
	if (ball->meta!=0 && Dot_limit1000()) {
		Point c = ball->vel;
		Vec_fastNormalize(&c);
		Vec_mul(&c, 4);
		axis x = ball->pos.x-c.x;
		axis y = ball->pos.y-c.y;
		if (*Dot_pos(x,y)<=Dot_BGFAN) {
			Elem elem = ball->meta & 0xFF;
			int fill = ball->meta>>8;
			if (fill>0) {
				Dot_create(x,y,elem);
				ball->meta = (fill-1)<<8 | elem;
			}
		}
	}
#elif defined UPDATE_BALL_PART
	if (!ball->meta) {
		if (part->type==Elem_WATER||part->type==Elem_OIL||part->type==Elem_MAGMA||part->type==Elem_NITRO||part->type==Elem_GAS||part->type==Elem_SOAPY||part->type==Elem_ACID||part->type==Elem_SEAWATER||part->type==Elem_MERCURY||part->type==Elem_CLOUD)
			ball->meta = part->type;
	} else {
		int type = ball->meta & 0xFF; //what if we used field size uh
		int amount = ball->meta>>8;
		if (part->type == type) {
			ball->meta = (amount+1)<<8 | type;
			Dot_remove(part);
		}
	}
	if (part->type==Elem_MAGMA || part->type==Elem_LASER || part->type==Elem_THUNDER)
		return 1;
#endif
}
