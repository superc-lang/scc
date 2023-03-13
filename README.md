# Super C Language & Compiler

### Super C is:

* **a superset of standard C**. [^superset]
* 'C with classes' *re-imagined*!
* [transpiled](https://en.wikipedia.org/wiki/Source-to-source_compiler) to C.
* as fast as C.
* more concise than C. [^concise]
* more than just syntactic sugar for C.
* compiled to optimized machine code by an existing C compiler, such as GCC.
* designed to be incrementally adoptable. [^inc]
* written in standard C, so it's easy to build; but a Super C rewrite is also possible.
* designed to work in conjunction with existing C code, in a mixed source hybrid environment; where you have both Super C and standard C code/files. You can also compile all your standard C files with the `scc` compiler even if you never intend to alter them, or you can just *link* the final `scc` and `gcc` compiled object files together at the end; and since `scc` calls `gcc` *under the hood* anyway, the object files are binary compatible. [^hybrid]
* designed to make use of; and build on top of the existing C infrastructure (like existing C compilers).
* designed to be as fast as possible, in order to minimize the compile time overhead.
* for people that want more syntactical options/freedom and design flexibility in C.
* going to divide opinion on it's value, features, keywords, usage and place in the C community.
* heavily inspired by Rust and C++; but also influenced by D, C#, Java, Kotlin and JavaScript.
* "zero cost abstractions" without the BS!
* originally based on the C11 standard (and still compatible), but now includes many enhancements.
* a passion project several years in the making.
* **NOT** (yet) a replacement for C, C++, Rust, Zig or any other mature systems level language.
* **NOT** designed to replace C, it builds on top of C.
* **NOT** trying to be a C++ clone! It has a different design philosophy.
* **NOT** trying to be a *safe* language. If you want memory safety, use something else!
* **NOT** sanctioned by, or affiliated to the ISO standards committee or WG14.
* **NOT** affiliated with any big tech company, although I welcome any constructive input.
* **NOT** a borrow checker, although "opt-in" borrow checking is possible in the future!
* **NOT** trying to dictate or enforce any programming philosophy like OOP on you. Use what makes sense!
* **NOT** currently suitable for beginners or those that don't have a good understand of C.
* **NEVER** going to add exceptions or a garbage collector! Ever! Build your own if you need them!


[^superset]: Super C is a strict superset of standard C, so all valid C programs are valid Super C programs!\
Unlike C++, this mandate is non-negotiable for Super C; so it will remain a strict C superset, forever!\
Therefore, all features introduced will have a C equivalent or counterpart, as it's ultimately transpiled to C, and compiled by a C compiler. The difference will be in the syntax, which will be more concise (shorter).\
Even the word *Super* in the name is derived from the word 'superset'; hence the name, Super(set) C.

[^concise]: Super C is objectively more concise than C, meaning it has shorter syntax.\
This is objectively true; and can be verified by simply counting the number of characters required in standard C syntax for the same expression/statement in Super C syntax.\
This is with regards to the new features added in Super C, not the existing C syntax which is the same.\
This has implications for readability, maintainability and productivity.

[^inc]: You can create Super C 'wrappers' around libraries and structures you don't even own! By leaving the original C code untouched, and adding checks for `__SUPERC__` around the Super C wrapper code, you can gradually add Super C features to your code base, one file at a time; while still supporting a backwards compatible standard C interface. Check the `examples/` directory for an example in `multi-file3` where I support both a standard C and Super C interface to a hash table implementation.

[^hybrid]: Super C is designed to work in an incrementally adoptable, mixed source (hybrid) environment; where you have both Super C and standard C code and files.\
Start with your existing C code, and incrementally adopt the features you want.\
You can even mix Super C and C in the same file, or even in the same function by using the `__SUPERC__` macro.\
You can also compile all your standard C files with the `scc` compiler; or compile standard C files with `gcc` and just the Super C files with `scc`; and then *link* the final compiled object files together at the end. Since `scc` calls `gcc` *under the hood*, the compiled object files are binary compatible.


### Features (summary)

All features are compiled to human readable standard C.

* [Generics](#generics)
* `impl` blocks (inspired by Rust).
* `NULL`, `nullptr` and `null` are *built-in* keywords
* `bool`, `true` and `false` are *built-in* keywords
* `get` and `set`
* `new` and `delete`
* `=>` (single-expression `return` shorthand)
* `::` and `.` (pseudo-namespacing)
* `this` and `self` are implicitly added and auto-detected
* `__SUPERC__` macro to detect support

## Features (detailed)

* One of the most powerful features of Super C, is arguably native support for **Generics**!
  * Please read the detailed section below on Super C's powerful implementation of [Generics](#generics).
* `impl` blocks are where you define methods associated with a structure or `typedef`.
  * This is more than just a choice of syntax, it has a profound impact on many aspects of the language.
  * Unlike C++ where `class` structures are 'closed', in the sense that they can't be extended without inheritance, `impl` blocks allow you to extend any `typedef` multiple times with methods, because the `impl` blocks are not 'nested' within the `struct`.
  * By separating the methods into `impl` blocks, we keep the base `struct` clean and simple.
  * Similar to C#'s '[extension methods](https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/extension-methods)', this allows you to extend structures you don't even control.
  * Create wrappers and extend any external library, structure or `typedef`, without any inheritance and without having to modify the original source code.
  * Create an 'object-like' interface or wrapper for `FILE`, zlib, libpng, OpenGL, OpenSSL etc.
  * Super C's `impl` blocks have a different design philosophy to C++ classes.
* `NULL`, `nullptr` and `null` are all built-in keywords that map to `((void*)0)`.
  * By 'built-in' I mean that they are keywords with native support and do not require any header files.
  * If any `NULL` keywords survive the C preprocessor, they will be handled by the Super C compiler.
  * Although `nullptr` will be added in C2X (C23), Super C makes it available to older C versions.
  * `null` is my preferred keyword, it's shorter, looks more natural and available in several other languages.
* `bool`, `true` and `false` are also built-in keywords that don't require headers. (Headers are optional).
* C++ style `new` and `delete` keywords and syntax. (But a different implementation)
* C++ style object method invocation. eg. `foo->bar()` instead of `someprefix_bar(foo)`.
  * This does actually get transpiled to a standard C function call, but the object-style is much more concise!
* pseudo-namespacing with `::` or `.`
  * eg. `Foo::bar()` or `Foo.bar()`.
  * These methods are implemented in `impl static` blocks, which don't require an instance of the class.
* 'getters' (`get`) and 'setters' (`set`) are built-in constructs.
  * *True* support for native 'getters' and 'setters' which don't require any `()`.
    * eg. `get int count() const => this->counter;`
    * Can be used like this in code: `foo->count` or `foo.count`.
    * It does get transpiled to a standard C function call, but the Super C syntax is much shorter.
* `this` and `self` are both supported and auto-detected within methods in `impl` blocks.
  * Use whichever you prefer inside the `impl` methods, and the compiler will auto-detect it.
  * We support both `this` and `self` for people from different language backgrounds and preferences.
  * `this` will be familar to C++, Java, C# and D developers
  * `self` should be familiar to Rust and Python developers
* 'fat arrow' functions `=>` for `return` statement shorthand.
  * eg. `int count() => this->counter;` is shorthand for `int count() { return this->counter; }`
* All source-code generated by the Super C compiler is visible to the developer; 'beautified' and human readable standard C. There is no 'hidden magic' except AST (tree node) manipulation.


## Generics

**TLDR;** *Generics* are a first-class native feature of Super C, which creates a unique `struct` for each concrete type of a *generic* type at compile-time. Similar to C++ templates and the [Monomorphization](https://en.wikipedia.org/wiki/Monomorphization) of *generics* in Rust.

The primary goal of implementing *generics* in Super C is to improve run-time performance.\
Secondary goals included more readable, maintainable and type safe code for *generic* types.

*Generics* are typically used in 'container' classes; such as linked lists, hash tables, dictionaries, tuples etc.

Given the fact that 'container' classes are such a vital and integral part of most programs; the lack of *generics* in C can be viewed as a serious deficiency; especially when you are forced to make design trade-offs between run-time performance, readability and the maintainability of your code; which is exactly what *generics* give you.

Sure, every C dev has their own preferred workaround for containers; and yes, you might not even consider it a 'deficiency' in C; some people don't even realize there is an issue, others don't really know there is already a better solution to this problem already implemented in other languages. Sadly, most C developers just have to ignore it and work with what they have available. But no matter what workaround or solution you can come up with in standard C; there is simply NO suitable, comparable or equivalent alternative to the run-time performance, readability and maintainability of native *generics*.

Well, now you have the option to use them too!


#### *Generics* give you:
* a 'custom designed' compile-time data structure perfectly fitting your data needs
* improved run-time performance:
  * improved '[locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)'
  * improved CPU cache utilization
  * fewer CPU cache misses
  * fewer memory allocations
  * fewer pointer dereferences
* improved readability and maintainability
  * no macros
  * less boilerplate code (from casts and additional allocations)
  * reduces code duplication
* compile-time type checking


Example 1:
```C
struct Vec3<T> {
    T x;
    T y;
    T z;
};
```

Example 2:
```C
struct LinkedListNode<T> {
	T value;
	struct LinkedListNode<T> *next;
};
```

Example 3:
```C
struct Vector<T> {
	T *data;
	size_t size;
	size_t capacity;
};
```

Example 4:
```C
struct Matrix<T, M, N> {
	T mat[M][N];
};
```


#### Generics are:
* a game changer for C!
* one of the most powerful features natively supported in many other languages, but not in C.
* the #1 feature I wanted to implement in Super C, because there is simply no suitable equivalent in C.
* unmatched in terms of run-time performance, readability and type safety compared to any other C alternative.
* not implemented in C because it would increase the complexity of the language and compilers.
  * However, not having this feature as a native part of the language forces us to make unreasonable compromises and tradeoffs between verbosity, readability, maintainability, type safety and run-time performance.
* a powerful tool for creating reusable code and reducing boilerplate code; improving maintainability.
* especially useful for creating container types that support any type of data.
  * Yes, this is a very specific category of data structures, but it is also a vital part of almost every program!
* commonly used to implement 'containers' and reuseable abstract data types in other languages such as:
  * `std::vector<T>`, `std::list<T>`, `std::map<K,V>` and `std::pair<A,B>` in C++
  * `Vec<T>`, `HashMap<K, V>`, `Option<T>` and `Tuple<A, B>` in Rust
  * `ArrayList<E>`, `LinkedList<E>`, `HashMap<K, V>` and `Pair<A, B>` in Java
  * `List<T>`, `LinkedList<T>`, `Dictionary<K, V>` and `Tuple<A, B>` in C#
* not easily emulated by the available language features in C:
  * The most common alternatives to *generics* in standard C are:
    * a `void *data` member
    * using `#define` macros
    * store data member size at run-time
    * 'function pointers'
    * [tagged unions](https://en.wikipedia.org/wiki/Tagged_union)
  * All these alternatives have limitations and drawbacks; and none can compare to a native language feature.
* implemented as a first-class native language construct in Super C.
  * Super C uses the common `<T>` syntax for generic types, which is simply impossible to do in standard C.
  * The Super C compiler creates a unique `struct` and dedicated functions for each type at compile-time.
  * This is known as [Monomorphization](https://en.wikipedia.org/wiki/Monomorphization) in Rust.
  * Monomorphization is the compile-time process of replacing a generic `struct` with a concrete implementation.
  * This is desirable since the resulting code can be easily optimized, producing faster run-time code.
  * All the code generated by the Super C compiler is visible to you by just inspecting the standard C output.
  * To recap; the Super C compiler creates (or injects) a unique `struct` with supporting functions for each concrete type at compile time; with just two lines of code. There is simply no equivalent in standard C to the power, elegance, natural feel and run-time speed of this approach.

---

#### The most common alternatives to generics are:
  * a `void *data` member
    * Very common in simple/naive linked list and hash table implementations.
    * Commonly taught in C tutorials, courses, books and other educational materials.
    * This method is actually necessary in some situations, where you want to link to an existing structure.
    * Advantages:
      * simple to implement
      * familiarity
    * Disadvantages:
      * Poor run-time performance:
        * Issues with '[locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)'
        * Increased CPU cache pollution (uses at least two CPU cache lines instead of one)
        * Increased CPU cache misses
        * Increased memory allocations
        * Increased pointer dereferences and indirections
      * More boilerplate code for type-casts from `void*` and extra memory allocations etc.
  * using `#define` macros
    * This method uses `#define` for a set of macros that create custom `structs` and functions for each type.
    * Gives you the ability to 'embed' (or inject) the data type within the parent `struct`
    * Avoids all the performance issues compared to using a `void *data` member.
    * Disadvantages:
      * Increased code verbosity.
      * Decreases overall readability and maintainability of the code.
    * This is still the only option to C devs for compile-time code generation.
    * Macros do not have any advantages over *generics* in Super C, including run-time performance!
  * Store data size at runtime
    * This is what I personally use.
    * In hash table or linked list implementations, you have a `char data[]` member at the bottom of each node.
    * You store the data member size in the parent `struct`, and use it when allocating memory for the nodes.
    * Advantages:
      * Uses the same source code for all types. So better utilization of CPU icache (instruction cache).
      * Performance:
        * Improved '[locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)'.
        * Improved CPU cache utilization.
        * Less memory allocations.
      * Avoids using macros.
    * Disadvantages:
      * extra parameter to keep the data member size at run-time (minor issue, only stored once)
      * No type safety: you still need to cast a `char data[]` member to the correct type.
  * 'function pointers'
  * [tagged unions](https://en.wikipedia.org/wiki/Tagged_union)
  * or some other custom approach (AKA a hack)

---

### How to use *generics* in Super C:

The code below might look complex, but it should be fairly easy to follow.

1. Declare a *generic* type:
```C
struct Vec3<T> {
    T x;
    T y;
    T z;
};
```

2. Write the *generic* methods you want in 'named' `impl` blocks:
```C
impl header Vec3<T>
{
	Vec3<T> *new(T x, T y, T z);
	bool eq(Vec3<T> *other);
	set void eq(Vec3<T> *other);
	get T magnitude();
	void normalize();
	T dot(Vec3<T> *other);
	void delete();
}

impl source Vec3<T>
{
	Vec3<T> *new(T x, T y, T z)
	{
		Vec3<T> *v = (Vec3<T>*) malloc(sizeof(Vec3<T>));
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
```
Note: The names (or labels) of the `impl` block, `header` and `source` are user defined, to group the code snippets.

3. Declare your concrete types, and where you want the `impl` code generated:

```C
// .h  (header file)
typedef Vec3<float>;
typedef Vec3<double>;

impl header Vec3<float>;
impl header Vec3<double>;
```

```C
// .c  (source file)
impl source Vec3<float>;
impl source Vec3<double>;
```

4. Use the generic types and methods in your code:
```C
int main(int argc, const char *argv[])
{
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
	printf("v1 = (%f, %f, %f)\n", v1->x, v1->y, v1->z);

	delete v1;
	delete v2;

	return 0;
}
```

### So what's the big deal?

The big deal is that with a single line of code:
```C
typedef Vec3<float>;
```
the Super C compiler generated a unique structure for the `Vec3<float>` implementation:
```C
typedef struct Vec3__float {
	float x;
	float y;
	float z;
} Vec3__float;
```
and with another single line of code:
```C
typedef Vec3<double>;
```
it will generate a totally different structure for the `Vec3<double>` implementation:
```C
typedef struct Vec3__double {
	double x;
	double y;
	double z;
} Vec3__double;
```
Not only that, but it will generate custom methods for each structure with literally a single line of code:
```C
impl source Vec3<float>;
impl source Vec3<double>;
```

 the `impl` code for each type, and it will generate the `impl` code for each method.


The big deal is that you can now use the same code for different types, without having to write a separate implementation for each type. For example, you can use the same `Vec3` code for a `float` or `double` implementation.

Another big deal is that the Super C compiler generated a custom structure for the `<float>` implementation:
```C
typedef struct Vec3__float {
	float x;
	float y;
	float z;
} Vec3__float;
```
and it will generate a totally different structure for the `<double>` implementation:
```C
typedef struct Vec3__double {
	double x;
	double y;
	double z;
} Vec3__double;
```




5. The real power of *generics* will come in when you declare a different type:
```C
Vec3<double> *v3 = new Vec3<double>(7.0, 8.0, 9.0);
```

'named' `impl` blocks are a Super C specific feature, allowing you to group code blocks for different purposes, like 'header' and 'source' code; or feature specific code, like 'math' or 'string' specific code.

You are free to add `static inline` methods to the 'header' section, it's not restricted to function declarations, it's just a label!

The 'name' (or label) is just a user defined identifier that is used to identify and separate the different groups of code.

For example, you might want to define a custom set of features (or methods) for different data types; for example, you might want to declare a set of methods specific to 'string' data types, such as `length`, `concat`, `copy` etc. that might not be suitable for numeric or primitive data types.

Each type is also able to override the default implementation of any generic methods. (feature coming soon)

---

1. Declare your concrete types:
```C
typedef Vec3<float>;
typedef Vec3<double>;
typedef Vec3<int>;
```
The compiler will automatically infer the generic type and generate the corresponding structures.






3. Use the `Vec3<float>` as any other type:
```C
Vec3<float> vec3 = new Vec3<float>(1.0, 2.0, 3.0);    // Heap allocated *
// or
Vec3<float> vec3 = { 1.0, 2.0, 3.0 };                 // Stack allocated
```
\* Actions performed by the `new` and `delete` keywords are implemented in `impl` blocks. You have full control of their implementation, and you are free to use `malloc()` and `free()` or any other custom allocator. The `new` and `delete` keywords are just a syntactical convenience.

4. The compiler generates the following standard C code:
```C
struct Vec3__float {
    float x;
    float y;
    float z;
};

typedef struct Vec3__float Vec3__float;

Vec3__float vec3 = Vec3__float__new(1.0, 2.0, 3.0);   // Heap allocated
Vec3__float vec3 = { 1.0, 2.0, 3.0 };                 // Stack allocated
```



5. The compiler then generates the following standard C code:
```C
//	Vec3.h
typedef struct Vec3__float {
	float x;
	float y;
	float z;
} Vec3__float;

typedef struct Vec3__double {
	double x;
	double y;
	double z;
} Vec3__double;

// `Vec3__float` headers
Vec3__float *Vec3__float__new(float x, float y, float z);
Vec3__float *Vec3__float__myMethod(Vec3__float *this, Vec3__float *other);
void Vec3__float__delete(Vec3__float *this);

// `Vec3__double` headers
Vec3__double *Vec3__double__new(double x, double y, double z);
Vec3__double *Vec3__double__myMethod(Vec3__double *this, Vec3__double *other);
void Vec3__double__delete(Vec3__double *this);
```

```C
//	Vec3.c

// `Vec3__float` methods

Vec3__float *Vec3__float__new(float x, float y, float z) {
	Vec3__float *vec3 = malloc(sizeof(Vec3__float));
	// ...
	return this;
}

Vec3__float *Vec3__float__myMethod(Vec3__float *this, Vec3__float *other)
{
	// ...
}


// `Vec3__double` methods

Vec3__double *Vec3__float__new(double x, double y, double z) {
	Vec3__double *vec3 = malloc(sizeof(Vec3__double));
	// ...
	return this;
}

Vec3__double *Vec3__double__myMethod(Vec3__double *this, Vec3__double *other)
{
	// ...
}

// ...

```

Each generic type gets a unique `struct` and methods, all generated at compile-time.\
There are also many other features of generics, such as dedicated member methods, 'getters', 'setters' etc.







## Example 1:

#### Code highlights:

* Everything you see here is transpiled (converted) to standard C syntax!
* The final C output of this example is available here: https://godbolt.org/z/TvGT4WEbz
* In every scenario, the Super C syntax is more concise and arguably easier to read and maintain.
* `impl` statements inspired by Rust. Keeps data structures and member methods separated.
	The 'typename' in `impl <typename>` acts as a namespace and common prefix for method names.\
	eg. all `Foo` class/structure methods get a `Foo__` prefix.
* `new` and `delete` keywords and syntax from C++, map to the `new` and `delete` methods.
* `age` is a 'getter' (defined by the `get` keyword), as well as a 'fat-arrow function' `=>` (`return` shorthand).
* In `main()`: `car->age` maps to the `age` 'getter', which is converted to a function called `Car__get__age`.
* You can choose to use either `self` or `this` inside `impl` methods. The compiler will auto detect them.
* Unlike in Rust, but just like in C++, you don't need to specify `self` or `this` as the first param, it's implied!
* If you need a method that doesn't take an object instance, like `static` methods in C++, use `impl static <typename>`.

##### Summary

| Super C            | C output              |
| ------------------ | --------------------- |
| `impl Car`         | -                     |
| `new Car(...);`    | `Car__new(...);`      |
| `delete car;`      | `Car__delete(car);`   |
| `car->make_model()`| `Car__make_model(car)`|
| `car->age`         | `Car__get__age(car)`  |
| `=> ...`           | `{ return ... }`      |


```diff
-// standard C syntax
+// Super C syntax

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	const char *make;
	const char *model;
	int year;
} Car;

+impl Car
+{
-	Car *car_init(const char *make, const char *model, int year)
+	Car *new(const char *make, const char *model, int year)
	{
		Car *car = (Car *) malloc(sizeof(Car));

		car->make = make;
		car->model = model;
		car->year = year;

		return car;
	}

-	const char *car_make_model(const Car *self)
+	const char *make_model() const
	{
		static char make_model[128];

		sprintf(make_model, "%s %s", self->make, self->model);

		return make_model;
	}

-	int car_age(const Car *self) { return 2023 - self->year; }
+	get int age() const => 2023 - self->year;

-	void car_free(Car *self)
+	void delete()
	{
		free(self);
	}
+}

int main(int argc, char *argv[])
{
-	Car *car = car_init("Ford", "Mustang", 1969);
+	Car *car = new Car("Ford", "Mustang", 1969);

-	printf("Car make, model & year: %s %d\n", car_make_model(car), car->year);
+	printf("Car make, model & year: %s %d\n", car->make_model(), car->year);

-	printf("Age: %d\n", car_age(car));
+	printf("Age: %d\n", car->age);

-	car_free(car);
+	delete car;

	return 0;
}
```

## Example 2

#### Code highlights:

* The final C output of this example is available here: https://godbolt.org/z/onodhYKhh
* Example 1 demonstrated usage of `self`. Example 2 demonstrates `this`. Super C supports both!
* `distance()` and `angle()` both take an additional `Point` value `p2`, but called like C++ `p1->distance(p2)`.
	The syntax `p1->distance(p2)` is transpiled to standard C `Point__distance(p1, p2)`.
* `angle` and `magnitude` are both using the `return` shorthand provided by 'fat-arrow' functions `=>`.
* `p1->magnitude` is a getter and transpiled to: `Point__get__magnitude(p1)`

##### Summary

| Super C             | C output                    |
| ------------------- | --------------------------- |
| `impl Point`        | -                           |
| `new Point(0, 0)`   | `Point__new(0, 0)`          |
| `delete p1;`        | `Point__delete(p1);`        |
| `p1->distance(p2)`  | `Point__distance(p1, p2)`   |
| `p1->angle(p2)`     | `Point__angle(p1, p2)`      |
| `p1->magnitude`     | `Point__get__magnitude(p1)` |
| `magnitude() const` | `Point__magnitude(const Point *this)` |
| `=> ...`            | `{ return ... }`            |

```diff
-// standard C syntax
+// Super C syntax

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Point;

+impl Point
{
-	Point *point_create(int x, int y)
+	Point *new(int x, int y)
	{
		Point *p = (Point *) malloc(sizeof(Point));

		p->x = x;
		p->y = y;

		return p;
	}

-	float point_distance(const Point *this, Point *p2)
+	float distance(Point *p2) const
	{
		int dx = this->x - p2->x;
		int dy = this->y - p2->y;

		return sqrt(dx * dx + dy * dy);
	}

-	float point_angle(const Point *this, Point *p2) { return atan2(p2->y - this->y, p2->x - this->x); }
+	float angle(Point *p2) const => atan2(p2->y - this->y, p2->x - this->x);

-	float point_magnitude(const Point *this) { return sqrt(this->x * this->x + this->y * this->y); }
+	get float magnitude() const => sqrt(this->x * this->x + this->y * this->y);

-	void point_free(Point *this)
+	void delete()
	{
		// potentially free other members here
		free(this);
	}
}

int main(int argc, char *argv[])
{
-	Point *p1 = point_create(0, 0);
-	Point *p2 = point_create(3, 4);
+	Point *p1 = new Point(0, 0);
+	Point *p2 = new Point(3, 4);

-	printf("Distance between p1 and p2: %f\n", point_distance(p1, p2));
+	printf("Distance between p1 and p2: %f\n", p1->distance(p2));

-	printf("Angle between p1 and p2: %f\n", point_angle(p1, p2));
+	printf("Angle between p1 and p2: %f\n", p1->angle(p2));

-	printf("Magnitude of p1 and p2: %f\n", point_magnitude(p1), point_magnitude(p2));
+	printf("Magnitude of p1 and p2: %f\n", p1->magnitude, p2->magnitude);

-	point_free(p1);
-	point_free(p2);
+	delete p1;
+	delete p2;

	return 0;
}
```

##### Disclaimer on the term 'standard C'!

Q: By the term 'standard C compliant', what do I mean?\
A: I mean that this compiler was originally based on the C11 specification, but needed many enhancements and extensions to be compatible with GCC generated output; which includes many of it's own compiler specific extensions, even to the standard C syntax.

This is a 'best effort' attempt to support as many variations and extensions to the 'standard C' syntax, and as many C compilers as possible! I'm not there yet! Currently I only support GCC, but I would like to support at least GCC, Clang, MSVC, PCC, TCC and LCC in the future.

So I welcome the input from **any** compiler devs to help me make it more compatible with their compilers.

## How does it work?

* The Super C Compiler `scc` calls GCC to pre-process your source file (expanding macros `#include`, `#define`, `#if` etc.).
* The first step creates a new file; `<filename>.sc.i` which contains the expanded Super C source code;
* The Super C compiler creates an AST (abstract syntax tree) from the `<filename>.sc.i` file;
* The Super C AST is converted into a 'standard C' AST; (the actual conversion and most important step)
* From the standard C AST we generate a `.i` file containing the final standard C compliant code;
* The source code generated from the `.i` file is compiled by GCC into the final binary;
* The `.i` extension on files indicates to GCC that the file has already been preprocessed, so GCC skips that step;
* You will need to refer to the `.i` file during debugging, because GCC will be generating syntax errors from it!
* If you compiled a standard C file there would be nothing extra to convert.

So the Super C compiler is technically a source-to-source transpiler.

Currently, GCC is the only fully tested compiler, since most of my effort has been directed at the actual language features and design, and not compiler integration. But I fully intend to support multiple compilers, any help or suggestions from other compiler devs are welcome.

## New Keywords

* `NULL` == `nullptr` == `null` == `((void*)0)`
* `bool` => `_Bool`, `true` => `1`, `false` => `0`
* `impl <typename> { ... }` ~ inspired by Rust, where you add instance methods
* `impl static <typename> { ... }` ~ a block for non-instance methods similar to C++ `static` methods.
* `new` & `delete` ~ inspired by C++
* `get` ~ getters
* `set` ~ setters
* `this` or `self` ~ compiler auto-detects one

## New Operators

* `::` or `.` ~ pseudo-namespacing
  * eg. `Foo::bar()` or `Foo.bar()` becomes `Foo__bar()` in the final C output.
  * internally they are just replaced with `__` in the final C function name.
* `=>` ~ fat arrow functions for `return` statement shorthand
  * eg. `get int count() => this.counter;` is equivalent to `get int count() { return this->counter; }`

## Possible future features and wishlist

* JavaScript-inspired object destructuring. eg. `const { model, make, year } = this;`
* Initializer shorthand.
* `interfaces` from Java/C# and/or Rust-like `traits` - to improve polymorphism!
  * This will probably require a V-table, unless someone has a better suggestion?
* Primary Constructors inspired by Kotlin.
* anonymous functions
* nested functions
* `let` or `var`, or C++ style `auto` - automatic type inference
* `defer`
* 'null safe' operators - `?.` from TypeScript and Kotlin, and/or `?:` and/or `??`
* binary values; eg. `0b0101`
* `Range` or `Iterator` (requires 'interfaces' or 'traits')
* `foreach`, implementing either `Range`s or `Iterator`s
* `owner`/`borrow` (an "opt-in" borrow checker is possible)
* multiple return values
* `===` and `!==` - my idea of auto-dereferencing, and overloadable comparisons!
* Array index subscript overloading (eg. `a[0]` or `a[1]` or `a[2]` etc.)
* `async`/`await`
* 'coroutines' / green threads / fibers
* built-in (compile-time) regular expressions
* operator overloading (unlikely but possible)
* `classes` - C++/Java/C# classes (unlikely for now but still possible, but very distant future)

\* These will depend on complexity, workload, requests, funding etc.
My primary target is to get *generics* implemented, I think it will be a game changer!


# Install

```
make
```

### Compile a file

The compiler supports all GCC commands. Some commands are executed in the pre-processor phase, and others are executed in the final C code generation phase.

But you don't have to worry about which is which, just use the same commands you would normally use with GCC.

Unfortunately, the compiler doesn't have very sophisticated error messages yet. I rely on GCC to give me the errors, so if you get an error, you will have to look at the C output code to figure out how to modify your code to compile correctly. Every file is compiled with two extra files. `<filename>.sc.i` and `<filename>.i`. The first is the GCC preprocessor output, and the second file is the output from the Super C compiler. The `.sc.i` file will contain the Super C code with all the macros expanded, including `#include` files. So you will see a LOT of extra data, just scroll to the bottom of the file to your code. The second file, `<filename>.i` is the final C code that will be compiled by GCC.

So, essentially the Super C compiler takes the `.sc.i` file, and converts it into the `.i` file. The `.i` file has the final standard C code which is then compiled by GCC.

```
scc ./examples/example1.c -o example1
```

I'm still using `.c` extensions for now, but I might change it to `.sc` in the future. Once we have proper tooling for that extension. Or I might just stick with `.c`?

The compiler only has 1 extra flag, `-ast` which will generate a 'before' and 'after' AST tree file in `<filename>.ast.before.txt` and `<filename>.ast.after.txt`.

The AST tree generation is probably the most powerful debugging tool for anyone wanting to know how it works internally. And literally every time I add a new feature, I need the AST tree files to implement the feature.

If you specify the `-g` GCC (debug) command, it will also generate the AST tree listings!

## Limitations

Disclaimer: C programmers are notorious for doing "out of the ordinary" or unconventional things, so I'm 100% sure there are still a million ways you can break the compiler that I haven't thought about. I've just been focusing on the core features for now!

There are many limitations currently, but there are also many positives to take from this project so far!

Anyways, here's my current list of *major* or obvious issues:

* VERY limited error reporting and handling on syntax errors. I imagine that this will be an ongoing, endless mission to improve the error handling feedback.
* You MUST specify the `struct` as a `typedef` name for use in `impl` blocks. You can't do the following: `impl struct Car`! It's just `impl Car` which must be a `typedef` name!
* The `new` and `delete` syntax don't work on arrays like the C++ syntax does. (yet!) eg. `new Point[10]` or `delete[] p`.
* The biggest issue right now, is probably that the 'getter', 'setter' and member method syntax/lookup doesn't work on nested variables. eg. `var1->var2->getter` won't work. The way to solve this currently is to define a local variable for `var2` first, eg. `MyType *var2 = var1->var2`. Then call the 'getter', `var2->getter`, because I don't do multi-level lookups for now. I do plan to get this working in the future since it's required!
* Method chaining won't work either, because I don't have 'deep' knowledge of the function return values and structure layout yet. Baby steps!

### Dedication

This language and compiler is dedicated to [Dennis Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie), [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson) and [Brian Kernighan](https://en.wikipedia.org/wiki/Brian_Kernighan).


# [FAQ](FAQ.md)
