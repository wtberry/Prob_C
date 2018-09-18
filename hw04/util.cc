#include <cstdio>
#include <stdlib.h>

void printIntArray(const int* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");

}


void printCharArray(const char* array, int size){

	for(int i=0; i<size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");

}

char* readHeader(const char* f_name){

	FILE* fp = fopen(f_name, "r");
	char* array = new char[10];
	if(fp == NULL) { // if the file does not exits, exit with 1
	printf("File does not exist, program will be terminated.\n");
	exit(1);

}
// if it does
	else{
		printf("the file exists, proceeding to read.\n");
		// read the header
		fscanf(fp, "%c", &array[0]);
		printf("first character: %c\n", array[0]);
		
		int i = 1;	
		char temp;
		// now read in the rest of int
		while(temp != 'n'){ // ==1 works,
			temp = fscanf(fp, "%c", &array[i]);
			// maybe while input is integer??
			i++;
			
			printf("reading: %d %c \n", i, temp);
			if (i == 6) break;
		}
	}


	return array;

}
#if 0
void readPixels(){

}
#endif
