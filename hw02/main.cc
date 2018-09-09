// matrix dot product calclator

# include <cstdio>
# include "mat_calc.h"

int main(int argc, char** argv){

	// declare array sizes
	int m1;
	int m2;
	int n1;
	int n2;

	// get user input for array size and create array
	print("first array row size: \n");
	scanf("%d", &m1);
	print("first array column size: \n");
	scanf("%d", &n1);
	print("second array row size: \n");
	scanf("%d", &m2);
	print("second array column size: \n");
	scanf("%d", &n2);

	// create arrays
	double mat1[m1][n1];
	double mat2[m2][n2];



	// get input and fill out arrays
	for(int row=0; row<m1; row++){
	    // each inner arrays
	    printf("********** %d row *************", row);
	    for (int col=0; col<n1; col++){
		double input = 0;
	   	printf("enter %d row, %d column #: ", row, col); 
		scanf("%lf", &input);
		mat1[row][col] = input;
	    }
	}






























}
