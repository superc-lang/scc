## Generics

Compile from root dir:
```bash
./scc -lm -g -ast -Wall ./examples/multi-file6-generics/main.c ./examples/multi-file6-generics/vec3f.c -o test
```

Run:
```bash
./test
```


#### main.c

```c
```

#### expected output:

```txt
v1 = (1.000000, 2.000000, 3.000000)
v2 = (4.000000, 5.000000, 6.000000)
Magnitude of v1 = 3.741657
Magnitude of v2 = 8.774964
v1 == v2: false
v1 == v2: true
The dot product of v1 & v2: 77.000000
v1 = (0.455842, 0.569803, 0.683763)
```

### C Output

#### main.i

```c
```

---

#### trait.i

```c
```
