#include <stdio.h>

#include "opaque-generic.h"

int main(int argc, const char *argv[])
{
	Foo<int> *i = new Foo<int>(123);
	Foo<float> *f = new Foo<float>(456.3f);

	int i_mul = 3;
	float f_mul = 6.9f;

	printf(
		"\n"
		"Super C example demonstrating `opaque generics`\n"
		"-----------------------------------------------\n"
		"\n"
	);

	//	NOTE: `i->value` is actually a 'getter'!
	printf("int value = %d * %d == %d\n", i->value, i_mul, i->value * i->mul(i_mul));
	printf("float value = %.2f * %.2f == %.2f\n", f->value, f_mul, f->value * f->mul(f_mul));

	delete i;
	delete f;

	return 0;
}
