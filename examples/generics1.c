#include <stdlib.h>
#include <stdio.h>

struct Example<T>
{
	T m_value;
};

impl src Example<T>
{
	Example<T> *new(T value)
	{
		Example<T> *v = (Example<T> *) malloc(sizeof(Example<T>));

		v->m_value = value;

		return v;
	}

	//	WARNING: I cannot have a 'getter' with the same name as one of the struct properties!
	//	Currently, I cannot detect this scenario! But will implement this check soon!
	//	get T value() => self->value;	//	notice the 'getter' is called 'value', AND the return is called 'value'!
	get T value() const => self->m_value;

	set T value(T value) => self->m_value = value;

	T get_value() const => self->m_value;

	get T *get_ptr() => &self->m_value;
}

typedef Example<const char *>;
typedef Example<int>;
typedef Example<float>;
typedef Example<double>;

impl src Example<const char *>;
impl src Example<int>;
impl src Example<float>;
impl src Example<double>;

//	structure to 'embedded' inside the 'generic' `Example<T>`
typedef struct MyStruct {
	int a;
	int b;
} MyStruct;

typedef Example<MyStruct>;
typedef Example<MyStruct*>;

impl src Example<MyStruct>;
impl src Example<MyStruct*>;


int main(int argc, const char *argv[])
{
	Example<const char *> *string_example = new Example<const char *>("Hello, World!");
	Example<int> *integer_example = new Example<int>(42);
	Example<float> *float_example = new Example<float>(42.42);
	Example<double> *double_example = new Example<double>(42.42);

	MyStruct my_struct = { 56, 78 };
	Example<MyStruct> *MyStruct_example = new Example<MyStruct>(my_struct);

	MyStruct my_struct_ptr = { 67, 89 };
	Example<MyStruct*> *MyStruct_ptr_example = new Example<MyStruct*>(&my_struct_ptr);

	//	NOTE: This variant is not working for generics yet!
	// Example<const char *> *string_example = Example<const char *>::new("Hello, World!");
	// Example<int> *integer_example = Example<int>::new(42);

	printf("\nGenerics using a 'getter' method\n");
	printf("%s\n", string_example->value);
	printf("%d\n", integer_example->value);
	printf("%f\n", float_example->value);
	printf("%f\n", double_example->value);
	printf("MyStruct_example: a == %d\n", MyStruct_example->value.a);
	printf("MyStruct_example: b == %d\n", MyStruct_example->value.b);
	printf("MyStruct_ptr_example: a == %d\n", MyStruct_ptr_example->value->a);
	printf("MyStruct_ptr_example: b == %d\n", MyStruct_ptr_example->value->b);

	printf("\nGenerics using a standard method call\n");
	printf("%s\n", string_example->get_value());
	printf("%d\n", integer_example->get_value());
	printf("%f\n", float_example->get_value());
	printf("%f\n", double_example->get_value());
	printf("MyStruct_example: a == %d\n", MyStruct_example->get_value().a);
	printf("MyStruct_example: b == %d\n", MyStruct_example->get_value().b);
	printf("MyStruct_ptr_example: a == %d\n", MyStruct_ptr_example->get_value()->a);
	printf("MyStruct_ptr_example: b == %d\n", MyStruct_ptr_example->get_value()->b);

	printf("\nGenerics using a 'setter'\n");
	printf("%s\n", string_example->value = "Hello, World 2!");
	printf("%d\n", integer_example->value = 24);
	printf("%f\n", float_example->value = (float) 99999.99);
	printf("%f\n", double_example->value = (double) 99999.99);

	fputc('\n', stdout);

	//	'setters' with embedded structures don't work if you return them 'by value'!
	// printf("%d\n", MyStruct_example->value.a = 123);
	// printf("%d\n", (MyStruct_example->value).a = 123);
	// printf("MyStruct_example: a == %d\n", MyStruct_example->value.a);

	//	However, if you return the internal structure by pointer, then you can use 'setters'!
	printf("MyStruct_example: set `a` using ptr: %d\n", MyStruct_example->get_ptr->a = 456);
	printf("MyStruct_example: get `a` using ptr: %d\n", MyStruct_example->get_ptr->a);

	fputc('\n', stdout);

	//	However, 'setters' with pointers to structures will work!
	printf("MyStruct_ptr_example: set a struct value with a 'setter': %d\n", MyStruct_ptr_example->value->a = 123);
	printf("MyStruct_ptr_example: testing value set with a 'getter': %d\n", MyStruct_ptr_example->value->a);
}
