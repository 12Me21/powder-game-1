break; case Elem_LASER:
{
#ifdef UPDATE_PART
	const Offset nears[] = {1,-WIDTH+1,-WIDTH,-WIDTH-1,-1,WIDTH-1,WIDTH,WIDTH+1};
	const Offset nearsX[] = {1,1,0,-1,-1,-1,0,1};
	const Offset nearsY[] = {0,-1,-1,-1,0,1,1,1};
	*Part_pos2(p->pos) = p;
	p->vel = (Point){0,0};
	int v = p->meta & 0xF;
	int yy = p->meta>>4 & 0xF;
	int z = p->meta>>8 & 0xFF;
	yy++;
	if (yy==1) {
		p->meta = z<<8|yy<<4|v;
		break;
	} else if (yy>12) {
		if (z/*==Elem_GLASS*/) {
			p->type = z;//Elem_GLASS;
			p->meta = 0;
			p--; //bug?
		} else
			Part_remove(p--);
		break;
	} else if (yy>8) {
		p->meta = z<<8|yy<<4|v;
		break;
	} else if (v==0) {
		// this happens if
		// laser was placed by clone or something
		// or initially when a save is loaded.
		// it tries to make the laser shoot away from adjacent walls.
		Part** at = Part_pos2(p->pos);
		bool check(int n) {
			Part* w = at[nears[n]];
			return w>=Part_0 && w->type!=Elem_LASER;
		}
		// b f c
		// g * w
		// q n r
		bool w = check(0);
		bool c = check(1);
		bool f = check(2);
		bool b = check(3);
		bool g = check(4);
		bool q = check(5);
		bool n = check(6);
		bool r = check(7);
		if (b&&g&&q) v=1;
		else if (q&&n&&r) v=3;
		else if (r&&w&&c) v=5;
		else if (c&&f&&b) v=7;
		else if (q) v=2;
		else if (r) v=4;
		else if (c) v=6;
		else if (b) v=8;
		else {
			p->meta = 0xA0|v;
			break;
		}
	}
	v--;			
	Part* near = Part_pos2(p->pos)[nears[v]];
	if (near>=Part_0) {
		switch (near->type) {
		case Elem_LASER:
			for (int b=2; b<=4; b++) {
				near = Part_pos2(p->pos)[nears[v]*b];
				if (near>=Part_0) {
					if (near->type != Elem_LASER)
						break;
				} else {
					if (near<=Part_BGFAN) {
						// todo: break if 1000 part limit
						Part* f = Part_create((int)p->pos.x+nearsX[v]*b, (int)p->pos.y+nearsY[v]*b, Elem_LASER);
						if (f)
							f->meta = v+1;
					}
					break;
				}
			}
			break;
		case Elem_METAL: case Elem_MERCURY:;
			Part** at = Part_pos2(p->pos);
			bool check(Offset n) {
				Part* c = at[n];
				return (c>=Part_0 && (c->type==Elem_METAL || c->type==Elem_MERCURY));
			}
			
			bool fl = check(nears[v+1 & 7]);
			bool l = check(nears[v+2 & 7]);
			bool bl = check(nears[v+3 & 7]);
			bool br = check(nears[v-3 & 7]);
			bool r = check(nears[v-2 & 7]);
			bool fr = check(nears[v-1 & 7]);
			bool ffl = check(nears[v]+nears[v+1 & 7]);
			bool ffr = check(nears[v]+nears[v-1 & 7]);
			if (!(v&1)) { // if not diagonal
				// bl ｌ fl ﬀl
				// :: →→ [] ::
				// br ｒ fr ﬀr
				                                      //   !!!!
				if      (br&&r&& !fl&&!l)       v+=1; //   →↗[]
				                                      // [][]  
				
					                                   // [][]  
				else if (bl&&l&& !fr&&!r)       v-=1; //   →↘[]
				                                      //   !!!!

				                                      // !!!![]
				else if (fl&&r&& !l&&!bl&&!br)  v+=3; //   →↖[]
				                                      // !![]  

	                              				     //   !!!![]
				else if (ffl&&fr&& !fl&&!l&&!r) v+=3; //   →↖[]
				                                      //   !![]

				                                      // !![]  
				else if (fr&&l&& !r&&!br&&!bl)  v-=3; //   →↙[]
				                                      // !!!![]

				                                      //   !![]
				else if (ffr&&fl&& !fr&&!r&&!l) v-=3; //   →↙[]
				                                      //   !!!![]
				
				                                      //   !!!!
				else if (r&& !fl&&!l&&!br)      v+=2; //   →↑[]
				                                      // !![]
				
				                                      // !![]
				else if (l&& !br&&!r&&!bl)      v-=2; //   →↓[]
				                                      // ??!!
				//br should've been fr
				v &= 0b111;
			} else { // diagonal
				//
				// ｇ ｂ ｆ pa
				// ｑ ➘➘ ｃ Ｙ
				// ｎ ｒ [] ｗ
				// ｅ La Ta

				// ab = r
				// Ka = c

				// ｂ bl ｌ fll
				// br ➘➘ fl lf
				// ｒ fr [] ffl 
				//frr rf ffr
				
				bool lf = check(nears[v+1 & 7]*2);
				bool rf = check(nears[v-1 & 7]*2);
				bool fll = check(nears[v+1 & 7]+nears[v+2 & 7]);
				bool frr = check(nears[v-1 & 7]+nears[v-2 & 7]);
				bool b = check(nears[v+4 & 7]);
				                                      // !!
				if      (fr&&br&& !fl&&!b)      v+=1; // []➘→!!
				                                      //   [][]
				
				                                      // !![]
				else if (fl&&bl&& !b&&!fr)      v-=1; //   ➘↓[]
				                                      //   !![]
				
				                                      //     !!
				else if (fl&&r&&fr&& !l&&!br)   v+=3; // !!➘↑[]
				                                      // [][][]

				                                        //       
				else if (ffl&&rf&& !lf&&!fl&&!fr) v+=3; //   ➘↑!!!!
				                                        //   !![][]
				                                        //   []

				                                   //       !!
				else if (lf&&fr&& !fl&&!fll) v+=3; //   ➘↑!![]
				                                   //   [][]

				                                    //   !![]
				else if (fl&&l&&fr&& !bl&&!r) v-=3; //   ➘←[]
				                                    // !![][]

						                                  //       
				else if (lf&&ffr&& !fl&&!fr&&!rf) v-=3; //   ➘←!![]
				                                        //   !![]
				                                        //   !![]

						                             //       
				else if (fl&&rf&& !fr&&!frr) v-=3; //   ➘←[]
				                                   //   !![]
				                                   // !![]

						                            //       
				else if (fr&& !fl)          v+=2; //   ➘↗!!
				                                  //   [][]

				                                  //       
				else if (fl&& !fr)          v-=2; //   ➘↙[]
				                                  //   !![]

				/*if      (br&&r&& !fl&&!l)       v+=1;
				else if (fl&&bl&& !fr&&!b)      v-=1;
				else if (r&&fr&&fl&& !l&&!br)   v+=3;
				else if (fr&&ffl&& !r&&!l&&!fl) v+=3;
				else if (r&&fl&& !l&&!ll)       v+=3;
				else if (l&&fl&&fr&& !r&&!bl)   v-=3;
				else if (fl&&ffr&& !l&&!r&&!fr) v-=3;
				else if (l&&fr&& !r&&!rr)       v-=3;
				else if (fr&& !fl)              v+=2;
				else if (fl&& !fr)              v-=2;*/

				v &= 0b111;
			}
			break;
		case Elem_POWDER: case Elem_SEED: case Elem_WOOD: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			near->meta = 0;
			break;
		case Elem_WATER: case Elem_OIL: case Elem_SOAPY: case Elem_ACID: case Elem_SALTWATER: case Elem_CLOUD:
			near->meta = near->type<<8|v+1;
			near->type = Elem_LASER;

			//near->meta = v+1;
			break;
		case Elem_GLASS:
			near->type = Elem_LASER;
			near->meta = Elem_GLASS<<8|v+1;
		}
	} else if (near<=Part_BGFAN /* && check part limit */) {
		Part* f = Part_create(p->pos.x+nearsX[v],p->pos.y+nearsY[v], Elem_LASER);
		if (f)
			f->meta = v+1;
	}
	p->meta = z<<8|yy<<4|v+1;
#endif
}
