
typedef long int size_t;

struct Vec<>;

struct Foo<T> {			//	struct IDENTIFIER '<' IDENTIFIER '>'
	Foo
		<T> *
			next;		//	NOTE: This is ALSO an IDENTIFIER!! However, now it has a GENERIC_TYPE; eg. `struct IDENTIFIER '<' GENERIC_TYPE '>'`
	Vec<T> *vec;
//	Vec<Z> vec2;
	size_t size;
	T value;
};

// typedef struct Bar<> Bar<T>;		//	ERROR: `syntax error, unexpected IDENTIFIER`

typedef struct Bar<> Bar<float>;	//	Now gets registered as a `typedef`!?!? Do we need this? I think so, we can use the location to inject struct code!
typedef struct Bar<> Bar<double>;
typedef struct Bar<> Bar<size_t>;

// CANNOT DO THIS!
//typedef struct Bar<T> Bar<T>;		//	`Bar<T>` CANNOT be a `typedef`!!!

// typedef struct Bar<T> Bar<float>;	//	struct IDENTIFIER '<' IDENTIFIER '>'
// typedef struct Bar<T> Bar<double>;	//	struct IDENTIFIER '<' IDENTIFIER '>'

/*
struct Bar<T> {				//	`Bar` == IDENTIFIER
	struct Bar<T> *next;	//	`Bar` == IDENTIFIER
	size_t size;
};
*/


int main(int argc, const char *argv[])
{
	Foo
		<float>
			foo;
	foo.size = 42;
	foo.value = 1.2f;
	return 0;
}


//	Opaque type

//struct Baz<T>;
typedef struct Baz<> Baz<Vec<Vec<float>>>;	//	NOTE: We need to write a custom lexer rule now!!!

// ...

struct Baz<T> {
	size_t size;
	T value;
};
//	NOTE: We will need to generate the struct Baz<float> { ... } code here ...
