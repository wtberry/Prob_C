# include <cstdio>

#if 1
void mat_dot(double* mat1, double* mat2, double* mat3, int m1, int n1, int m2, int n2){
	// this function takes 2 matrices as input, and reeturn dot products
	
	// first, let's get sizes of matrix
#if 0
	// prep for the size, get size of double on the machine
	double size_matters = 0; // random var for measuring the size of double
	// to get array's length, len(arr) = sizeof(arr)/sizeof(dtype)
	int m1 = sizeof(mat1)/sizeof(mat1[0]);// whole mat size / inner mat size
	int n1 = sizeof(mat1[0])/sizeof(size_matters); // how many elements in inner arrays
	int m2 = sizeof(mat2)/sizeof(mat2[0]);
	int n2 = sizeof(mat2[0])/sizeof(size_matters); 
#endif

	printf("m1 %d\n", m1);
	printf("n1 %d\n", n1);
	printf("m2 %d\n", m2);
	printf("n2 %d\n", n2);

	// declare the new matrix to fill in, and return

	// dot product
	// this part (algorithm) works in python.. but not in c++, problem with pointer??
	for(int col2=0; col2<n2; ++col2){
 	    for(int row1=0; row1<m1; ++row1){
		for(int col1=0; col1<n1; ++col1){ 
		    printf("r1, c2, c1: %d, %d, %d: \n", row1, col2, col1);
		    mat3[n2 * row1+col2] += mat1[n1 * row1 + col1] * mat2[n2 * col1 + col2];
		} 
	    }	
	}


}
#endif

void printArray(const double* matrix, int m, int n){
    	// Print the array for practice
	printf("matrix, %d x %d: \n", m, n);
	//double mat [m][n];
	//mat = matrix;
	for(int row=0; row<m; ++row){
	    printf("[");
	    for (int col=0; col<n; ++col){
	        printf("%lf ", matrix[n * row+col]); 
	    }
	    printf("]\n");
	}
}

void getInput(double* matrix, int m, int n){
	// get input from user and store it in the array
	for(int row=0; row<m; ++row){
	    // each inner arrays
	    printf("********** %d row *************\n", row);
	    for (int col=0; col<n; ++col){
		double input = 0;
	   	printf("enter %d row, %d column #: ", row+1, col+1); 
		scanf("%lf", &input);
		matrix[n * row + col] = input;
	    }
	}

}


void initializeArray(double* matrix, int m, int n){
    	// initialize the array elements to zero
	//double mat [m][n];
	//mat = matrix;
	for(int row=0; row<m; ++row){
	    //printf("[");
	    for (int col=0; col<n; ++col){
	        matrix[n * row+col] = 0; 
	    }
	}
}

