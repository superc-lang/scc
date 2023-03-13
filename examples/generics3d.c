
typedef long int size_t;

struct Foo<T> {
	size_t size;
	T value;
	Foo<T> *next;
	struct Foo<T> *next2;
};

struct test1 {
	int t;
};

struct {
	int t;
} test2;

struct test3 {
	int t;
} test4;


typedef struct test5 {
	int t;
} test6;


typedef Foo<float>;

// typedef int Foo<int>;
// volatile typedef int long Foo<int> Food;
// volatile typedef struct Food<T> Food<int>;

// typedef Foo<> Foo<int>;			//	INVALID! Handled by the parser!
// typedef Foo<int> Foo<int>;


//typedef struct Foo<> Foo<int>; ... I no longer want to support this syntax!!! You can't make a `typedef` of `Foo<int>`!
//	HOWEVER, on second thought. Since we WILL be doing this for the user anyway, it might be useful for the user to be able to do it themselves!
typedef struct Foo<> Foo<int>;

typedef struct Foo<int> MyFoo;

typedef Foo<int> MyFoo2;
typedef MyFoo2 MyFoo3;

// typedef struct Foo2<T> {
// 	int size;
// } Swoop;

// typedef Foo<> MyFoo2;		//	INVALID! Handled by the parser!
// typedef Foo<> Foo<int>;		//	INVALID! Handled by the parser!


int main(int argc, const char *argv[])
{
	struct Foo<int> *foo = (struct Foo<int>*) malloc(sizeof(struct Foo<int>));

	Foo<int> *foo2 = (Foo<int>*) malloc(sizeof(Foo<int>));

	Foo<int> *foo3;

	Foo<int> foo4;

	// fn(foo);

	// Foo<float> foo;
	// foo.size = 42;
	// foo.value = 1.2f;
	return 0;
}

void fn(Foo<int> *foo);
void fn(Foo<int> *foo)
{
	sizeof(Foo<int>);
	// sizeof Foo<int>;

	Foo<int> *foo2 = (Foo<int>*) NULL;

	static Foo<int> *foo3 = (Foo<int>*) NULL;
}

Foo<int> *fn2();
Foo<int> *fn2()
{

}

void fn3(int i, Foo<int> *foo);
void fn4(Foo<int> *foo, int i);
void fn5(Foo<int> *foo, Foo<long> *foo2);



struct Foo<int> *fn6();
struct Foo<int> *fn6()
{

}

void fn7(int i, struct Foo<int> *foo);
void fn8(struct Foo<int> *foo, int i);
void fn9(struct Foo<int> *foo, struct Foo<long> *foo2);
