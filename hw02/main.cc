// matrix dot product calclator

# include <cstdio>
# include "mat_calc.h"


int main(int argc, char** argv){

	// declare array sizes
	int m1 = 0;
	int m2 = 0;
	int n1 = 0;
	int n2 = 0;
	// get user input for array size and create array
	printf("first array row size: \n");
	scanf("%d", &m1);
	printf("first array column size: \n");
	scanf("%d", &n1);
	printf("second array row size: \n");
	scanf("%d", &m2);
	printf("second array column size: \n");
	scanf("%d", &n2);
	// create arrays
	double mat1[m1 * n1];
	double mat2[m2 * n2];


//#if 0
	// get input and fill out arrays
#if 0
	for(int row=0; row<m1; ++row){
	    // each inner arrays
	    printf("********** %d row *************\n", row);
	    for (int col=0; col<n1; ++col){
		double input = 0;
	   	printf("enter %d row, %d column #: ", row+1, col+1); 
		scanf("%lf", &input);
		mat1[n1*row + col] = input;
	    }
	}
#endif
	double size = 0;
	// Print the array for practice
	//printf("what is mat1? %p\n", (double* )mat1);
	//printf("size of mat1: %lu\n", sizeof(mat1));
	//printf("size of double: %lu\n", sizeof(size));
	//printArray((double* )mat1, m1, n1);
	
	// here get user input for array 1
	printf("Input for matrix 1");
	getInput(mat1, m1, n1);
	printf("Print matrix1");
	printArray(mat1, m1, n1);


	// here get user input for array 2
	printf("Input for matrix 2");
	getInput(mat2, m2, n2);
	printf("Print matrix2");
	printArray(mat2, m2, n2);

	// now time for dot products
	// make result array first
	double mat3 [m1 * n2];

	mat_dot(mat1, mat2, mat3, m1, n1, m2, n2); 

	// print out the result
	printArray(mat3, m1, n2);

//#endif


}
