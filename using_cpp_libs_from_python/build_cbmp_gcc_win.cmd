g++ -std=c++17 -Wall -Wextra -pedantic -fPIC -DBUILD_CBMP -c cbmp.cpp
g++ -shared cbmp.o -o cbmp.dll
del cbmp.o
