#include <stdlib.h>
#include <iostream>
#include "pixel.hpp"
#define PNG_SETJMP_NOT_SUPPORTED
#include <png.h>
#include "ppng.h"

using namespace std;

void SetPng::setpng(int height, int width,Pixel** str){
	for (int col =0 ; col <width; col++) {
		for (int row= 0; row <height; row++) {
			str[row][col].r = 0; // red
			str[row][col].g = 0; // green
			str[row][col].b = 0; // blue
			str[row][col].a = 0; // alpha (opacity)
			
		}
	}

}

void Png::allo(){
    /* allocate image data */
    //str=new Pixel*[ HEIGHT*(cnt+1)+cnt ];
    for(int row=0;row<HEIGHT*(cnt+1)+cnt;row++){
        str[row]=new Pixel[WIDTH*maxx];
    }
}

void Png::image(){
    /* begin writing PNG File */
    FILE*f = fopen("out.png", "wb");
     if (!f) {
    fprintf(stderr, "could not open out.png\n");
    exit(1);
    }
     png_structp png_ptr;
     png_infop info_ptr;
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
    fprintf(stderr, "could not initialize png struct\n");
    exit(1);
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
    png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    fclose(f);
    exit(1);
    }
    png_init_io(png_ptr, f);
    png_set_IHDR(png_ptr, info_ptr, WIDTH * maxx , HEIGHT*(cnt+1)+cnt, COLOR_DEPTH,
                PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png_ptr, info_ptr);

    /* write image data to disk */
    png_write_image(png_ptr, (png_byte **)str);
    /* clean up PNG-related data structures */
    png_write_end(png_ptr, NULL);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(f);

    for(int i = 0; i <HEIGHT*(cnt+1)+cnt; i++) {
        delete[] str[i];
    }
}

void Png_shape::allo(){
    /* allocate image data */
    for(int row=0;row<height;row++){
        str[row]=new Pixel[width]; //png_HEIGHT, png_WIDTH
    }
}

void Png_shape::image(){
    /* begin writing PNG File */
    FILE*fs = fopen("shape.png", "wb");
     if (!fs) {
    fprintf(stderr, "could not open shape.png\n");
    exit(1);
    }
    
    png_structp png_ptr;
    png_infop info_ptr;

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fprintf(stderr, "could not initialize png struct\n");
        exit(1);
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        fclose(fs);
        exit(1);
    }
 
    png_init_io(png_ptr, fs);
    png_set_IHDR(png_ptr, info_ptr, width , height, COLOR_DEPTH,
                PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png_ptr, info_ptr);

    png_write_image(png_ptr, (png_byte **)str);

    /* clean up PNG-related data structures */
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fs);
    for(int i = 0; i < height; i++) {
        delete[] str[i];
    }
}
