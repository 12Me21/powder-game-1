srcs:= elements input main part vector draw menu save bg entity platform-windows render-dot render-menu scale render-entity ball render-ball
output:= pg1.exe
libs:= winmm dwmapi

CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -s -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -O3

include .Nice.mk

fast: $(srcs:%=../%.c)
	i686-w64-mingw32-gcc $(CFLAGS) -mwindows $^ -o $(output) $(addprefix -l,$(libs))
