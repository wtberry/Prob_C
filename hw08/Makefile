all: main

main.o: main.cc Point.h Angle.h Fish.h Log.h Population.h
	g++ -c -Werror main.cc

fish.o: Fish.cc Point.h Angle.h Fish.h Log.h
	g++ -c -Werror Fish.cc 

angle.o: Angle.cc Point.h Angle.h Log.h
	g++ -c -Werror Angle.cc

point.o: Point.cc Point.h
	g++ -c -Werror Point.cc

log.o: Log.cc
	g++ -c -Werror Log.cc

main: main.o Population.o Fish.o Angle.o Log.o Point.o
	g++ -o main main.o Population.o Fish.o Angle.o Log.o Point.o
