all: main

mat_util.o: mat_util.cc mat_calc.h
	g++ -c -Werror mat_util.cc

main.o: main.cc mat_calc.h
	g++ -c -Werror main.cc 

main: main.o mat_util.o
	g++ -o main main.o mat_util.o
