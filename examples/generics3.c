typedef long int size_t;

struct Vec4<T, W, N> {
	const T x;
	T y;
	T z;
	W const w
		[N];
	const char * const a;
};

// struct HashTableNode
// 	<T>;

struct Matrix<T, M, N> {
	T mat[M][N];
};

struct Mat<T, M, N> {
	T mat[M][N];
};

struct Vector<T> {
	T *data;
	size_t size;
	size_t capacity;
};

typedef Vector<float>;

struct Vector2X<T, X> {
	struct Vector
		<T>
		vec;
	T *
		data;
	size_t size;
	size_t capacity;
};

struct test {
	int i;
};

// typedef Vector<float>;

struct LinkedListNode<T> {
	struct LinkedListNode
		<T> *
		next;
	struct test t;
	struct test2 {
		T value;
	} t2;
	struct Vector<T> vec;
	struct {
		T value;
	} test3;
	T value;
};

// struct TestX2;
typedef struct TestX2 TestX2;
// struct TestX2 {
// 	int value;
// };

struct TestX<T>;

typedef
TestX
<float>;

typedef
TestX
<double>;

struct TestX<T> {
	T value;
};

typedef TestX<float>;
typedef TestX<double>;


impl headers Vector<T>
{
	Vector<T> *new(size_t size)
	{
		Vector<T> *v = (Vector<T>*) malloc(sizeof(Vector<T>));
		v->data = (T*) malloc(sizeof(T) * size);
		v->size = size;
		v->capacity = size;
		return v;
	}

	void delete()
	{
		free(this->data);
		free(this);
	}
}



impl headers Vector<float>;


// T mat[M][N];

typedef Vec4<float, const char *, 4>;

typedef Mat<float, 0x4, 0x4>;

typedef LinkedListNode<float>;

int main(int argc, const char *argv[])
{
//	Vec4<float, double, 4> *v1 = new Vec4<float, double, 4>(1.0f, 2.0f, 3.0f, 4.0);
	Vec4<float, const char *, 4> v;

	Mat<float, 0x4, 0x4> mat4;


	LinkedListNode<float> ll;
}
