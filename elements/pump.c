break; case Elem_PUMP:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);

	const Offset DIRS[4] = {WIDTH,-1,-WIDTH,1};
	const axis DIRSX[4] = {0,-1,0,1};
	const axis DIRSY[4] = {1,0,-1,0};
	
	if (p->pumpType==0)
		break;
	int dir = p->Cpump.dir;
	// randomly check in a clockwise or counterclockwise order
	int r = Random_(1)<0.5 ? 1 : -1;
	// this will either go
	// forward,left,right OR forward,right,left
	for (int b=0;b<4;b++) {
		if (b==2) continue;
		Dot* near = Dot_pos2(p->pos)[DIRS[(dir+b*r)&3]];
		if (near>=Dot_0 && near->type==Elem_PUMP) {
			if (near->pumpType==0) {
				// move forward
				Dot_swap(p,near);
				p->Cpump.dir += b*r;
			} else if (p->pumpType == near->pumpType) {
				// merge contents with pump carrying same element
				near->Cpump.amount += p->Cpump.amount;
				p->charge = 0;
				p->pumpType = 0;
			} else {
				// reverse direction
				p->Cpump.dir += 2;
			}
			goto pumped;
		}
	}
	// if there wasn't another pump to transfer to:
	if (Dot_pos2(p->pos)[2*DIRS[dir]]<=Dot_BGFAN && Dot_limit1000()) {
		Dot_create(
			p->pos.x+0.5+DIRSX[dir]*2, // I doubt this +0.5 ever matters
			p->pos.y+0.5+DIRSY[dir]*2,
			p->pumpType);
	}
	if (p->Cpump.amount<=1) {
		p->charge = 0;
		p->pumpType = 0;
	} else {
		p->Cpump.amount--;
	}
 pumped:;

#elif defined UPDATE_BALL
	if (ball->charge!=0 && Dot_limit1000()) {
		Point c = ball->vel;
		Vec_fastNormalize(&c);
		Vec_mul(&c, 4);
		axis x = ball->pos.x-c.x;
		axis y = ball->pos.y-c.y;
		if (*Dot_pos(x,y)<=Dot_BGFAN) {
			Elem elem = ball->charge & 0xFF;
			int fill = ball->charge>>8;
			if (fill>0) {
				Dot_create(x,y,elem);
				ball->charge = (fill-1)<<8 | elem;
			}
		}
	}
#elif defined UPDATE_BALL_PART
	Elem type = part->type;
	if (!ball->charge) {
		if (type==Elem_WATER||type==Elem_OIL||type==Elem_MAGMA||type==Elem_NITRO||type==Elem_GAS||type==Elem_SOAPY||type==Elem_ACID||type==Elem_SEAWATER||type==Elem_MERCURY||type==Elem_CLOUD)
			ball->Cpump.type = type;
	} else {
		if (type == ball->Cpump.type) {
			ball->Cpump.amount++;
			Dot_remove(part);
		}
	}
	if (type==Elem_MAGMA || type==Elem_LASER || type==Elem_THUNDER)
		return 1;
#endif
}
