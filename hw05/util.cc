#include <cstdio>
#include <stdlib.h>
#include "util.h"

// two print functions for debugging
void printIntArray(const int* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d \n", array[i]);
	}
	printf("\n");

}


void printTwoArray(int** array, int m, int n){
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}


void printCharArray(const char* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");

}

int** readPpm(const char* f_name, int* width, int* height){
	FILE* fb = fopen(f_name, "rb"); // open the file
	printf("Reading the header\n");
	fscanf(fb, "%*s\n%d %d\n%*d\n", width, height); // write header
	int pixels = *width * *height * 3;
	char* array_pix = new char [pixels]; // initialize the heap array
	printf("now reading raw bytes!\n");
	fread(array_pix, sizeof(char), (pixels), fb); // return
	fclose(fb);

	// declare max pixel value
	printf("starting hw5\n");
	int max = 255;
	unsigned char* max_pix = (unsigned char*)(&max); // type casting, 255 in hex
	// declare the 2D array as data int, (width x height)
	// allocate array of pointers
	int** array = create_mat(*height, *width);
	// now go through all the elements in the original char array
	//for(int e=0; e<pixels, e+3){ // increment by 3, each pixel
	int c = 0;
	for(int row=0; row<*height; row++){
		for(int col=0; col<*width; col++){
			// making char pointer for the int array element
			unsigned char* ptr_pix = (unsigned char*)(&array[row][col]);//2D array as 1D array
			// now transfer data...
			ptr_pix[0] = max_pix[0]; // 255
			ptr_pix[1] = array_pix[c]; // r  dereferencing the pointers
			ptr_pix[2] = array_pix[c+1]; // g
			ptr_pix[3] = array_pix[c+2]; // b

			c = c+3;
		}

	}
	// typecast from char to int??
	
	// fill up the 2D array, with data
	// point at one char/pixel, and 
	// typecast char -> int and put it in 2D array
	// fill in the extra byte with 255
	return array; // the char flat array
}

void writePpm(int** array, char* magic, int width, int height, int max_pix){
	// open the file and initialize the file
	FILE* fw = fopen("result.ppm", "wb"); 
	int pixels = width * height * 3;
	printTwoArray(array, 1, 5);
	// create the new char flat array to write data from
	char* array_pix = new char [pixels]; // initialize the heap array
	int c = 0;
	printf("for loop: 2D -> flat char array...\n");
	for(int row=0; row<height; ++row){
		for(int col=0; col<width; ++col){
		// cast int as unsigned char so it's readable
		unsigned char* pixel = (unsigned char*)(&array[row][col]);
		array_pix[c] = pixel[1];
		array_pix[c+1] = pixel[2];
		array_pix[c+2] = pixel[3];
		c += 3;
		}
	}

	fprintf(fw, "%s\n%d %d\n%d\n", magic, width, height, max_pix); // write header
	fwrite(array_pix, sizeof(char), (pixels), fw); // write data
	fclose(fw);
}

int** horizFlip(int** picture, int height, int width){
	// flip the pic horizontally
	// create reverse identity
	printf("making the inv\n");
	int** rI = reverse_identity(width);	
	// perform dot product
	printf("flopping the pic now...\n");
	int** result = dot_product(picture, rI, width, height, width, width);

	return result;
}

int** vertFlip(int** picture, int height, int width){
	// flip the pic horizontally
	// create reverse identity
	printf("making the inv\n");
	int** rI = reverse_identity(height);	
	// perform dot product
	printf("flopping the pic now...\n");
	int** result = dot_product(rI, picture, width, height, width, width);

	return result;
}

int** rotate(int** picture, int height, int width){
	// flip the pic horizontally
	// create reverse identity
	printf("horizontal...\n");
	int** horiz = horizFlip(picture, height, width);
	printf("vertical..\n");
	int** vert = vertFlip(horiz, height, width);

	return vert;
}

int** dot_product(int** mat1, int** mat2, int width1, int height1, int width2, int height2){
	// get pointers to the 2D matrix and perform dot product
	// first declare the result matrix
	printf("before the creating m3...\n");
	int** mat3 = create_mat(height1, width2);	

	for(int col2=0; col2<width2; ++col2){
		//printf("outer for loop...\n");
		for(int row1=0; row1<height1; ++row1){
			//printf("second for loop..\n");
			for(int col1=0; col1<width1; ++col1){
				//printf("width1, %d, height1: %d, width2: %d, height2: %d\n", width1, height1, width2, height2);
				//printf("row1: %d, col1: %d, col2: %d\n", row1, col1, col2);
				mat3[row1][col2] += mat1[row1][col1] * mat2[col1][col2];
				//printf("Matrix value: %d\n", mat3[row1][col2]);
			}
		}
	}
	return mat3;

}

int** create_mat(int height, int width){

	printf("creating the 2D array of size: %d x %d\n", width, height);
	int** mat= new int* [height];
	printf("created pointer array\n");
	// allocate flat array
	*mat = new int[width*height]; // pointer to the pointer of the first element in the array
	printf("created data array\n");
	// set pointers to the start of the each row
	for(int i=1; i<height; ++i){
		mat[i] = mat[i-1] + width;
	}
	printf("returning the new mat\n");
	return mat;
}

int** reverse_identity(int size){
	// input for this method will always be square matrix!
	printf("***testing reverse Identity");
	int** mat = create_mat(size, size);
	for(int row=0; row<size; ++row){
		//mat[row][size-(row+1)] = 1;
		for(int col=0; col<size; ++col){
			if(row+col == size-1){
				mat[row][col] = 1;
				//printf("row: %d, col: %d\n", row, col);
			}
			else{mat[row][col] = 0;}
		}
	}
	return mat;
}
