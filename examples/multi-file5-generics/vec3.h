#pragma once

#include <stdlib.h>

struct Vec3<T>
{
	T x;
	T y;
	T z;
};

//	NOTE: This declaration is not (normally) meant to be used in `.c` files!
//	It's used as a `template` to make the 'concrete' implementation of the generic type!

//	impl header Vec3<T>
//	impl source Vec3<T>

//	impl <label> Vec3<T>

//	impl header Vec3<float>;
//	impl source Vec3<float>;

//	impl static Vec3<float>;

impl header Vec3<T>
{
	Vec3<T> *new(T x, T y, T z);

	get Vec3<T> *get_self();
	set Vec3<T> *set_self(T x);
	Vec3<T> *ret_me();

	void delete();
}

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

	get Vec3<T> *get_self() => self;
	set Vec3<T> *set_self(T x) { self->x = x; return self; }
	Vec3<T> *ret_me() => self;

	void delete()
	{
		free(this);
	}
}
