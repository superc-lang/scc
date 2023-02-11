typedef struct {
	int a;
	int b;
} MyStruct;

impl MyStruct {
	static inline int add() => self.a + self.b;
	int sub();
}
