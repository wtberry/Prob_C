#ifndef ANGLE_H
#define ANGLE_H
#include<iostream>
#include"Log.h"
#include"Point.h"

class Point;

class Angle{

private:
	double angle;
	mutable double sin_val;
	mutable double cos_val;
	mutable bool have_sin;
	mutable bool have_cos;

public:
	Angle();
	Angle(double angle);
	virtual ~Angle();

	double getAngle() const; // don't forget const
	double getSin() const;
	double getCos() const;
	void setAngle(double angle);
	double resetAngle(double angle) const;
	void resetTrig(); // reset the trig bool to false
	void arnold() const;
	Angle operator+(const Angle& angle) const;
	Angle operator+=(const Angle& angle);
	Angle operator-=(const Angle& angle);
	Angle operator-(const Angle& angle) const;
	Angle operator*(const Angle& angle) const;
	Angle operator*=(const Angle& angle);
	Angle operator/=(const Angle& angle);
	Angle operator/(const Angle& angle) const;
	bool operator==(const Angle& angle) const;
	void operator=(const Angle& angle);
	void operator=(const double angle);


	// printable
	friend std::ostream& operator<<(std::ostream& out, const Angle& a);


}; // semicolon don't forget

//std::ostream& operator<<(std::ostream& out, const Angle& a);

#endif
