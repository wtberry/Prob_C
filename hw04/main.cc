#include <cstdio>
#include <stdlib.h>
#include "util.h"

int main(){

// declare neccesary things
const char* f_name = "test.ppm";
int width = 0;
int height = 0;
int max_pixel_val = 0;
char magic[5]; // for P6 part
char* array;


array =readPpm(f_name, magic, &width, &height, &max_pixel_val);

printf("Width, Height, Max_pixel: %s %d %d %d \n", magic, width, height, max_pixel_val);

writePpm(array, magic, width, height, max_pixel_val);

}
