break; case Elem_LASER:
{
#ifdef UPDATE_PART
	// these tables are for converting an angle (0-7) to x/y offsets
	const Offset nears[] = {1,-WIDTH+1,-WIDTH,-WIDTH-1,-1,WIDTH-1,WIDTH,WIDTH+1};
	const axis nearsX[] = {1,1,0,-1,-1,-1,0,1};
	const axis nearsY[] = {0,-1,-1,-1,0,1,1,1};
	// 3 2 1
	// 4 * 0
	// 5 6 7

	Dot_toGrid(p);
	p->vel = (Point){0,0};
	int v = p->Claser.dir; // this is a number 1-8, or 0 if the laser has no direction.
	int age = p->Claser.age;
	age++;
	if (age==1) { // do nothing on first frame
		p->Claser.age = age;
		break;
	} else if (age>12) { // remove old laser
		if (p->Claser.inside==Elem_GLASS) {
			p->type = Elem_GLASS;
			p->charge = 0;
			p--; //bug?
			break;
		} else
			Dot_KILL();
	} else if (age>8) { // also do nothing
		p->Claser.age = age;
		break;
	}
	// laser's age is 2 - 8

	// if the laser's direction is 0:
	if (v==0) {
		// this happens if
		// laser was placed by clone or something
		// or initially when a save is loaded.
		// it tries to make the laser shoot away from adjacent walls.
		Dot** at = Dot_pos2(p->pos);
		inline bool check(int n) {
			Dot* w = at[nears[n]];
			return w>=Dot_0 && w->type!=Elem_LASER;
		}
		bool ne = check(1);
		bool nw = check(3);
		bool sw = check(5);
		bool se = check(7);
		if (nw && sw && check(4)) v=1; // northeast
		else if (sw && se && check(6)) v=3; // northwest
		else if (se && ne && check(0)) v=5; // southwest 
		else if (ne && nw && check(2)) v=7; // southeast
		else if (sw) v=2; // up
		else if (se) v=4; // left
		else if (ne) v=6; // down
		else if (nw) v=8; // right
		else {
			p->Claser.inside = 0;
			p->Claser.age = 10;
			p->Claser.dir = 0;
			break;
		}
	}
	
	v--; // convert direction from 1-8 to 0-7
	// check part in front of the laser
	Dot* near = Dot_pos2(p->pos)[nears[v]]; 
	if (near>=Dot_0) {
		switch (near->type) {

			// burn flammable elements:
		case Elem_POWDER: case Elem_SEED: case Elem_WOOD: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			near->charge = 0;
			break;

			// destroy liquids:
		case Elem_WATER: case Elem_OIL: case Elem_SOAPY: case Elem_ACID: case Elem_SEAWATER: case Elem_CLOUD:
			near->type = Elem_LASER;
			near->charge = 0;
			near->Claser.dir = v+1;
			break;

			// pass through glass:
		case Elem_GLASS:
			near->type = Elem_LASER;
			near->charge = 0;
			near->Claser.dir = v+1;
			near->Claser.inside = Elem_GLASS;
			break;
			
			// pass through laser:
		case Elem_LASER:
			// [→p→] [near] [ 2 ] [ 3 ] [ 4 ]
			for (int dist=2; dist<=4; dist++) {
				near = Dot_pos2(p->pos)[nears[v]*dist];
				if (near<=Dot_BGFAN) {
					if (!Dot_limit1000())
						break;
					Dot* f = Dot_create(
						(int)p->pos.x+nearsX[v]*dist,
						(int)p->pos.y+nearsY[v]*dist,
						Elem_LASER
					);
					if (f)
						f->Claser.dir = v+1;
				} else if (near>=Dot_0 && near->type==Elem_LASER)
					// if there is laser particle, we keep checking
					continue;
				break; // otherwise,
			}
			break;

			// laser reflects off of metal/mercury:
		case Elem_METAL: case Elem_MERCURY:;
			// this is big and complicated
			Dot** at = Dot_pos2(p->pos);
			inline bool check(Offset n) {
				Dot* c = at[n];
				return (c>=Dot_0 && (c->type==Elem_METAL || c->type==Elem_MERCURY));
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

				// BUG!!
				// br should've been fr here:
				                                      // !![]
				else if (l&& !br&&!r&&!bl)      v-=2; //   →↓[]
				                                      // ??!!
				v &= 0b111;
			} else { // diagonal
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
				v &= 0b111;
			}
			break;
		}
	} else if (near<=Dot_BGFAN && Dot_limit1000()) {
		Dot* f = Dot_create(
			p->pos.x+nearsX[v],
			p->pos.y+nearsY[v],
			Elem_LASER
		);
		if (f)
			f->Claser.dir = v+1;
	}
	p->Claser.age = age;
	p->Claser.dir = v+1;
#endif
}
