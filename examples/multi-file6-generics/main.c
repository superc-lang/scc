#include <stdio.h>

#include "vec3.h"

int main(int argc, const char *argv[])
{
	//	Vec3<float>

	printf(
		"\n"
		"Vec3<float>\n"
		"-----------\n"
	);

	Vec3<float> *v1 = new Vec3<float>(1.0f, 2.0f, 3.0f);
	Vec3<float> *v2 = new Vec3<float>(4.0f, 5.0f, 6.0f);

	printf("v1 = (%f, %f, %f)\n", v1->x, v1->y, v1->z);
	printf("v2 = (%f, %f, %f)\n", v2->x, v2->y, v2->z);

	printf("Magnitude of v1 = %f\n", v1->magnitude);
	printf("Magnitude of v2 = %f\n", v2->magnitude);

	printf("v1 == v2: %s\n", v1->eq(v2) ? "true" : "false");

	v1->eq = v2;
	printf("v1 == v2: %s\n", v1->eq(v2) ? "true" : "false");

	printf("The dot product of v1 & v2: %f\n", v1->dot(v2));

	v1->normalize();
	printf("v1 normalized = (%f, %f, %f)\n", v1->x, v1->y, v1->z);

	delete v1;
	delete v2;


	//	Vec3<double>

	printf(
		"\n"
		"Vec3<double>\n"
		"-----------\n"
	);

	Vec3<double> *v3 = new Vec3<double>(1.0, 2.0, 3.0);
	Vec3<double> *v4 = new Vec3<double>(4.0, 5.0, 6.0);

	printf("v3 = (%f, %f, %f)\n", v3->x, v3->y, v3->z);
	printf("v4 = (%f, %f, %f)\n", v4->x, v4->y, v4->z);

	printf("Magnitude of v3 = %f\n", v3->magnitude);
	printf("Magnitude of v4 = %f\n", v4->magnitude);

	printf("v3 == v4: %s\n", v3->eq(v4) ? "true" : "false");

	v3->eq = v4;
	printf("v3 == v4: %s\n", v3->eq(v4) ? "true" : "false");

	printf("The dot product of v3 & v4: %f\n", v3->dot(v4));

	v3->normalize();
	printf("v3 normalized = (%f, %f, %f)\n", v3->x, v3->y, v3->z);

	delete v3;
	delete v4;


	return 0;
}
