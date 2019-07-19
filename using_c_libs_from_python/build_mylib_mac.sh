clang -std=c11 -Wall -Wextra -pedantic -fPIC -c mylib.c
clang -shared mylib.o -o mylib.dylib
rm mylib.o
