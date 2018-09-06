# orders of dependency does not matter
# orders of the lines won't matter, except the very top line, all: ...

all: main

calc.o: calc.cc calc.h
	g++ -c -Werror calc.cc

main.o: main.cc calc.h
	g++ -c -Werror main.cc

main: main.o calc.o
	g++ -o main main.o calc.o
