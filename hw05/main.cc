#include <cstdio>
#include <stdlib.h>
#include "util.h"

int main(){

// declare neccesary things
const char* f_name = "test.ppm";
int width = 0;
int height = 0;
int max_pixel_val = 255;
char magic[5] = "P6"; // for P6 part
char* array;
int ** td_array;


td_array =readPpm(f_name, &width, &height);

printf("Width, Height, Max_pixel: %s %d %d %d \n", magic, width, height, max_pixel_val);
printf("where is the seg fault??\n");

//testing the dot function
#if 0
int m = 30;
int n = 20;
int** test = create_mat(m, n);
for(int i=0; i<m; ++i){
	for(int j=0; j<n; ++j){
		test[i][j] = i*n+j;
	}
}
printTwoArray(test, m, n);
int** horizFlipPic = horizFlip(test, m, n);
printTwoArray(horizFlipPic, m, n);
#endif

//int** horizFlipPic = horizFlip(td_array, height, width);
//printTwoArray(horizFlipPic, 1, 5);
//writePpm(horizFlipPic, magic, width, height, max_pixel_val);
//int** vertFlipPic = vertFlip(td_array, height, width);
//writePpm(vertFlipPic, magic, width, height, max_pixel_val);

int** rotated = rotate(td_array, height, width);
writePpm(rotated, magic, width, height, max_pixel_val);

}
