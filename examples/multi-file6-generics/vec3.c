#include <stdlib.h>
#include <math.h>

#include "vec3.h"

impl source Vec3<T>
{
	Vec3<T> *new(T x, T y, T z)
	{
		Vec3<T> *v = (Vec3<T> *) malloc(sizeof(Vec3<T>));

		v->x = x;
		v->y = y;
		v->z = z;

		return v;
	}

	bool eq(Vec3<T> *other) const => this->x == other->x && this->y == other->y && this->z == other->z;

	set void eq(Vec3<T> *other)
	{
		this->x = other->x;
		this->y = other->y;
		this->z = other->z;
	}

	get T magnitude() const => (T) sqrt(this->x * this->x + this->y * this->y + this->z * this->z);

	void normalize()
	{
		T mag = this->magnitude;
		this->x /= mag;
		this->y /= mag;
		this->z /= mag;
	}

	T dot(Vec3<T> *other) const => this->x * other->x + this->y * other->y + this->z * other->z;

	void delete()
	{
		free(this);
	}
}

impl source Vec3<float>;
impl source Vec3<double>;
