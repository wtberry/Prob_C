all: main

main.o: main.cc util.h
	g++ -c -Werror main.cc

util.o: util.cc util.h
	g++ -c -Werror util.cc
	
main: main.o util.o
	g++ -o main main.o util.o

