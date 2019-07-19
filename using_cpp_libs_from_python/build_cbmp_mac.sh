clang++ -std=c++17 -Wall -Wextra -pedantic -fPIC -c cbmp.cpp
clang++ -shared cbmp.o -o cbmp.dylib
rm cbmp.o
