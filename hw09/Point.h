// point class h file
#ifndef POINT_H
#define POINT_H

#include<iostream>

class Point{
private:
	int x;
	int y;

public:
	Point();
	Point(double x, double y);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double euclid(Point& point) const;
	// now operator overloads
	void operator+=(const Point& point);
	void operator-=(const Point& point);
	bool operator==(const Point& point) const;

	// printable with friend
	friend std::ostream& operator<<(std::ostream& out, const Point& point);

}; // don't forget the f semicolon;;;;;;;;;;;

#endif
