# Super C Compiler

#### Super C is:

* **a strict syntactical superset of standard C**.
* 'C with classes' *re-imaged*!
* [transpiled](https://en.wikipedia.org/wiki/Source-to-source_compiler) to standard C.
* as fast as C. (because it is C)
* more concise than C. (shorter syntax)
* compiled to machine code by an existing C compiler such as GCC.
* a passion project that has taken thousands of hours and still in active development (as of Feb 2023).
* C with syntactic sugar (eye candy). **
* for C and non-C programmers that want more syntactical options and design flexibility; haters be gone!
* going to divide opinion on it's value, features, keywords, usage and place in the C community.
* designed to be incrementally adoptable. ***
* inspired by Rust, C++, C#, Java, Kotlin and JavaScript.
* "zero cost abstractions" without the BS!
* still a work in progress, so expect missing features or some incompatibility with your existing C code.
* designed for modern CPU architectures that declare `NULL` as `((void*)0)` (or equivalent). 
  * This includes all Intel, AMD, ARM, RISC-V, PowerPC, SPARC, MIPS, etc.
  * Only very old CPUs from the 60's, 70's and 80's don't support this!
* **NEVER** going to add exceptions or a garbage collector! Ever!
* **NOT** a replacement for C, C++, Rust, Zig or any other mature systems level language.
* **NOT** designed to replace C, it builds on top of C.
* **NOT** trying to be a C++ clone! It has a different design philosophy.
* **NOT** trying to be a *safe* language. If you want memory safety use something else!
* **NOT** sanctioned by or affiliated to the ISO standards committee or WG14.
* **NOT** affiliated with any big tech company, although I welcome any constructive input.
* **NOT** a borrow checker (although "opt-in" borrow checking is possible in the future!)
* **NOT** trying to dictate or enforce any programming philosophy like OOP on you. Use what makes sense!
* **NOT** currently suitable for beginners or those that don't have a good understand of C.


** All valid C programs are valid Super C programs. It's a 100% compatible superset of C, hence the name, Super(set) C.
*** You can create Super C 'wrappers' around libraries and structures you don't even own!

> Syntactic Sugar
> "syntax within a programming language that is designed to make things easier to read or to express."

## Example 1:

#### Code highlights:

* Everything you see here is transpiled (converted) to standard C syntax!
* The final C output of this example is available here: https://godbolt.org/z/TvGT4WEbz
* In every scenario, the Super C syntax is more concise and arguably easier to read and maintain.
* `impl` statements inspired by Rust. Keeps data structures and member methods separated.
	The 'typename' in `impl <typename>` acts as a namespace and common prefix for method names.
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

-	const char *car_make_model(Car *self)
+	const char *make_model()
	{
		static char make_model[128];

		sprintf(make_model, "%s %s", self->make, self->model);

		return make_model;
	}

-	int car_age(Car *self) { return 2023 - self->year; }
+	get int age() => 2023 - self->year;

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

| Super C            | C output                    |
| ------------------ | --------------------------- |
| `impl Point`       | -                           |
| `new Point(0, 0);` | `Point__new(0, 0);`         |
| `delete p1;`       | `Point__delete(p1);`        |
| `p1->distance(p2)` | `Point__distance(p1, p2)`   |
| `p1->angle(p2)`    | `Point__angle(p1, p2)`      |
| `p1->magnitude`    | `Point__get__magnitude(p1)` |
| `=> ...`           | `{ return ... }`            |

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

-	float point_distance(Point *this, Point *p2)
+	float distance(Point *p2)
	{
		int dx = this->x - p2->x;
		int dy = this->y - p2->y;

		return sqrt(dx * dx + dy * dy);
	}

-	float point_angle(Point *this, Point *p2) { return atan2(p2->y - this->y, p2->x - this->x); }
+	float angle(Point *p2) => atan2(p2->y - this->y, p2->x - this->x);

-	float point_magnitude(Point *this) { return sqrt(this->x * this->x + this->y * this->y); }
+	get float magnitude() => sqrt(this->x * this->x + this->y * this->y);

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

By the term 'standard C compliant', what do I mean? ... actually I don't even know what anyone means by that term, because it's ambiguous! Do you mean the original K&R C? ANSI C? ISO C90? C95? C99? C11? C17? C2x? Or a particular compiler implementation?

But besides the various C 'standards', which often introduce or deprecate features, which immediately creates a moving target, the compilers themselves implement compiler specific extensions and features which are not always compatible with each other or 'the standard'.

Although I might have a 100% '*compliant*' parser for GCC, and I want it to be 100% 'standard C' compliant; there is actually NO compiler on the planet which is 100% 'standard C' compliant, because 'standard C' doesn't actually exist (without ambiguity); it means different things to different people at different times and in different contexts. You could say that your compiler is C11 compliant, but the 'C standard' is a moving target and always evolving. So what was once a 'C compliant' compiler, might no longer be compliant with 'the latest C standard'.

So, this is a 'best effort' attempt to support as many variations of the 'C standard' and C compilers as possible! I'm not there yet though! I just support GCC for now, but I would like to support at least GCC, Clang, MSVC, PCC, TCC and LCC in the future.

Once the language and compiler matures, I would welcome the input from **any** compiler devs to help me make it more compatible with their compilers.

## How does it work?

* The Super C Compiler `scc` calls GCC to pre-process your source file (expanding macros `#include`, `#define`, `#if` etc.).
* The first step creates a new `.sc.i` file, which contains the pre-processed Super C source code;
* The `.sc.i` file is loaded into the Super C compiler which creates a Super C AST;
* The Super C AST is converted into a standard C AST; (the most important step)
* From the standard C AST we generage a new `.i` file with the final standard C compliant code;
* The `.i` file is finally compiled by GCC into the final binary;
* The `.i` extension on files indicates to GCC that the file has already been preprocessed, so GCC skips that step;
* You will need to refer to the `.i` file during debugging, because GCC will be generating syntax errors from it!
* If you compiled a standard C file there would be nothing extra to convert.

So the Super C compiler is technically a source-to-source transpiler.

Currently, GCC is the only fully tested compiler, since most of my effort has been directed at the actual language features, and not compiler integration. But I fully intend to support multiple compilers, any help or suggestions from the compiler devs are welcome.

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

* *generics*
  ```C
  struct vec3<T> {
	T x;
	T y;
	T z;
  };
  ```
  eg. `vec3<float>` will just expand to:
  ```C
  struct vec3__float {
	float x;
	float y;
	float z;
  };
  ```
* JavaScript-inspired object destructuring. eg. `const { model, make, year } = this;`
* Initializer shorthand.
* `interfaces` from Java/C# and/or Rust-like `traits` - to improve polymorphism!
  * This will probably require a V-table, unless someone has a better suggestion?
* Primary Constructors inspired by Kotlin.
* anonymous functions
* nested functions
* `let` or `var`, or C++ style `auto` - automatic type inference
* `defer`
* 'null safe' operators - `?.` from TypeScript and Kotlin, and/or `?:` (GCC conflict) and/or `??`
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


## In loving memory of [Dennis Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie)!

# [FAQ](FAQ.md)
