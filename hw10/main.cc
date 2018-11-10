#include<vector>
#include "Angle.h"
#include "Fish.h"
#include "DrunkenFish.h"
#include "FlippyFish.h"
#include "Log.h"
#include "Point.h"
#include<iostream>
#include<cstdio>

int main(){
	// create logger object
	Log d = Log::getInstance();
	// create vector to test
	//Population atlantic;
	std::vector<Fish*> atlantic; 
	
	// create a new fish
	// add the fish in the thing??, so modify the fish methods??
	Fish fish1(12, -12, 5, &atlantic);
	//DrunkenFish drunk(30, 10, 15, &pacific);
	FlippyFish flip(22, 12, 1, 180, 40, &atlantic);
	DrunkenFish drunk(32, 21, 40, &atlantic);

	// test the print methods for both kine
	std::cout << "***** Testing the print methods for fishes *************" << std::endl;
	std::cout << fish1 << std::endl;
	std::cout << flip << std::endl;
	std::cout << drunk << std::endl;
	//
	std::cout << "where?? Flip: " << flip.whereIsFish() << std::endl;
	std::cout << "where?? Drunk: " << drunk.whereIsFish() << std::endl;


#if 0
	// release new fish into the pacific
	pacific.add(&f1);
	pacific.add(&f2);
	pacific.add(&f3);
	pacific.add(&f4);
#endif
	//testing out log function
	// print out all the fish in Pacific
	//std::cout << "Testing the Populations' print overload" << std::endl;
	//std::cout << atlantic << std::endl;



#if 0
	// search
	//int result = pacific.searchFish(&f2);
	std::cout << "search for f2 " << result << std::endl;

	// test the delete
	pacific.remove(&f3);
	std::cout << pacific << std::endl;
	
	
	// now test printing
	std::cout << f1 << std::endl;
	d.printd("test swim");
	f1.swim();
	std::cout << f1 << std::endl;


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
#endif

#if 1
	//NOW simulation time!!
	// make the ocean
	std::vector<Fish*> pacific;
	Point zero(0, 0); // the zero in the Atlantic
	//  create bunch of fish
	//  First Flippy
	FlippyFish flip1(0, 0, 10, 200, 40, &pacific);
	FlippyFish flip2(0, 0, 20, -200, -40, &pacific);
	FlippyFish flip3(0, 0, 30, 20, 50, &pacific);
	FlippyFish flip4(0, 0, 40, 40, 80, &pacific);
	FlippyFish flip5(0, 0, 50, 60, 150, &pacific);
	FlippyFish flip6(0, 0, 60, -120, 240, &pacific);
	// then give them some drink
	DrunkenFish drunk1(0, 0, 10, &pacific);
	DrunkenFish drunk2(0, 0, 20, &pacific);
	DrunkenFish drunk3(0, 0, 30, &pacific);
	DrunkenFish drunk4(0, 0, 40, &pacific);
	DrunkenFish drunk5(0, 0, 50, &pacific);
	DrunkenFish drunk6(0, 0, 60, &pacific);

	// now test the print methods for each fish in pacific
	std::cout << "######## Testing the printing in pacific fish ####### \n" << std::endl;
	// iterator
	std::vector <Fish*>::iterator it; // fist element
	for(it = pacific.begin(); it != pacific.end(); it++){
		std::cout << std::endl;
		std::cout << "forever loop" << std::endl;
		std::cout << **it << std::endl;
	}

	std::cout << "\n #### DONE testing for printing pacific fish ##### \n" <<std::endl;

#if 1
	// timer
	//for(int t=0; t<30; ++t){
	// reset the iterator
	it = pacific.begin();
	int t = 0;
	//while(it != pacific.end()){ // run until all the fish are dead
	while(t<10){
		std::cout << "\n######### TimeStamp: " << t << " #########\n" << std::endl;
		// otehr iterator
		std::vector<Fish*>::iterator j;
		for(int j=0; j <pacific.size(); j++){
			(*pacific[j]).swim();
			std::cout << (*pacific[j]) << std::endl;
			double distance  = (*pacific[j]).whereIsFish().euclid(zero);
			std::cout << "Distance: " << distance << "\n" << std::endl;
			//std::cout << "Forever loop??" << std::endl;
			if(distance > 100){
				std::cout << "************* DELETING FISH *******" << std::endl;
				delete pacific[j]; // delte the fish
				std::cout << "************* FISH DELETED *******" << std::endl;
				std::cout << "Seg fault??" << std::endl;
			}
		std::cout << "end of for loop " << std::endl;
		} // seg fault here
		t++;
		
		std::cout << "\n---------------------------------------------" << std::endl;

	}
#endif
#endif

}

