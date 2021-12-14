elems = 0 1 9 powder water fire seed wood gunpowder fan ice snow steam superball clone fireworks oil c4 18 stone
srcs := $(elems:%=elements/%.c)

srcs += elements.c input.c main.c dot.c vector.c render/draw.c menu.c save.c render/bg.c object.c render/dot.c render/menu.c render/object.c ball.c render/ball.c block.c wheel.c wheel-frames.c font.c bubble.c reset.c render/scale.c menu-input.c render/bubble.c render/wheel.c random.c

# this is VERY IMPORTANT!
# causes number literals to be treated as float instead of double
# CFLAGS+= -fsingle-precision-constant
CFLAGS += -Werror=double-promotion

CC:= clang
libs:= X11 m Xpm
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

include .Nice.mk
