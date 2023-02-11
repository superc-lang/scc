
typedef struct {
	const char *make;
	const char *model;
	int year;
} Car;
typedef struct Test Test;
impl Car
{
	static int test()
	{
		Test *test = self;				//	NOT STATIC!
		Test test[10] = { self.foo };	//	NOT STATIC!

		Test *self;						//	AST_STATIC
		int self;						//	AST_STATIC
		Test *self[];					//	AST_STATIC
		Test self[];					//	AST_STATIC
		Test self[10] = { 0 };			//	AST_STATIC
	}

	static int static_member()
	{
		return 123;
	}

	static int non_static_member(/* &self */)
	{
		return 456;
	}
}

int main(int argc, const char *argv[])
{
	Car *car1;
	Car *car2;

	Car::static_member(car1, car2);		//	REAL STATIC!

	Car::non_static_member(car1);		//	ERROR!


	Car *car;

	car->static_member();				//	ERROR!

	car->non_static_member();			//	NOT STATIC!

	return 0;
}
