// import
#include<iostream>
#include<cmath>
#include"Point.h"


// const
Point::Point(){
	x = 0;
	y = 0;
}

// const
Point::Point(double x, double y){
	this->x = x;
	this->y = y;
}

// get
double Point::getX() const{
	return x;
}
// get
double Point::getY() const{
	return y;
}
// set
void Point::setX(double x){
	this->x = x;
}

void Point::setY(double y){
	this->y = y;
}

// distance between two points
double Point::euclid(Point& point) const{
	int x_sq = pow((this->x - point.x), 2.0);
	int y_sq = pow((this->y - point.y), 2.0);
	return sqrt(x_sq + y_sq);
}
// operators overload

void Point::operator+=(const Point& point){
	this->x += point.x;
	this->y += point.y;
}

void Point::operator-=(const Point& point){
	this->x -= point.x;
	this->y -= point.y;
}


bool Point::operator==(const Point& point) const{
	return ((this->x == point.x)&&(this->y == point.y));
}

// printable
std::ostream& operator<<(std::ostream& out, const Point& point){
	out << "(" << point.x <<", " << point.y << ") ";
	return out;
}


