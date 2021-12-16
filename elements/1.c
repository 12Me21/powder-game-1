#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"

AUTORUN {
	ELEMENTS[1] = (ElementDef){
		.name = "Elem_1",
		.color = RGB(0x60,0x60,0x60),
		.friction = 0.5,
	};
}
