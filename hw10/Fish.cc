
// fish class

#include<vector>
#include<cmath>
#include<cstdlib> // for rand()
#include"Population.h"
#include "Angle.h"
#include "Fish.h"
#include "Point.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
Fish::Fish(double x, double y, double speed, std::vector<Fish*>* sea)
	: location(x, y)
	//direction(dir), // declaring non-default const for angle not needed for drunk
	  //t_rate(turn), // not needed for drunken
{
	this->speed = speed;
	this->sea = sea;
	sea->push_back(this); // saving itself to population, this is pointer

}

Fish::~Fish(){ // empty destructor for now

	sea->erase(this->getIndex()); // arg for this needs to be index?
	std::cout << "Removing fish from Vector in fish class" << std::endl;
}




// drunk version
void Fish::swim(){ // overriding the methid from fish

	// generate random directions
	// what if fish decides to go straight?
	int choice = rand()%4;
	if(choice == 0) location.setX(location.getX() + this->speed);
	else if(choice == 1) location.setY(location.getY() + this->speed);
	else if(choice == 2) location.setX(location.getX() - this->speed);
	else location.setY(location.getY() + this->speed);

}




Point Fish::whereIsFish() const{
	return location;
}

std::vector<Fish*>::iterator Fish::getIndex()const{
	int index = 0;
	std::vector<Fish*>::iterator it;
	std::cout << "getIndex: Created Iterator" << std::endl;
	for(it = this->sea->begin(); it != this->sea->end(); ++it){
		if(*it == this){
			std::cout << "getIndex: returning it" << std::endl;
			return it;
		}
		else{
			index++;
			std::cout << "getIndex: increment index" << std::endl;
		}

	}
	it = this->sea->begin();
	std::cout << "getIndex: couldn't find the index, decrement it--" << std::endl;
	it--; // return -1 index, which should return error in vector.erase
	return it; // couldn't find it
}



// compare opps , virtual this is
bool Fish::operator==(const Fish& fish) const{
	return ((this->location == fish.location) && (this->speed == fish.speed));
}


void Fish::printOp(std::ostream& out)const{
	out << "Just a FIsh.....\nLocation: "  << this->location << "Speed: " << this->speed;
}

// now printable
std::ostream& operator<<(std::ostream& out, const Fish& fish){
	//out << "Usual Fish: Location: " << fish.location;
	fish.printOp(out); // printOp in class, use the classname 
	// https://stackoverflow.com/questions/31365230/was-not-declared-in-the-scope-error
	return out;
}


