srcs:= elements input main part vector draw menu save bg entity platform-x11 render-dot render-menu render-entity ball render-ball cell wheel wheel-frames font bubble reset
output:= pg1

libs:= X11 m Xpm

CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -Wno-parentheses -Werror=incompatible-pointer-types -Wdouble-promotion

# this is VERY IMPORTANT!
# causes number literals to be treated as float instead of double
CFLAGS+= -fsingle-precision-constant

include .Nice.mk

optimized: $(srcs:%=%.c)
	gcc $(CFLAGS) -O3 $(addprefix -l,$(libs)) $^ -o $(output)-fast
