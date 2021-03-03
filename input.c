#include <stdbool.h>
#include <stdio.h>
#include "input.h"
#include "menu.h"
#include "common.h"


Key Keys[256] = {
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //0-12
	{13,13},{0},{0},{0}, // 13-15
	{16,16},{17,17},{18,18}, //16-18
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //19-31
	// todo: finish
};



MouseState Mouse_now;
MouseState Mouse_old;
MouseState Mouse_older;
// ignore the x/y on these
MouseState Mouse_rising;
MouseState Mouse_falling;

bool Mouse_risingClick;
int Mouse_fallingDirection;



int Platform_mouseX, Platform_mouseY;
int Platform_mouseLeft, Platform_mouseRight, Platform_mouseMiddle;
bool Platform_keys[256]; //todo: this won't capture keypresses that start+end within 1 frame

extern int Pen_oldx, Pen_oldy;

void Input_update(void) {
	//Pen_oldx = Pen_x;
	//Pen_oldy = Pen_y;
	//Pen_x = Mouse_now.x;
	//Pen_y = Mouse_now.y;
	Mouse_rising.left = !Mouse_old.left && Mouse_now.left;
	Mouse_falling.left = Mouse_old.left && !Mouse_now.left;
	Mouse_rising.right = !Mouse_old.right && Mouse_now.right;
	Mouse_falling.right = Mouse_old.right && !Mouse_now.right;
	Mouse_older = Mouse_old;
	Mouse_old = Mouse_now;
	
	Mouse_now.x = Platform_mouseX;
	Mouse_now.y = Platform_mouseY;
	Mouse_now.left = Platform_mouseLeft;
	Mouse_now.right = Platform_mouseRight;
	Mouse_now.middle = Platform_mouseMiddle;
	
	Mouse_risingClick = !(Mouse_falling.left||Mouse_old.left||Mouse_falling.right||Mouse_old.right);
	Mouse_fallingDirection = Mouse_falling.left ? 1 : Mouse_falling.right ? -1 : 0;

	//var a,d,b,c=new Vector,e=new Vector,f=new Vector;
	//if (!Menu_cursorInMenu /*&& wa==0*/) {
	//Pen_x=clamp(Mouse_old.x+2*4,2*4,4*((W+8)/4)-1);
	//Pen_y=clamp(Mouse_old.y+2*4,2*4,4*((H+8)/4)-1);
		//}
		/*	if (Menu_zoomLevel>0) {
			Pen_x = 2*H+floor(Menu_zoomX)+(Mouse_old.x>>Menu_zoomLevel);
			Pen_y = 2*H+floor(Menu_zoomY)+(Mouse_old.y>>Menu_zoomLevel);
			Pen_x = clamp(pen_x,2*4,4*(104-2)-1);
			Pen_y = clamp(pen_y,2*4,4*(79-2)-1);
		}
		if (Menu_penMode==Pen_LINE) {
			if (Mouse_rising.left||Mouse_rising.right) {
				penlinestartx = Pen_x;
				penlinestarty = Pen_y;
			} else if (Mouse_falling.left||Mouse_falling.right) {
				sd = penlinestartx;
				td = penlinestarty;
			}
		} else if(Menu_penMode==P_LOCK) {
			if (Mouse_rising.left||Mouse_rising.right) {
				penlockmode=0;
			} else if (Mouse_old.left||Mouse_old.right) {
				if(penlockmode==0){
					if(abs(pen_x-sd)>abs(pen_y-td)){
						penlockmode=1;
					}else if(abs(pen_x-sd)<abs(pen_y-td)){
						penlockmode=2;
					}
				}
			}else if(mouse.falling.left||mouse.falling.right){
				penlockmode=0;
			}
			if(penlockmode==1){
				pen_y=td;
			}else if(penlockmode==2){
				pen_x=sd;
			}
		}
		c.set(pen_x,pen_y);
		pen_dir.set(sd-5*pen_dir.x,td-5*pen_dir.y);
		var q=5;
		d=a=0.5;
		ee.sub2(c,pen_dir);
		q-=ee.fastnormalize();
		a*=q;
		d*=q;
		c.x+=ee.x*a;
		c.y+=ee.y*a;
		pen_dir.x-=ee.x*d;
		pen_dir.y-=ee.y*d;
		pen_dir.sub2(c,pen_dir);
		pen_dir.fastnormalize();
		mouse_stuff(0);
		mouse_stuff(1);
		if(Menu_zoomLevel!=0&&mouse.middle){
			zoomx-=(mouse.old.x-mouse.older.x)/(1<<Menu_zoomLevel);
			zoomy-=(mouse.old.y-mouse.older.y)/(1<<Menu_zoomLevel);
			zoomx=clamp(zoomx,0,400-(400>>Menu_zoomLevel));
			zoomy=clamp(zoomy,0,300-[300,150,75,38,19][Menu_zoomLevel]);
		}
		if(mouse.rising.left||mouse.rising.right){
			carefullycreated=clamp(carefullycreated+1,0,4095);
		}
	}
	g=[1,2,4,8];
	for(q=0;q<g[Menu_gameSpeed];q++){
		var opencells=0
		for(a=0;a<Air_CELLS;a++){
			if(blocks[a]==0){
				opencells++;
			}
		}
		if(opencells>0){
			pd/=opencells;
			for(a=0;a<Air_CELLS;a++){
				if(blocks[a]==0){
					Air.pres[a]+=pd;
				}
			}
			pd=0;
		}
		if(Menu_paused&&!(risingmouseclick&&wa==0&&Keys.rising[10]|Keys.rising[13])){
			break;
		}
		for(a=0;a<Air_CELLS;a++){
			Air.vel2[a].copy(Air.vel[a]);
		}
		a=2*G+2;
		for(b=2;b<kd-2;b++,a+=4){
			for(d=2;d<G-2;d++,a++){
				if(blocks[a]!=1){
					c.copy(Air.vel[a]);
					var n=c.fastnormalize();
					if(n!=0){
						var r=abs(c.x),w=abs(c.y),y=r/(r+w)*n*0.5,n=w/(r+w)*n*0.5;
						e.mul2(c,y);
						f.mul2(c,n);
						var z=c.x<0?-1:1,v=c.y<0?-G:G;
						if(r>w){
							if(blocks[a+z]<=0){
								Air.vel2[a].sub(e);
								Air.vel2[a+z].add(e);
								Air.pres[a+z]+=y;
								Air.pres[a]-=y;
							}else{
								Air.vel2[a].sub(e);
								Air.vel2[a].sub(e);
							}
							if(blocks[a+z+v]<=0){
								Air.vel2[a].sub(f);
								Air.vel2[a+z+v].add(f);
								Air.pres[a]-=n;
								Air.pres[a+z+v]+=n;
							}else{
								Air.vel2[a].sub(f);
								Air.vel2[a].sub(f);
							}
						}else{
							if(blocks[a+v]<=0){
								Air.vel2[a].sub(f);
								Air.vel2[a+v].add(f);
								Air.pres[a]-=n;
								Air.pres[a+v]+=n;
							}else{
								Air.vel2[a].sub(f);
								Air.vel2[a].sub(f);
							}
							if(blocks[a+v+z]<=0){
								Air.vel2[a].sub(e);
								Air.vel2[a+v+z].add(e);
								Air.pres[a]-=y;
								Air.pres[a+v+z]+=y;
							}else{
								Air.vel2[a].sub(e);
								Air.vel2[a].sub(e);
							}
						}
					}
				}
			}
		}
		for(a=0;a<Air_CELLS;a++){
			Air.pres2[a]=Air.pres[a];
		}
		a=2*G+2;
		r=-1-G;
		w=1-G;
		y=-1+G;
		n=1+G;
		for(b=2;b<kd-2;b++,a+=4){
			for(d=2;d<G-2;d++,a++){
				if(blocks[a]!=1){
					if(blocks[a-1]<=0){
						Air.vel2[a].x-=0.0625*(Air.pres[a]-Air.pres[a-1]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a-1]);
					}
					if(blocks[a+1]<=0){
						Air.vel2[a].x+=0.0625*(Air.pres[a]-Air.pres[a+1]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a+1]);
					}
					if(blocks[a-G]<=0){
						Air.vel2[a].y-=0.0625*(Air.pres[a]-Air.pres[a-G]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a-G]);
					}
					if(blocks[a+G]<=0){
						Air.vel2[a].y+=0.0625*(Air.pres[a]-Air.pres[a+G]);
						Air.pres2[a]-=0.0625*(Air.pres[a]-Air.pres[a+G]);
					}
					if(blocks[a+r]<=0){
						Air.vel2[a].x-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
						Air.vel2[a].y-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+r]);
					}
					if(blocks[a+w]<=0){
						Air.vel2[a].x+=0.044194173*(Air.pres[a]-Air.pres[a+w]);
						Air.vel2[a].y-=0.044194173*(Air.pres[a]-Air.pres[a+w]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+w]);
					}
					if(blocks[a+y]<=0){
						Air.vel2[a].x-=0.044194173*(Air.pres[a]-Air.pres[a+y]);
						Air.vel2[a].y+=0.044194173*(Air.pres[a]-Air.pres[a+y]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+y]);
					}
					if(blocks[a+n]<=0){
						Air.vel2[a].x+=0.044194173*(Air.pres[a]-Air.pres[a+n]);
						Air.vel2[a].y+=0.044194173*(Air.pres[a]-Air.pres[a+n]);
						Air.pres2[a]-=0.044194173*(Air.pres[a]-Air.pres[a+n]);
					}
				}
			}
		}
		for(a=0;a<Air_CELLS;a++){
			if(blocks[a]!=-1){
				Air.vel[a].copy(Air.vel2[a]);
				Air.pres[a]=Air.pres2[a];
			}else{
				Air.pres[a]=0;
		p		Air.vel[a].set(0,0);
			}
		}
		this.Parts_update();
		this.Wheels_update();
		this.Bubbles_update();
		this.Entities_update();
		this.Balls_update();
	}
	//	*/
	int i;
	for (i=0;i<256;i++) {
		Keys[i].pressed = Platform_keys[i];
		Keys[i].rising = Platform_keys[i];//Keys[i].rising1;
		Keys[i].rising1 = false;
	}
}
