#include <stdio.h>

typedef void(*test)();

test test1(void) {
	static void n(void) {
		puts("hello");
	}
	 return n;
}

test test2(void) {
	static void n(void) {
		puts("hello 2");
	}
	 return n;
}

void main() {
	test x = test1();
	test y = test2();
	x();
	y();
}
