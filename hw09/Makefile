all: main

main.o: main.cc Point.h Angle.h Fish.h Log.h Population.h FlippyFish.h DrunkenFish.h
	g++ -c -Werror main.cc

fish.o: Fish.cc Point.h Angle.h Fish.h Log.h
	g++ -c -Werror Fish.cc 


FlippyFish.o: FlippyFish.cc Point.h Angle.h Fish.h Log.h FlippyFish.h
	g++ -c -Werror FlippyFish.cc

DrunkenFish.o: DrunkenFish.cc Point.h Angle.h Fish.h Log.h DrunkenFish.h
	g++ -c -Werror DrunkenFish.cc

angle.o: Angle.cc Point.h Angle.h Log.h
	g++ -c -Werror Angle.cc

point.o: Point.cc Point.h 
	g++ -c -Werror Point.cc

log.o: Log.cc
	g++ -c -Werror Log.cc

main: main.o Population.o Fish.o FlippyFish.o Angle.o Log.o Point.o DrunkenFish.o
	g++ -o main main.o Population.o Fish.o FlippyFish.o Angle.o Log.o Point.o DrunkenFish.o
