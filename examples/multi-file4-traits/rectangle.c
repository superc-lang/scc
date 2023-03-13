#include "rectangle.h"

impl Rectangle
{
	Rectangle *new(int x, int y, int width, int height)
	{
		Rectangle *self = (Rectangle*) malloc(sizeof(Rectangle));
		if (self == NULL)
			return NULL;
		
		self->x = x;
		self->y = y;
		self->width = width;
		self->height = height;

		return self;
	}

	void delete()
	{
		free(self);
	}
}
