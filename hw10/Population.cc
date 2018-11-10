//Population class
//array to keep fish, and methods to maintain and monitor the fishes in the sea

#include<iostream>
#include"Population.h"
#include"Fish.h"
#define MAX_FISH 1000

// const
Population::Population(){
	index = -1;
	size = 0; // num of fish, do not declare it here, it'll be seg fault
	//Fish** sea; // this one line gives seg fault when .add method is called? why??
	sea = new Fish* [MAX_FISH]; // heap array
	std::cout << "Population created" << std::endl;
	std::cout << "3rd element" << sea[3] << std::endl;

}

// destructor
Population::~Population(){
	delete[] sea;
	std::cout << "Population deleted" << std::endl;
}

// add
void Population::add(Fish* fish){
	std::cout << "adding the pointer to list" << std::endl;
	std::cout << "what's in size??" << size << std::endl;
	this->sea[size++] = fish; // storing pointer to fish
}

// remove
void Population::remove(Fish* fish){
	// first look for the elememnt in the array
	this->index = searchFish(fish); // passing pointer & searching for fish

	std::cout << "search complete: fish at: " << index << std::endl;
	if (this->index == -1) {
		std::cout << "Fish you want to delete don't exist!" << std::endl;
	}
	else{
		// first delete the fish from the memory
		for(int i=this->index; (i+1)<this->size; ++i){
			sea[i] = sea[i+1]; // assgin new addr for null
			sea[i+1] = NULL; // set it to null
		}
		size--; //decrement the numbers of fish
	}
}

int Population::getSize() const{
	return this->size; // return the size of fish
}

// get
Fish* Population::get(int search_index) const{
	return sea[search_index]; // return the pointer to the fish
}

// searchFish
int Population::searchFish(Fish* fish) const{
	//
	for(int i = 0; i<this->size; ++i){
		if(*sea[i] == *fish) return i; // found it, return its index

	}
	return -1; // not found, return -1
}

Fish& Population::operator[](int ind) const{
	if((ind > size) || ind < 0 ){
		std::cout << "Index Out of Range for Population class" << std::endl;
	}
	else return *(sea[ind]); // why is this legal?? obj to reference??
}

// printable
std::ostream& operator<<(std::ostream& out, const Population& water){
	for(int i=0; i<water.size; ++i){
		out << "fish " << i+1 << " " << *(water.sea[i]) << "\n";
	}
	return out;
}

