#ifndef DRUNKUNFISH_H // always declare the class first, before includes anything
#define DRUNKUNFISH_H
#include<vector>
#include<iostream>
#include<cmath>
#include"Angle.h"
#include"Point.h"
#include"Population.h"
#include"Log.h"

// Arent these inherited from Fish??
class Point;
class Population;

class DrunkenFish : public Fish {

private:
	// everything needed should be present in Fish class
	//Point location;
	//double speed; //speed is always positive
	//Angle direction;
	//Angle  t_rate; // turning rate
	//Population* sea; // reference to population

public:
	DrunkenFish(double x, double y, double speed, std::vector <Fish*>* sea);
	virtual ~DrunkenFish(); //?? only in the fish class?

	//double getPosition() const; // don't forget const
	//void setPosition(double angle);
	//double resetFish(double angle) const;
	//void resetTrig(); // reset the trig bool to false
	//void arnold() const;
	virtual void swim(); // override it
	//Point whereIsFish() const;
	

	//Point whereIsFish() const;
	bool operator==(const DrunkenFish& dfish) const; // needs to override?
	virtual std::vector<Fish*>::iterator getIndex() const;
	// printOp to be called by the operator<<
	virtual void printOp(std::ostream& out) const;

	// printable
	//friend std::ostream& operator<<(std::ostream& out, const DrunkenFish& dfish);

}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Fish& a);

#endif

