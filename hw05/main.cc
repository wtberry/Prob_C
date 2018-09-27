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

int** horizFlipPic = horizFlip(td_array, height, width);
writePpm(horizFlipPic, magic, width, height, max_pixel_val);

}
