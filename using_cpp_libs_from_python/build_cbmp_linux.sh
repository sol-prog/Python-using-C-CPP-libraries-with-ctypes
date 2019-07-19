g++ -std=c++17 -Wall -Wextra -pedantic -fPIC -c cbmp.cpp
g++ -shared cbmp.o -o cbmp.so
rm cbmp.o
