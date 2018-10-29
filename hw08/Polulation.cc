// population class
#include<iostream>
#include"Angle.h"
#include"Fish.h"
#include"Population.h"

// Constructor
Population::Population(int max_size){
	this->max_size = max_size;
	this->size = 0; // zero fish so far
	// call fish??
	// create array
	Fish** sea; // pointer to pointer array
	sea = new Fish* [max_size]; // array of pointers to fish
}

//add fish
void Population::add(Fish& fish){
	// add the reference into the array
	// add and increment
	sea[size++] = fish; // would this store the fish itself?? 
}
