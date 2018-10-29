
// fish class

#include<cmath>
#include<cstdlib> // for rand()
#include"Population.h"
#include "Angle.h"
#include "Fish.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
Fish::Fish(double x, double y, double speed, double dir, double turn, Population* sea)
	: direction(dir), // declaring non-default const for angle
	  t_rate(turn)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->sea = sea;
	sea->add(this); // saving itself to population, this is pointer

	struct location{
		int x_;
		int y_;
	};
	
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

	x += speed * direction.getCos(); // angle to x value
	y += speed * direction.getSin(); // angle to y value
	
}

struct Fish::whereIsFish() const{
	struct foud_it;
	found_it.x_ = this->x;
	found_it.y_ = this->y;

	return found_it;
}



// compare opps
bool Fish::operator==(const Fish& fish) const{
	return ((this->x == fish.x) && (this->y == fish.y) && (this->speed == fish.speed) && (this->direction == fish.direction) && (this->t_rate == fish.t_rate));
}


// now printable
std::ostream& operator<<(std::ostream& out, const Fish& fish){
	out << "Location: " << "(" << fish.x <<", " << fish.y << ") " << "Dir: "<< fish.direction.getAngle() << "\u00B0, " << "Turn Angle: " << fish.t_rate.getAngle() << "\u00B0";
	return out;
}

