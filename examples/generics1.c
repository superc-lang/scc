struct vec3<T> {
	T x;
	T y;
	T z;
};

struct vec3<float> v1;
struct vec3<double> v2;

impl vec3<T>
{
	get T x() => self.x;
	get T y() => self.y;
	get T z() => self.z;

	set T x(T value) => self.x = value;
	set T y(T value) => self.y = value;
	set T z(T value) => self.z = value;

	T length() => sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
}


typedef struct vec3__float {
	float x;
	float y;
	float z;
} vec3__float;

static float vec3__get__x__float(vec3__float *self) => self->x;
static double vec3__get__x__double(vec3__double *self) => self->x;

impl vec3<float>
{
	float length() => sqrtf(self.x * self.x + self.y * self.y + self.z * self.z);
}

impl vec3<double>
{
	double length() => sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
}

// Path: examples/generics2.c

// Compare this snippet from output.i:
// typedef struct vec3  vec3;
//
// static float vec3__get__x(vec3 *);
//
// static float vec3__get__y(vec3 *);
//
// static float vec3__get__z(vec3 *);

// static float vec3__set__x(vec3 *self, float value)



