srcs:= elements input main part vector draw menu save bg entity platform-x11 render-dot render-menu scale render-entity ball render-ball
output:= pg1

libs:= X11 m Xpm

CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -O3

include .Nice.mk

fast: $(srcs:%=%.c)
	gcc $(CFLAGS) $(addprefix -l,$(libs)) $^ -o $(output)
