elems = 0 1 9 powder water fire seed wood gunpowder fan ice snow steam superball clone fireworks oil c4 18 stone
srcs := $(elems:%=elements/%.c)

srcs += elements.c input.c main.c dot.c vector.c render/draw.c menu.c save.c render/bg.c object.c render/dot.c render/menu.c render/object.c ball.c render/ball.c block.c wheel.c wheel-frames.c font.c bubble.c reset.c render/scale.c menu-input.c render/bubble.c render/wheel.c random.c

CC:= clang
CFLAGS = --target=wasm32 -O3 -fno-builtin
LDFLAGS+= --target=wasm32 -nostdlib -Wl,--no-entry,--export-all,-z,stack-size=5000000

libs:= X11 Xpm
srcs+= platform-x11.c
output:= pg1

ifdef opt
 junkdir:= $(junkdir)/optimized
 output:= fast-$(output)
 LDFLAGS+= -flto
 CFLAGS+= -O3 -flto
endif

# enable/disable tons of warnings
CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -Wno-parentheses -Werror=incompatible-pointer-types -Wdouble-promotion -Wno-missing-braces -Wint-conversion -Wno-sign-compare
CFLAGS += -Werror=double-promotion

include .Nice.mk
