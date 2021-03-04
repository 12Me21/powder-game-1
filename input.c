#include <stdbool.h>
#include <stdio.h>
#include "input.h"
#include "menu.h"
#include "common.h"

// todo:
// we need to buffer mouse clicks,
// so that a click which starts and end within one frame
// is still counted

ButtonState Keys[256] = {
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //0-12
	{13,13},{0},{0},{0}, // 13-15
	{16,16},{17,17},{18,18}, //16-18
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //19-31
	// todo: finish
};



MouseState mouse = {0};

bool Mouse_risingClick;
int Mouse_fallingDirection;



extern int Pen_oldx, Pen_oldy;

void Input_update2(void) {
	for(int i=0;i<3;i++) {
		mouse.buttons[i].gotPress = false;
		mouse.buttons[i].gotRelease = false;
		mouse.buttons[i].wasHeld = mouse.buttons[i].held;
	}
	mouse.olderPos = mouse.oldPos;
	mouse.oldPos = mouse.pos;
	for (int i=0;i<256;i++) {
		Keys[i].gotPress = false;
		Keys[i].gotRelease = false;
		Keys[i].wasHeld = Keys[i].held;
	}
}

void Input_update(void) {
	for(int i=0;i<3;i++) {
		mouse.buttons[i].held = mouse.buttons[i].heldNow || mouse.buttons[i].gotPress;
	}
	for (int i=0;i<256;i++) {
		Keys[i].held = Keys[i].heldNow || Keys[i].gotPress;
	}
	
	Mouse_risingClick = !(mouse.left.held||mouse.right.held);
	Mouse_fallingDirection = mouse.left.gotRelease ? 1 : mouse.right.gotRelease ? -1 : 0;
}
