#include <cstdio>
#include <stdlib.h>

// two print functions for debugging
void printIntArray(const int* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d \n", array[i]);
	}
	printf("\n");

}


void printCharArray(const char* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");

}

char* readPpm(const char* f_name, char* magic, int* width, int* height, int* max_pix){
	FILE* fb = fopen(f_name, "rb"); // open the file
	printf("Reading the header\n");
	fscanf(fb, "%s\n%d %d\n%d\n", magic, width, height, max_pix); // write header
	int pixels = *width * *height * 3;
	char* array_pix = new char [pixels]; // initialize the heap array
	printf("now reading raw bytes!\n");
	fread(array_pix, sizeof(char), (pixels), fb); // return
	fclose(fb);
	return array_pix;
}

void writePpm(char* array, char* magic, int width, int height, int max_pix){
	// open the file and initialize the file
	FILE* fw = fopen("result.ppm", "wb"); 
	int pixels = width * height * 3;
	fprintf(fw, "%s\n%d %d\n%d\n", magic, width, height, max_pix); // write header
	fwrite(array, sizeof(char), (pixels), fw); // write data
	fclose(fw);
}
