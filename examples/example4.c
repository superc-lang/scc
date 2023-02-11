typedef struct Foo Foo;

struct Foo {
	int value;
};

int test() {
	return 0;
}

// NOTE: The ONLY valid `static` member here, will be for `new`! Which is always implied to be `static`!
impl Foo
{
	static void non_static_member()
	{
		self.value = 10;
	}

	static void non_static_const_member() const	//	Foo *const self
	{
		self.value;
	}

	get static int getter();

	set static int setter(int value)
	{
		self.value = value;
	}

	Foo *new();
	void delete();
}

impl static Foo
{
	int size_of() => sizeof(Foo);

	static void static_member()
	{

	}

	int test_decl(Foo *self);
	int test_const(const Foo *self);
}

typedef long int size_t;

impl static size_t
{
	get static size_t min() => 0;
	get static size_t max() => 0xFFFFFFFFFFFFFFFF;
}

int main(int argc, const char *argv[])
{
	Foo *foo;

	Foo.static_member();			//	REAL STATIC member!
	foo->non_static_member();		//	'NON STATIC' member!

	Foo.size_of();
	Foo::size_of();

	// Foo.non_static_member();		//	ERROR! ... because `non_static_member` requires an instance of `Foo`!
	// foo->static_member();		//	ERROR! ... because `static_member` requires NO instance of `Foo`!

	foo->non_static_const_member();

	foo->getter;

	Foo *bar = Foo.new();
	Foo *baz = new Foo();

	delete bar;
	delete baz;

	size_t.min;
	size_t::min;

	Foo f;
	f.getter;

	Foo arr[10];

	arr[4].getter;

	Foo.static_member(&arr[4]);

	return 0;
}
