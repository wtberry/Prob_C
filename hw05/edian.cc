#include <cstdio>

int main(){

	// program to find out little or big edian 
	
	int num = 987654321; // in Hex, this is equal to 3ADE68B1
	const char* hex = "3ADE68B1";

	// now type cast pointer to char array
	unsigned char* edian = (unsigned char*)&num; // edian points at the first element in the array

	printf("original number: %d\n", num);
	printf("original number in HEX: %s\n", hex);
	
	// now printing out as char
	printf("value in the memory as char: ");
	//printf("size of edian: %lu\n", sizeof(edian));
	//printf("size of char: %lu\n", sizeof(char));
	for(int i=0; i<sizeof(edian)/2; ++i){
		printf("%x|", edian[i]);
	}
	printf("\n");

}
