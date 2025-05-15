#pragma once
#include <stdlib.h>
#include <string.h>
#include <fstream> //헤더 정보 확인
#include <iostream>
#include<stdio.h>
#include<png.h>
#include "pixel.hpp"
#include "ppng.h"
#define COLOR_DEPTH 8
class Png_merge:public SetPng{
    private:
        Pixel ** str;
        int height;
        int width;
       

    public:
        Png_merge(Pixel ** _str,int height,int width):str(_str),height(height), width(width){};
        ~Png_merge(){}
        void overlayImages(const char* largeImageFile, const char* smallImageFile, const char* filename);
        void allo();
        void image(const char * filename);
};