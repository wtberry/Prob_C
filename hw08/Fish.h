#include<iostream>
#ifndef FISH_H
#define FISH_H

class Fish{

private:
	double x;
	double y;
	unsigned double speed; //speed is always positive
	Fish direction;
	Fish t_rate; // turning rate

public:
	Fish(double x, double y);
	virtual ~Fish();

	double getPosition() const; // don't forget const
	void setPosition(double angle);
	//double resetFish(double angle) const;
	//void resetTrig(); // reset the trig bool to false
	//void arnold() const;
	void swim(); // decide random angle to swim to


	// printable
	friend std::ostream& operator<<(std::ostream& out, const Fish& a);

}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Fish& a);

#endif

