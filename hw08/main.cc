#include"Population.h"
#include "Angle.h"
#include "Fish.h"
#include "Log.h"
#include "Point.h"
#include<iostream>
#include<cstdio>

int main(){
	// create logger object
	Log d = Log::getInstance();
	// create the population
	Population pacific;
	
	// create a new fish
	Fish f1(12, -12, 5, 80, 20, &pacific);
	Fish f2(30, 10, 15, 10, 30, &pacific);
	Fish f3(22, 12, 1, 180, 40, &pacific);
	Fish f4(-59, 100, 3, 200, 4, &pacific);


#if 0
	// release new fish into the pacific
	pacific.add(&f1);
	pacific.add(&f2);
	pacific.add(&f3);
	pacific.add(&f4);
#endif
	//testing out log function
	// print out all the fish in Pacific
	std::cout << pacific << std::endl;

	// search
	int result = pacific.searchFish(&f2);
	std::cout << "search for f2 " << result << std::endl;

	// test the delete
	pacific.remove(&f3);
	std::cout << pacific << std::endl;
	
	
	// now test printing
	std::cout << f1 << std::endl;
	d.printd("test swim");
	f1.swim();
	std::cout << f1 << std::endl;

	//NOW simulation time!!
	// make the ocean
	Population atlantic; // no () needed for empty const
	Point zero(0, 0); // the zero in the Atlantic

	// create fish
	Fish salmon(0, 0, 50, 20, 80, &atlantic);	
	Fish tuna(0, 0, 100, -100, 130, &atlantic);
	Fish sushi(0, 0, 2.4, 43.22, 4.5, &atlantic);
	Fish catfish(0, 0, 3, 20, 0, &atlantic);
	Fish nemo(0, 0, 2, 350, -80, &atlantic);
	Fish greatWhite(0, 0, 40, 300, 300, &atlantic);
	Fish hammerHead(0, 0, 30, 200, 200, &atlantic);
	Fish blackBeard(0, 0, 10, 10, 78.3, &atlantic);

	blackBeard.~Fish(); // delete the fish
	// timer
	//for(int t=0; t<30; ++t){
	int t = 0;
	while(atlantic.getSize() > 0){ // run until all the fish are dead
		std::cout << "\n######### TimeStamp: " << t << " #########\n" << std::endl;
		for(int f=0; f<atlantic.getSize(); ++f){
			atlantic[f].swim();
			std::cout << atlantic[f] << std::endl;
			double distance  = atlantic[f].whereIsFish().euclid(zero);
			std::cout << "Distance: " << distance << std::endl;
			if(distance > 100){
				atlantic[f].~Fish(); // delte the fish
				std::cout << "************* FISH DELETED *******" << std::endl;
			}
		}
		t++;
		std::cout << "\n---------------------------------------------" << std::endl;

	}

}

