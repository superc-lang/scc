#! /bin/sh

# To run the script from the base `scc` folder:
# ./examples/opaque-generics/run.sh

clear
make clean
rm -f a.out
make
#../../scc -g -ast -Wall main.c opaque-generic.c
./a.out
