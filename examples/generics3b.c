
typedef long int size_t, size_z;

struct Test;
typedef struct Test Test;
typedef struct Test Test2;

struct Test {
	int value;
};

typedef struct Foo<>
	Foo<float>,
	Foo<double>;




//	Example 1
//	Standard Generic Type
typedef struct {
	T x, y, z;
} Foo<T>;						//	WRONG! We don't create a `typedef` of type `Foo<T>`!

typedef Foo<T> Foo<float>;		//	WRONG! We MUST declare `struct Foo<T>` first!
typedef Foo<T> Foo<double>;



//	Example 2
typedef struct {
	Vec<T> vec;
	size_t size;
} Foo<T>;


//	Example 3
typedef struct Foo<T> {
	struct Foo<T> *next;
	size_t size;
} Foo<T>;


//	Example 4
typedef struct Foo<T> {
	Foo<T> *next;
	size_t size;
} Foo<T>;


typedef struct Foo<> Foo<T>;
struct Foo<T> {
	Foo<T> *next;
	size_t size;
};


//	Example 4
//	Opaque Generic Type
typedef struct Bar<> Bar<T>;
struct Bar<T> {
	Bar<T> *next;
	size_t size;
};


//-----------------------------------------------------------------------------

typedef struct Bar<T> {
	struct Bar<T> *next;
	size_t size;
} Bar<T>;					//	WRONG! We don't create a `typedef` of type `Bar<T>`!

typedef Bar<T> Bar<float>;
/*
```
typedef struct Bar<T> {
	struct Bar<T> *next;
	size_t size;
} Bar<T>;

typedef Bar<T> Bar<float>;
```
*/


//-----------------------------------------------------------------------------

typedef struct Bar<T> {
	struct Bar<T> *next;
	size_t size;
} Bar<T>;					//	WRONG!

typedef Bar<T> Bar<float>;	//	This is essentially like another opaque type!
/*
```
typedef struct Bar__float {
	struct Bar__float *next;
	size_t size;
} Bar__float;
```
*/
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

struct Bar<T> {				//	`Bar` is currently an IDENTIFIER then gets registered as generic type.
	struct Bar<T> *next;	//	NOTE: This is ALSO an IDENTIFIER!!
	size_t size;
};

// CANNOT DO THIS!
typedef struct Bar<T> Bar<T>;		//	`Bar<T>` CANNOT be a `typedef`!!!

typedef struct Bar<T> Bar<float>;	//	struct IDENTIFIER '<' GENERIC_TYPE (or %empty '>'
typedef struct Bar<T> Bar<double>;	//	struct IDENTIFIER '<' GENERIC_TYPE (or %empty '>'

struct Bar<T> {				//	`Bar` == IDENTIFIER
	struct Bar<T> *next;	//	`Bar` == IDENTIFIER
	size_t size;
};

//	NOTE: `Bar__float` gets registered as a generic type!



/*
```
struct Bar__float {
	struct Bar__float *next;
	size_t size;
};

typedef Bar<T> Bar<float>;
```
*/

//-----------------------------------------------------------------------------




typedef struct Bar<> Bar<T>;
struct Bar<T> {
	Bar<T> *next;		//	GENERIC_NAME '<' GENERIC_TYPE '>'
	size_t size;
};

typedef Bar<T> Bar<float>;
typedef Bar<T> Bar<double>;

typedef struct Bar<> Bar<T>;
struct Bar<T> {
	Bar<T> *next;
	size_t size;
};








//	Example 4
//	Opaque Generic Type
typedef struct Bar<> Bar<T>;

typedef Bar<T> Bar<float>;
typedef Bar<T> Bar<double>;

//	ALL `opaque` definitions will be resolved here !?!?
//	We assume that the concrete types are already defined by this point!
struct Bar<T> {
	T x, y, z;
};


int main(int argc, const char *argv[])
{
	Test test;
	test.value = 42;
	return 0;
}
