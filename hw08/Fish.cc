
// fish class

#include<cmath>
#include<cstdlib> // for rand()
#include"Population.h"
#include "Angle.h"
#include "Fish.h"
#include "Point.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
Fish::Fish(double x, double y, double speed, double dir, double turn, Population* sea)
	: direction(dir), // declaring non-default const for angle
	  t_rate(turn),
	  location(x, y)
{
	this->speed = speed;
	this->sea = sea;
	sea->add(this); // saving itself to population, this is pointer

}

Fish::~Fish(){ // empty destructor for now
	sea->remove(this);
	std::cout << "Removing fish from population" << std::endl;
}


void Fish::swim(){

	// generate random directions
	// what if fish decides to go straight?
	int choice = rand()%3;
	if(choice == 0) direction -= t_rate;
	else if(choice == 2) direction += t_rate;

	//location.x += speed * direction.getCos(); // angle to x value
	//location.y += speed * direction.getSin(); // angle to y value
	std::cout << "y: " << speed*direction.getSin() << std::endl;
	std::cout << "x: " << speed*direction.getCos() << std::endl;

	location += Point(speed*direction.getCos(), speed*direction.getSin());
	
}

Point Fish::whereIsFish() const{
	return location;
}



// compare opps
bool Fish::operator==(const Fish& fish) const{
	return ((this->location == fish.location) && (this->speed == fish.speed) && (this->direction == fish.direction) && (this->t_rate == fish.t_rate));
}


// now printable
std::ostream& operator<<(std::ostream& out, const Fish& fish){
	out << "Location: " << fish.location << "Dir: "<< fish.direction.getAngle() << "\u00B0, " << "Turn Angle: " << fish.t_rate.getAngle() << "\u00B0";
	return out;
}

