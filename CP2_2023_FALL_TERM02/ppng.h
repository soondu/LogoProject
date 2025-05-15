#pragma once
#include <iostream>
#include<stdio.h>
#include<png.h>
#include "shape.hpp"
#include "input.h"

#define WIDTH 7
#define HEIGHT 7
#define COLOR_DEPTH 8
class SetPng{
    public:
        void setpng(int height, int width, Pixel ** str);
        ~SetPng(){}
        
};
class Png:public SetPng{
    private:
        Pixel ** str;
        int cnt;
        int maxx;
        const char* filename;
    public:
        Png(Pixel ** _str,int _cnt,int _maxx):str(_str),cnt(_cnt),maxx(_maxx),filename("out.png"){};
        ~Png(){}
        void allo();
        void image();
        const char* GetFile() const { return filename; }
};

class Png_shape:public SetPng {
private:
    Pixel ** str;
    SelectShape& select;
    int height; //png_HEIGHT, png_WIDTH
    int width;
    const char* filename;

public:
    Png_shape(Pixel ** _str,SelectShape& _select) : 
    str(_str),select(_select), height(select.png_HEIGHT), width(select.png_WIDTH),filename("shape.png"){}
    ~Png_shape(){}
    void allo();
    void image();
    const char* GetFile() const { return filename; }
};
