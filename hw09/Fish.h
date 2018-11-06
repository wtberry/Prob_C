#ifndef FISH_H // always declare the class first, before includes anything
#define FISH_H

#include<iostream>
#include<cmath>
#include"Angle.h"
#include"Point.h"
#include"Population.h"
#include"Log.h"


class Angle;
class Point;
class Population;

class Fish{

protected: // only for subclass
	Point location;
	double speed; //speed is always positive
	Population* sea; // reference to population
	//Angle direction;
	// these following 2 variables are only in the Flippy, not Drunk
	//Angle  t_rate; // turning rate

public:
	Fish(double x, double y, double speed, Population* sea);
	virtual ~Fish();

	//double getPosition() const; // don't forget const
	//void setPosition(double angle);
	//double resetFish(double angle) const;
	//void resetTrig(); // reset the trig bool to false
	//void arnold() const;
	virtual void swim(); // override it in drunken fish
	Point whereIsFish() const;
	virtual bool operator==(const Fish& fish) const;

	// to be called << overload
	virtual void printOp(std::ostream& out) const;

	// printable
	friend std::ostream& operator<<(std::ostream& out, const Fish& fish);

}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Fish& a);

#endif

