
// fish class

#include<cmath>
#include<cstdlib> // for rand()
#include "Angle.h"
#include<iostream>

// MAYBE use construct to get argumnets here??
Fish::Fish(double x, double y, unsigned double speed, double direction, double t_rate){
	// empty const for fish, calls empty const
	x = 0;
	y = 0;
	speed = 0;
	Angle direction(direction);
	Angle t_rate(t_rate);
}

Fish::~Fish(){ // empty destructor for now
}


Fish::swim(){

	// generate random directions
	// what if fish decides to go straight?
	int choice = rand()%3;
	if(choice == 0) direction -= t_rate;
	else if(choice == 2) direction += t_rate;

	x += speed * direction.getCos(); // angle to x value
	y += speed * direction.getSin(); // angle to y value
	
}

// now printable
std::ostream& operator<<(std::ostream& out, const Fish& fish){
	out << fish.angle << "\u00B0";
	return out;
}

