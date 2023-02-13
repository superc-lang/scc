// Check the output on Godbolt!
// https://godbolt.org/z/TvGT4WEbz

// For the purposes of our examples, we don't need the `include` files yet.
// If you want to actually compile this example with GCC or your compiler, you'll need to add them!

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	const char *make;
	const char *model;
	int year;
} Car;

impl Car
{
	Car *new(const char *make, const char *model, int year)
	{
		Car *car = (Car *) malloc(sizeof(Car));

		car->make = make;
		car->model = model;
		car->year = year;

		return car;
	}

	get static inline int age() => 2023 - self->year;

	const char *make_model()
	{
		static char make_model[128];

		sprintf(make_model, "%s %s", self->make, self->model);

		return make_model;
	}

	void delete()
	{
		free(self);
	}
}

int main(int argc, char *argv[])
{
	Car *car = new Car("Ford", "Mustang", 1969);
	// Car *car3 = Car::new("Ford", "Mustang", 1969);	//	Alternative syntax!

	printf("Car make, model & year: %s %d\n", car->make_model(), car->year);
	printf("Age: %d\n", car->age);

	delete car;

	return 0;
}
