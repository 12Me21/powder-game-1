srcs:= elements input main dot vector render/draw menu save render/bg object render/dot render/menu render/object ball render/ball block wheel wheel-frames font bubble reset render/scale menu-input render/bubble render/wheel random

# this is VERY IMPORTANT!
# causes number literals to be treated as float instead of double
CFLAGS+= -fsingle-precision-constant

#CFLAGS+= -mx32
#LDFLAGS+= -mx32

#gch:= precompile.h

ifdef win
 CC:= i686-w64-mingw32-gcc
 LDFLAGS+= -mwindows
 junkdir:= windows
 libs:= winmm dwmapi
 srcs+= platform-windows
 output:= pg1.exe
else
 CC:= gcc
 junkdir:= linux
 libs:= X11 m Xpm
 srcs+= platform-x11
 output:= pg1
endif

ifdef opt
 junkdir:= $(junkdir)/optimized
 output:= fast-$(output)
 LDFLAGS+= -flto
 CFLAGS+= -O3 -flto
endif

# enable/disable tons of warnings
CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts -Wno-parentheses -Werror=incompatible-pointer-types -Wdouble-promotion -Wno-missing-braces -Wint-conversion -Wno-sign-compare

include .Nice.mk
