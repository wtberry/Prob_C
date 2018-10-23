#include<cstdio>
#include "Angle.h"
#include<iostream>
int main(){

	// vi command to replace all printf() to std::cout
	// :%s/printf(\(.*\) \S\+, \(.*\));/std::cout << \1 " << \2 << std::endl;/g

	// create a new Angle object
	Angle right(200);
	std::cout << "set right as... " << right.getAngle() << std::endl;
	Angle pi(180);

	Angle neg(-345.2);
	std::cout << "depresseed: " << neg << std::endl;

	// test + overloading
	std::cout << "right + pi, should be 270: " << (right+pi) << std::endl;

	// test - overloading
	std::cout << "right - pi, should be 90: " << (pi-right) << std::endl;

	// test *
	std::cout << "right * pi, should be 0: " << (pi*right) << std::endl;


	// test /
	std::cout << "right * pi, should be 0.9: " << (pi/right) << std::endl;


	// test +=
	pi+= right;
	std::cout << "pi += right, pi now should be 20: " << pi << std::endl;
	
	// test -=
	pi+= right; // 20 + 200 => 220
	std::cout << "pi -= right, pi now should be 220: " << pi << std::endl;
	
	// test *=
	pi*= right; // 220 * 200 => 44000
	std::cout << "pi *= right, pi now should be 80??: " << pi << std::endl;
	
	// test /=
	pi/= right; // 80 / 200 => 0.4
	std::cout << "pi *= right, pi now should be 0.4??: " << pi << std::endl;

	// test ==
	if(pi==right) std::cout<<"pi==right\n"<<std::endl;
	else std:: cout<< "pi!=right" <<std::endl;

	// test = with angle
	pi = right;
	std::cout << "pi = right: should be 200 " << pi << std::endl;
	
	// test = with double 
	pi = 124.5;
	std::cout << "pi = right: should be 124.5 " << pi << std::endl;

	std::cout << "trying out printable methods for pi: " << pi << std::endl;
	// test the zero division terminator
	Angle zero(0);
	std::cout << "pi/ zero, should be error: " << (pi/zero) << std::endl;

}
