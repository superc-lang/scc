#include "circle.h"

impl Circle
{
	Circle *new(int x, int y, int width, int height)
	{
		Circle *self = (Circle*) malloc(sizeof(Circle));

		self->x = x;
		self->y = y;
		self->radius = radius;

		return self;
	}

	void delete();
}

impl Circle implements Shape
{
	void draw()
	{
		printf("Drawing a circle at (%d, %d) with radius %d\n", self->x, self->y, self->radius);
	}

	void move(int x, int y)
	{
		self->x = x;
		self->y = y;
	}
}

/**
Generated Code
==============

Shape__trait Circle__Shape = {
	.draw = (void (*)(void*)) Circle__draw,
	.move = (void (*)(void*, int x, int y)) Circle__move,
};
*/
