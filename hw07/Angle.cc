// Angle class
// getter and setter
// const and destruct
// overloading arithmatic ops
//
#include<cmath>
#include<cstdio>
#include "Angle.h"
#include<iostream>

#define ROUND 360

// std::absolute value and %
Angle::Angle(){
	// empty const, initialize angle to 0
	this->angle = 0;
}

Angle::Angle(double angle){
	// standard const with input
	// make sure the angle is correct ranage
	this->angle = this->resetAngle(angle); 
}

Angle::~Angle(){ // empty destructor for now
}

// getter
double Angle::getAngle() const{
	// return value angle
	return angle;
}

// setter
void Angle::setAngle(double angle) { // modify the angle, so no const
	// set new angle
	this->angle = resetAngle(angle);
}

double Angle::resetAngle(double angle) const{
	// use std::abs() instead of just abs(), to return abs as double
	int tmp = angle/ROUND; // integer portion of the quotient
	double remain = std::abs(angle) - std::abs(tmp * ROUND); // remainder 
	if ((angle>=0) || (std::abs(angle)==ROUND)){
		return remain;
	}
	else{ 
		return -remain + ROUND;	
	}
}

void Angle::arnold() const{
	std::cout << "Division by 0,  terminating the program1n" << std::endl;
	exit(1);
}


// overload`
Angle Angle::operator+(const Angle& angle) const{
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	return Angle(this->resetAngle((this->angle + angle.angle)));
}

Angle Angle::operator+=(const Angle& angle) {
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	this->angle += angle.angle;
	this->angle = resetAngle(this->angle);
}

Angle Angle::operator-(const Angle& angle) const{
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	return (*this)+(-angle.getAngle()); // using + method for -
}

Angle Angle::operator-=(const Angle& angle) {
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	this->angle -= angle.angle;
	this->angle = resetAngle(this->angle);
}
//Angle ngle::operator-(const Angle& angle) const{
//	return Angle(this->resetAngle(this->angle - angle.angle));
//}

Angle Angle::operator*(const Angle& angle) const{
	return Angle(this->resetAngle(this->angle * angle.angle));
}

Angle Angle::operator*=(const Angle& angle) {
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	this->angle *= angle.angle;
	this->angle = resetAngle(this->angle);
}
Angle Angle::operator/(const Angle& angle) const{
	// make sure no zero division
	if(angle.angle == 0) arnold();
	else{
	return Angle(this->resetAngle(this->angle / angle.angle));
	}
}

Angle Angle::operator/=(const Angle& angle) {
	// why can I access angle by angle.angle, not getAngle? thought it was private?
	if(angle.angle == 0) arnold();
	this->angle /= angle.angle;
	this->angle = resetAngle(this->angle);
}

void Angle::operator=(const Angle& angle){
	this->angle = this->resetAngle(angle.angle);
}

void Angle::operator=(const double angle){
	this->angle = this->resetAngle(angle);
}
bool Angle::operator==(const Angle& angle)const{
	if(this->angle == angle.angle) return true;
	else return false;
}

// now irintable
std::ostream& operator<<(std::ostream& out, const Angle& a){
	out << a.angle << "\u00B0";
	return out;
}
// end of the class
