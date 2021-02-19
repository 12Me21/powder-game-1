srcs:= elements input main part vector draw menu save bg entity
output:= pg1

libs:= X11 m

CFLAGS+= -Wextra -Wall -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Werror=implicit-function-declaration -g -ftabstop=3 -Wno-missing-field-initializers -Wno-char-subscripts

include .Nice.mk
