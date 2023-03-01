#pragma once

struct Vec3<T>
{
	T x;
	T y;
	T z;
};

// typedef struct Vec3<float> Vec3<float>;
// typedef struct Vec3<double> Vec3<double>;

typedef Vec3<float>;
typedef Vec3<double>;

impl header Vec3<T>
{
	Vec3<T> *new(T x, T y, T z);

	bool eq(Vec3<T> *other) const;
	set void eq(Vec3<T> *other);
	get T magnitude() const;
	void normalize();
	T dot(Vec3<T> *other) const;

	void delete();
}

impl header Vec3<float>;
impl header Vec3<double>;
