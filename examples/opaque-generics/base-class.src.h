#include <stdlib.h>

#include "base-class.h"

struct Foo<T> {
	T m_value;
};

impl source Foo<T>
{
	Foo<T> *new(T value)
	{
		Foo<T> *foo = (Foo<T>*) malloc(sizeof(Foo<T>));
		foo->m_value = value;
		return foo;
	}

	get T value() const => this->m_value;
	set T value(T value) => this->m_value = value;

	T mul(T value) const => this->m_value * value;

	void delete()
	{
		free(this);
	}
}
