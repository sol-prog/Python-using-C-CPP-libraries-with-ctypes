gcc -std=c11 -Wall -Wextra -pedantic -fPIC -c mylib.c
gcc -shared mylib.o -o mylib.so
rm mylib.o
