all: main

main: main.o function.o
	g++ -o main main.o function.o

main.o: main.cc util.h
	g++ -c -Werror main.cc

function.o: function.cc util.h
	g++ -c -Werror function.cc
