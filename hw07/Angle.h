#include<iostream>
#ifndef ANGLE_H
#define ANGLE_H

class Angle{

private:
	double angle;

public:
	Angle();
	Angle(double angle);
	virtual ~Angle();

	double getAngle() const; // don't forget const
	void setAngle(double angle);
	double resetAngle(double angle) const;
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
