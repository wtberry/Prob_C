#include <cstdio>
#include <stdlib.h>
#include <jpeglib.h>
#include "util.h"


unsigned char* readPpm(const char* f_name, int* width, int* height){
	FILE* fb = fopen(f_name, "rb"); // open the file
	printf("Reading the header\n");
	fscanf(fb, "%*s\n%d %d\n%*d\n", width, height); // write header
	int pixels = *width * *height * 3;
	unsigned char* array_pix = new unsigned char [pixels]; // initialize the heap array
	printf("now reading raw bytes!\n");
	fread(array_pix, sizeof(unsigned char), (pixels), fb); // return
	fclose(fb);

	return array_pix;
}

void writePpm(unsigned char* array, char* magic, int width, int height, int max_pix){
	// open the file and initialize the file
	FILE* fw = fopen("result.jpeg", "wb"); 
	int pixels = width * height * 3;

	// create structs for the libjpeg writer
	// * jpeg compression object: struct jpeg_compress_struct
	// * provide own error handler
	//
	// initialize struct
	//
	printf("initializing the structs...\n");
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	//...
	cinfo.err = jpeg_std_error(&jerr); // pass  the pointer to the jerr
	// this needs to be done FIRST
	jpeg_create_compress(&cinfo); // alloacte piece of memory. WIll fail if out of memory, which is why error handler is initialized first
	
	// specify the destination for the compressed jpeg data, this case a file
	printf("setting up the destination file\n");
	jpeg_stdio_dest(&cinfo, fw);

	// now set up the image parameter in struct
	printf("setting up the parameters for image size\n");
	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB; // wtf is this??

	

	// set up default compression parameters for now, can be changed after
	printf("setting up default\n");
	jpeg_set_defaults(&cinfo);

	// make optional compression params here if you want
	
	// start compression
	printf("startting the compression process...\n");
	jpeg_start_compress(&cinfo, true);

	// while loop to write on a file
	printf("sgtarting the while loop\n");
	unsigned char* row_pointer; // pinter to single row
	printf("int stride\n");
	int row_stride = cinfo.image_width * 3; // # of elements in 1 row
	while(cinfo.next_scanline < cinfo.image_height){
		row_pointer = &array[cinfo.next_scanline * row_stride];
		jpeg_write_scanlines(&cinfo, &row_pointer, 1);	
	
	}

	// finish the compression cycle
	jpeg_finish_compress(&cinfo);

	// releasing the compression object
	jpeg_destroy_compress(&cinfo);
	//fprintf(fw, "%s\n%d %d\n%d\n", magic, width, height, max_pix); // write header
	//fwrite(array, sizeof(char), (pixels), fw); // write data
	fclose(fw);
}


