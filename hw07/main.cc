#include<cstdio>
#include "Angle.h"
int main(){

	// create a new Angle object
	Angle right(200);
	printf("set right as... %lf\n", right.getAngle());
	Angle pi(180);

	Angle neg(-345.2);
	printf("depresseed: %lf\n", neg.getAngle());

	// test + overloading
	printf("right + pi, should be 270: %lf\n", (right+pi).getAngle());

	// test - overloading
	printf("right - pi, should be 90: %lf\n", (pi-right).getAngle());

	// test *
	printf("right * pi, should be 0: %lf\n", (pi*right).getAngle());


	// test /
	printf("right * pi, should be 0.9: %lf\n", (pi/right).getAngle());


	// test +=
	pi+= right;
	printf("pi += right, pi now should be 20: %lf\n", pi.getAngle());
	
	// test -=
	pi+= right; // 20 + 200 => 220
	printf("pi -= right, pi now should be 220: %lf\n", pi.getAngle());
	
	// test *=
	pi*= right; // 220 * 200 => 44000
	printf("pi *= right, pi now should be 80??: %lf\n", pi.getAngle());
	
	// test /=
	pi/= right; // 80 / 200 => 0.4
	printf("pi *= right, pi now should be 0.4??: %lf\n", pi.getAngle());

	// test ==
	if(pi==right) printf("pi==right\n");
	else printf("pi!=right\n");

	// test = with angle
	pi = right;
	printf("pi = right: should be 200 %lf\n", pi.getAngle());
	
	// test = with double 
	pi = 124.5;
	printf("pi = right: should be 124.5 %lf\n", pi.getAngle());
	// test the zero division terminator
	Angle zero(0);
	printf("pi/ zero, should be error: %lf\n", (pi/zero).getAngle());
}
