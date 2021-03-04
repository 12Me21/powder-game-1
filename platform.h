#pragma once
#include <stdio.h>

long Platform_millisec(void);
void Platform_main(int argc, void** argv);
FILE* Platform_fopen(const void* name);
