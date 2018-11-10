#ifndef FLIPPYFISH_H // always declare the class first, before includes anything
#define FLIPPYFISH_H
#include<vector>
#include<iostream>
#include<cmath>
#include"Angle.h"
#include"Point.h"
#include"Log.h"


class Point;

class FlippyFish : public Fish{

private:
	//Point location;
	//double speed; //speed is always positive
	Angle <double>direction;
	Angle  <double>t_rate; // turning rate
	//Population* sea; // reference to population

public:
	FlippyFish(double x, double y, double speed, double dir, double turn, std::vector <Fish*>* sea);
	virtual ~FlippyFish();

	//double getPosition() const; // don't forget const
	//void setPosition(double angle);
	//double resetFish(double angle) const;
	//void resetTrig(); // reset the trig bool to false
	//void arnold() const;
	void swim(); // using Fish's class's one

	virtual std::vector<Fish*>::iterator getIndex() const;
	virtual void printOp(std::ostream& out) const;
	bool operator==(const FlippyFish& ffish) const;


	// printable
	//friend std::ostream& operator<<(std::ostream& out, const FlippyFish& ffish);

}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Fish& a);

#endif

