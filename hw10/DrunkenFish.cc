
// fish class

#include<cmath>
#include<cstdlib> // for rand()
#include<vector>
#include "Angle.h"
#include "Fish.h"
#include "DrunkenFish.h"
#include "Point.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
DrunkenFish::DrunkenFish(double x, double y, double speed, std::vector <Fish*>* sea)
	: Fish(x, y, speed, sea) // using fish class const
	  //location(x, y) Done in Fish class
{
	//this->speed = speed; done in Fish
	//this->sea = sea; Done in the fish class
	// sea->add(this); // Done in Fish class

}

DrunkenFish::~DrunkenFish(){ 
	// inherit from fish
	std::cout << "DrunkDestructor: is this called??" << std::endl;
}


void DrunkenFish::swim(){ // overriding the methid from fish

	// generate random directions
	// what if fish decides to go straight?
	int choice = rand()%4;
	if(choice == 0) location.setX(location.getX() + this->speed);
	else if(choice == 1) location.setY(location.getY() + this->speed);
	else if(choice == 2) location.setX(location.getX() - this->speed);
	else location.setY(location.getY() + this->speed);

}


//Point DrunkenFish::whereIsFish() const{
//	// from Fish
//}



// compare opps // dunno if this should be overrided
bool DrunkenFish::operator==(const DrunkenFish& dfish) const{
	// inherited
}

// the getIndex for deleting
std::vector<Fish*>::iterator DrunkenFish::getIndex() const{
// inherit from Fish
}



// to be called from printable, overriden
void DrunkenFish::printOp(std::ostream& out) const{
	out << "Drunk...\nLocation: " << this->location << "Speed: " << this->speed;
}

// now printable
// not overriding because not part of fish class??
//std::ostream& operator<<(std::ostream& out, const Fish& fish){
//	fish.printOp(out);
//	return out;
//}

