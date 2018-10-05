#include <cstdio>
#include <jpeglib.h>
#include "util.h"

int main(){
printf("libjpeg imported\n");

// declare neccesary things
const char* f_name = "test.ppm";
int width = 0;
int height = 0;
int max_pixel_val = 255;
char magic[5] = "P6"; // for P6 part
unsigned char* array;

array = readPpm(f_name, &width, &height);
printf("read the array, this is in main, now start writing jpeg...\n");
writePpm(array, magic, width, height, max_pixel_val);

	
}
