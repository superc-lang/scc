// Check the output on Godbolt!
// https://godbolt.org/z/onodhYKhh

// For the purposes of our examples, we don't need the `include` files yet.
// If you want to actually compile this example with GCC or your compiler, you'll need to add them!

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// NB: Remember to compile with -lm flag to link with math library!

typedef struct {
	int x;
	int y;
} Point;

impl Point
{
	Point *new(int x, int y)
	{
		Point *p = (Point *) malloc(sizeof(Point));

		p->x = x;
		p->y = y;

		return p;
	}

	float distance(Point *p2)
	{
		int dx = this->x - p2->x;
		int dy = this->y - p2->y;

		return sqrt(dx * dx + dy * dy);
	}

	float angle(Point *p2) => atan2(p2->y - this->y, p2->x - this->x);

	get float magnitude() => sqrt(this->x * this->x + this->y * this->y);

	void delete()
	{
		free(this);
	}
}

int main(int argc, char *argv[])
{
	Point *p1 = new Point(0, 0);
	Point *p2 = new Point(3, 4);

	printf("Distance between p1 and p2: %f\n", p1->distance(p2));

	printf("Angle between p1 and p2: %f\n", p1->angle(p2));

	printf("magnitude of p1: %f\n", p1->magnitude);
	printf("magnitude of p2: %f\n", p2->magnitude);

	delete p1;
	delete p2;

	return 0;
}
