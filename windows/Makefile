srcs:= elements input main part vector draw menu save bg entity platform-windows render-dot render-menu render-entity ball render-ball cell wheel wheel-frames font bubble
output:= pg1.exe
libs:= winmm dwmapi

CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts

include .Nice.mk

fast: $(srcs:%=../%.c)
	i686-w64-mingw32-gcc $(CFLAGS) -O2 -mwindows $^ -o $(output) $(addprefix -l,$(libs))
