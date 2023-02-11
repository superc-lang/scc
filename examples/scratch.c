
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{

	return 0;
}
#include <stdio.h>

typedef struct Point Point;

struct Point {
	int _x;
	int _y;
};

impl Point
{
	get int x() const => self._x;
	get int y() const => self._y;

	set int x(int x) => self._x = x;
	set int y(int y) => self._y = y;

	void test()
	{
		// int me[this] = 123;
		//callme(this._x + this._y);
		callback(this.x);
		// int this = 123;
		//return self._x + self._y;
	}
}

int main(int argc, const char *argv[])
{
	Point p[3];

	p[0].x = 20;

	printf("%d\n", p[0].x);

	return 0;
}

void test(int v, Point *p, int (*callback)())
{
	// int;
	// int me = this;
	// int me = *this;
	// int me = this[5];

	// int this;
	// int *this;
	// int this[];

	// int this = 123;
	// int *this = 123;

	// int *this = *this;
	// int this[] = this;

	// int this = &this;
	// int this = &this[4];
	// int this = this[4];

	// p->xyz = 123;
	p[2].x = 10;
	callback();
}
