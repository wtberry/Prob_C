all: main

main.o: main.cc Angle.h Fish.h Log.h Population.h
	g++ -c -Werror main.cc

fish.o: Fish.cc Angle.h Fish.h Log.h
	g++ -c -Werror Fish.cc 

angle.o: Angle.cc Angle.h Log.h
	g++ -c -Werror Angle.cc

log.o: Log.cc
	g++ -c -Werror Log.cc

main: main.o Population.o Fish.o Angle.o Log.o
	g++ -o main main.o Population.o Fish.o Angle.o Log.o
