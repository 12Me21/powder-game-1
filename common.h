#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef float real;
typedef _Complex float Complex;
#define fabs(x) __builtin_fabsf(x)
#define floor(x) __builtin_floorf(x)
#define ceil(x) __builtin_ceilf(x)
#define acos(x) __builtin_acosf(x)
#define sin(x) __builtin_sinf(x)
#define cos(x) __builtin_cosf(x)
#define sqrt(x) __builtin_sqrtf(x)
#define abs(x) __builtin_abs(x)
#define memmove __builtin_memmove
#define strlen __builtin_strlen
#define memcpy __builtin_memcpy
#define memset __builtin_memset
#define memcmp __builtin_memcmp

#define export(name) __attribute__((export_name(name)))

#define LEN(a) (sizeof(a)/sizeof((a)[0]))

typedef union Color {
	struct {	uint8_t r,g,b,a; };
	uint32_t c;
} Color;

#define RGB(r,g,b) (Color){r,g,b,255}

/*#define RED(x) (int)((x)>>16&0xFF)
#define GREEN(x) (int)((x)>>8&0xFF)
#define BLUE(x) (int)((x)&0xFF)
#define RGB(r,g,b) ((r)<<16|(g)<<8|(b))*/

typedef int32_t axis; // could probably be 16bit but we want axis*width+axis to be 32bit so i make this 32bit just in case
typedef int32_t Offset; 
typedef int8_t Elem; // this has to be like, 0-100 ish, and a few negatives. -128 to 127 is a good range.

//#define SWITCH(cond) switch(cond) {
//#define CASE break; case
//#define OR : case
//#define DEFAULT break; default:
//#define OR_DEFAULT : default

#define when(x) break;case x
#define orwhen : case
#define otherwise break;default
//#define forRange(var, start, cond, step) for(var start; var cond; var step)

// size of visible area
#define W 400
#define H 300

// size of physics area and framebuffer
// h
#define WIDTH (8+W+8)
#define HEIGHT (8+H+8)

#define MENU_HEIGHT 156
#define MENU_WIDTH W

// height of window (smaller for some reason)
// (framebuffer is offset by -8, -8)
#define WINDOW_WIDTH (W)
#define WINDOW_HEIGHT (H+MENU_HEIGHT)

#define AUTORUN __attribute__((constructor)) static void init_##__LINE__(void)

//#define LAMBDA(type, def) ({ type _temp def; _temp; })

#define sign(x) ({__auto_type z = (x); (z>0)-(z<0); })
#define atMost(x,lim) ({__auto_type z = (x); __auto_type a = (lim); if (z>a) z=a; z; })
#define atLeast(x,lim) ({__auto_type z = (x); __auto_type a = (lim); if (z<a) z=a; z; })
#define between(x,a,b) ({__auto_type z = (x); if (z<a) z=a; else if (z>b) z=b; z; })
