#include "trait.h"

typedef struct Circle {
	int x;
	int y;
	float radius;
} Circle;

impl Circle
{
	Circle *new(int x, int y, float radius);
	void delete();
}

impl Circle implements Shape;

/**
Generated Code
==============

extern Shape__trait Circle__Shape;
*/
