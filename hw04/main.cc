#include <cstdio>
#include <stdlib.h>
#include "util.h"

int main(){
// what to do
const char* f_name = "test.ppm";
// check if the file exist
// open the file
FILE* fp = fopen(f_name, "r");
int header[4]; // int in the header
int i = 0;
int width;
int height;
int max_pixel_val;
char header_c; // for P6 part

char* array = readHeader(f_name);
#if 0
if(fp == NULL) { // if the file does not exits, exit with 1
	printf("File does not exist, program will be terminated.\n");
	exit(1);

}
// if it does
else{
	printf("the file exists, proceeding to read.\n");
	// read the header
	fscanf(fp, "%c", &header_c);
	printf("first character: %c\n", header_c);

	// now read in the rest of int
	while(fscanf(fp, "%d", (header+i)) == 1){ // ==1 works,
		// maybe while input is integer??
		i++;	
		printf("%d\n", i);
	}
#endif
	// check the array of int
	printf("printing the array and assign the values in the array.\n");
	printCharArray(array, 4);
	width= array[1], 
	height = array[2]; 
	max_pixel_val = array[3];

	printf("Width, Height, Max_pixel: %d %d %d \n", width, height, max_pixel_val);

	//printf("now reading the raw bytes...\n");
 	//int pixels = width * height * 3;	
	//FILE* fb = fopen(f_name, "rb");
	//char array_pix [pixels];// for bytes	
	//fread(array_pix, sizeof(char), (pixels), fb);

	//printCharArray(array_pix, pixels);
	
	
	
// 	initialize the file reader for formatted and unformatted input
//		raw bytes: FILE ∗ f p = f o p e n ( ” b i n a r y f i l e ” , ” r b ” ) ;
//
// 	input the header info somehow, and store
// 	
// 	input and store the bytes
//
// 	write the info
// 		headers: fprint()
// 		bytes
// 		FILE ∗ f p = f o p e n ( ” b i n a r y f i l e ” , ”wb” ) ;






}
