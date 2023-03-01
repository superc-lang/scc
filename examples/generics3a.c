// struct Normal<T> {
// 	T value;
// };
// typedef Normal<float>;

typedef long int size_t;

//	Declare the generic type, but don't define it.
// struct Foo<T>;
// typedef Foo<float>;

typedef struct Foo<> Foo<float>;	//	Here, it's an IDENTIFIER
typedef struct Foo<> Foo<double>;	//	Here, it's an GENERIC_NAME

//typedef struct Foo<> { ... } Foo<float>;


struct Vector<T> {
	T *data;
	size_t size;
	size_t capacity;
};

//	Define the generic type.
struct Foo
			<T> {
	T
		value;

	Vector
		<T>
		vec;
};

typedef Vector<float>;

//	Define the typedef to the generic type.
//	This is where the final name is generated and the type is expanded based on the generic definition!
struct Foo<float>;

// typedef Foo<float>;
// typedef Foo<double>;

int main(int argc, const char *argv[])
{
	Foo<float> foo;
}
