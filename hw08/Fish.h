#ifndef FISH_H // always declare the class first, before includes anything
#define FISH_H
#include<iostream>
#include"Angle.h"
#include"Log.h"

class Angle;
class Population;

class Fish{

private:
	double x;
	double y;
	double speed; //speed is always positive
	Angle direction;
	Angle  t_rate; // turning rate
	Population* sea; // reference to population

public:
	Fish(double x, double y, double speed, double dir, double turn, Population* sea);
	virtual ~Fish();

	//double getPosition() const; // don't forget const
	//void setPosition(double angle);
	//double resetFish(double angle) const;
	//void resetTrig(); // reset the trig bool to false
	//void arnold() const;
	void swim(); // decide random angle to swim to
	struct whereIsFish() const;
	bool operator==(const Fish& fish) const;


	// printable
	friend std::ostream& operator<<(std::ostream& out, const Fish& a);

}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Fish& a);

#endif

