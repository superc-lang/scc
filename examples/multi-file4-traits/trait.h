#pragma once

trait Shape
{
	void draw();
	void move(int x, int y);
}

/*
Generated Code
==============

typedef struct Shape__trait {
	void (*draw)(void *);
	void (*move)(void *, int x, int y);
} Shape__trait;
*/
