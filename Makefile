srcs:= elements input main part vector draw menu save bg entity render-dot render-menu render-entity ball render-ball cell wheel wheel-frames font bubble reset scale menu-input

ifdef WINDOWS
 gcc:= i686-w64-mingw32-gcc
 LDFLAGS+= -mwindows
 junkdir:= .junk/windows
 libs:= winmm dwmapi
 srcs+= platform-windows
 output:= pg1.exe
else
 libs:= X11 m Xpm
 srcs+= platform-x11
 output:= pg1
endif

# enable/disable tons of warnings
CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -Wno-parentheses -Werror=incompatible-pointer-types -Wdouble-promotion -Wno-missing-braces -Wint-conversion

# this is VERY IMPORTANT!
# causes number literals to be treated as float instead of double
CFLAGS+= -fsingle-precision-constant

include .Nice.mk

optimized: fast-$(output)
