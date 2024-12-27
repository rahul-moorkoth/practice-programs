# practice-code
repo for coding practice

# Commands to create shared library file
gcc -shared -fPIC -o libmylib.so my_lib.c my_lib_2.c
gcc -o main main.c -L. -lmylib
export LD_LIBRARY_PATH=.:.:
./main

# Commands to create static library file
gcc -c mylib.c
ar rcs libmylib.a mylib.o
