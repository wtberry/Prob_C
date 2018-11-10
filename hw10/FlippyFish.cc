
// fish class

#include<cmath>
#include<cstdlib> // for rand()
#include<vector>
#include "Angle.h"
#include "Fish.h"
#include "FlippyFish.h"
#include "Point.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
FlippyFish::FlippyFish(double x, double y, double speed, double dir, double turn, std::vector <Fish*>* sea)
	: Fish(x, y, speed, sea),
	  direction(dir), // declaring non-default const for angle
	  t_rate(turn)
	  //location(x, y) already in original fish class
{
	//this->speed = speed; // done in Fish
	//this->sea = sea; already in original fish class
	// sea->add(this); // saving itself to population, this is pointer, Done in Fish class

}

FlippyFish::~FlippyFish(){ // empty destructor for now
	// empty
}


void FlippyFish::swim(){ // not overriden

	// empty	
}


//Point FlippyFish::whereIsFish() const{
//	//return location; from Fish class
//}


// the getIndex for deleting
std::vector<Fish*>::iterator FlippyFish::getIndex() const{
// inherit from Fish
}


// compare opps
bool FlippyFish::operator==(const FlippyFish& ffish) const{
	return ((this->location == ffish.location) && (this->speed == ffish.speed) && (this->direction == ffish.direction) && (this->t_rate == ffish.t_rate));
}

// to be called by operator<<, overriden
void FlippyFish::printOp(std::ostream& out) const{
	out << "Flippy.....\nLocation: " << this->location << " Speed: " << this->speed << " \nDirection; " << this->direction << " turn_rate: " << this->t_rate;
}


// now printable
//std::ostream& operator<<(std::ostream& out, const Fish& fish){
//	fish.printOp(out);
//	return out;
//}

