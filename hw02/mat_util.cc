double [][] mat_dot(double [][] mat1, double [][] mat2){
	// this function takes 2 matrices as input, and reeturn dot products
	
	// first, let's get sizes of matrix
	// prep for the size, get size of double on the machine
	double size_matters = 0; // random var for measuring the size of double
	// to get array's length, len(arr) = sizeof(arr)/sizeof(dtype)
	int m1 = sizeof(mat1)/sizeof(mat1[0]);// whole mat size / inner mat size
	int n1 = sizeof(mat1[0])/sizeof(size_matters); // how many elements in inner arrays
	int m2 = sizeof(mat2)/sizeof(mat2[0]);
	int n2 = sizeof(mat2[0])/sizeof(size_matters); 

	printf("m1 %d\n", m1);
	printf("n1 %d\n", n1);

	// declare the new matrix to fill in, and return
	double [m1][n2] mat3;

	return mat3;

}
