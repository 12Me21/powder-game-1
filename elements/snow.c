#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"
//❄
static bool dot(Dot* p, Block* c) {
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.08);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	
	Dot* near = Dot_rndNear(p->pos, 3);
	if (near>=Dot_0) {
		Elem type = near->type;
		if (type == Elem_ICE)
			p->type = Elem_ICE;
		// melt on contact with elements except for:
		// wood, wheel, snow, clone, vine, cloud
		// wait how could the type ever be wheel?
		else if (type!=Elem_WOOD && type!=Elem_WHEEL && type!=Elem_SNOW && type!=Elem_SNOW && type!=Elem_CLONE && type!=Elem_VINE && type!=Elem_CLOUD)
			p->type = Elem_WATER;
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_SNOW] = (ElementDef){
		"SNOW", RGB(255,255,255), State_POWDER,
		
		.playerValid = true,
		.temperature = -500,
		.dissolveRate = 10,
		.friction = 0.5,
		.ze = 0.2, .Ae = 0.2,
		// unused values, since snow balls don't exist:
		.ballWeight = 0.02,
		.ballAdvection = 0.5,
		
		.wheelWeight = 1,
		
		.update_dot = dot,
	};
}
