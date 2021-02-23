break; case Elem_FAN:
{
#ifdef UPDATE_PART
	Vec_add(&c->vel, &p->vel);
	if (Part_at[(int)p->pos.y][(int)p->pos.x] == Part_EMPTY)
		Part_at[(int)p->pos.y][(int)p->pos.x] = Part_BGFAN;
#endif
}
