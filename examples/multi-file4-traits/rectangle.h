#include "trait.h"

typedef struct Rectangle {
	int x;
	int y;
	int width;
	int height;
} Rectangle;

impl Rectangle
{
	Rectangle *new(int x, int y, int width, int height);
	void delete();
}
