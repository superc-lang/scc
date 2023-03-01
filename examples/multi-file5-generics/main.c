#include <stdio.h>

#include "vec3f.h"

// impl Vec3<float>;
// impl decl Vec3<float>;



// NOT implemented yet!
// impl Vec3<float>
// {
	// Vec3(float x, float y, float z)
	// {
	// 	this->x = x;
	// 	this->y = y;
	// 	this->z = z;
	// }
// }



/*
typedef struct Vec3<float> Vec3<float>;

Generated Code
==============

typedef struct Vec3__float {
	float x;
	float y;
	float z;
} Vec3__float;
*/

int main(int argc, const char *argv[])
{
	Vec3<float>	*vec3f = new Vec3<float>(0, 0, 0);

	printf("X: %f\n", vec3f->x);
	printf("Y: %f\n", vec3f->y);
	printf("Z: %f\n", vec3f->z);

	delete vec3f;

	Vec3<float> *v2 = vec3f->get_self;
	v2 = vec3f->get_self;

	Vec3<float> *v3;
	v3 = vec3f->ret_me();


	return 0;
}

// typedef struct Vec3f {
// 	float x;
// 	float y;
// 	float z;
// //	void (*delete)(Vec3f *self);
// } Vec3f;
