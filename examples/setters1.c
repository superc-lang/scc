#include <stdio.h>

typedef struct S {
	int _x;
	int _y;
} S;

impl S
{
	get static inline int x() => self._x;
	get static inline int y() => self._y;

	set static inline int x(int value) { self._x = value; return value; }
	set static inline int y(int value) { self._y = value; return value; }
}

int main(int argc, const char *argv[])
{
	S s;
	s.x = 10;
	s.y = 20;
	printf("s.x = %d, s.y = %d\n", s.x, s.y);

	S *p = &s;
	p->x = 40;
	p->y = 50;
	printf("p->x = %d, p->y = %d\n", p->x, p->y);

	p->x = 10 + (p->y = 80);		// GCC ERROR: `error: void value not ignored as it ought to be` ... `p->y` is a `setter` that doesn't return a value!
	printf("p->x = %d, p->y = %d\n", p->x, p->y);

	return 0;
}
