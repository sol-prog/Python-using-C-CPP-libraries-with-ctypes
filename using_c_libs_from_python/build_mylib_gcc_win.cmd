gcc -std=c11 -Wall -Wextra -pedantic -fPIC -DBUILD_MYLIB -c mylib.c
gcc -shared mylib.o -o mylib.dll
del mylib.o
