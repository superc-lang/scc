## Opaque Generics

'opaque generics' are a way to implement *generic* types where only the interface is exposed to the user.

This is related to the concept of 'private implementations' (or 'pimpl' for short).

'private implementations' allow you to 'hide' the implementation details of an object.
There are many reasons for doing this, but the most common advantage is to allow you to change the implementation without breaking the interface.

Another advantage is that it increases compilation times, because the compiler only needs to compile the interface, not the implementation.

An example of this is the `FILE` type in C. The implementation of `FILE` is hidden from the user, and the user only interacts with the interface.

---

Compile from root dir:
```bash
./scc -g -ast -Wall ./examples/multi-file6-generics/main.c ./examples/multi-file6-generics/vec3f.c
```

Run:
```bash
./a.out
```


#### main.c

```c
```

#### expected output:

```txt
Super C example demonstrating `opaque generics`
-----------------------------------------------

int value = 123 * 3 == 45387
float value = 456.30 * 6.90 == 1436646.75
```

### C Output

#### main.i

```c
```

---

#### trait.i

```c
```
