#include <stdio.h>

#include "lib.h"

int main(int argc, const char *argv[])
{
	MyStruct obj = { .a = 10, .b = 20 };

	printf("Add obj: %d\n", obj.add());
	printf("Sub obj: %d\n", obj.sub());

	MyStruct arr[2] = {{ .a = 50, .b = 80 }, { .a = 100, .b = 120 }};

	printf("Add arr[0]: %d\n", arr[0].add());
	printf("Sub arr[1]: %d\n", arr[1].sub());

	MyStruct *p = &obj;

	printf("Add obj: %d\n", p->add());
	printf("Sub obj: %d\n", p->sub());

	MyStruct *p2 = &arr[0];

	printf("Add p2[0]: %d\n", p2[0]->add());
	printf("Sub p2[1]: %d\n", p2[1]->sub());

	return 0;
}
