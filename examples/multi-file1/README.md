#### Compile with (from root dir):

```bash
./scc ./examples/multi-file1/main.c ./examples/multi-file1/lib.c -o test && ./test
```

#### expected output:

```txt
Add obj: 30
Sub obj: -10
Add arr[0]: 130
Sub arr[1]: -20
Add obj: 30
Sub obj: -10
Add p2[0]: 130
Sub p2[1]: -20
```

### C Output

#### main.i

```c
typedef struct {
	int a;
	int b;
} MyStruct;

static inline int MyStruct__add(MyStruct *self)
{
	return self->a + self->b;
}

int MyStruct__sub(MyStruct *self);

int main(int argc, const char *argv[])
{
	MyStruct obj = {.a = 10, .b = 20};
	printf("Add obj: %d\n", MyStruct__add(&obj));
	printf("Sub obj: %d\n", MyStruct__sub(&obj));
	MyStruct arr[2] = {{.a = 50, .b = 80}, {.a = 100, .b = 120}};
	printf("Add arr[0]: %d\n", MyStruct__add(&arr[0]));
	printf("Sub arr[1]: %d\n", MyStruct__sub(&arr[1]));
	MyStruct *p = &obj;
	printf("Add obj: %d\n", MyStruct__add(p));
	printf("Sub obj: %d\n", MyStruct__sub(p));
	MyStruct *p2 = &arr[0];
	printf("Add p2[0]: %d\n", MyStruct__add(&p2[0]));
	printf("Sub p2[1]: %d\n", MyStruct__sub(&p2[1]));
	return 0;
}
```

#### lib.i

```c
typedef struct {
	int a;
	int b;
} MyStruct;

static inline int MyStruct__add(MyStruct *self)
{
	return self->a + self->b;
}

int MyStruct__sub(MyStruct *self);

int MyStruct__sub(MyStruct *self)
{
	return self->a - self->b;
}
```
