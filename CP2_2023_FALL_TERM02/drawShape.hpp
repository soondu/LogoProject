#pragma once
#ifndef DRAWSHAPE_HPP
#define DRAWSHAPE_HPP
#include <iostream>
#include "shape.hpp"
#include "pixel.hpp"
#include "color.hpp"
#include "input.h"
#include "ppng.h"
using namespace std;
class draw_data:public SetPng{
    public:
        Pixel ** str;
        Color * color; 
        SelectShape& select;
        draw_data(Pixel ** _str, Color * _color,SelectShape& _select)
        :str(_str), color(_color),select(_select){}
        ~draw_data(){}
        void draw(int x1, int x2,  int y2,int height,Pixel** str, Color * color);
        void draw_line(int x1, int x2, int y1, int y2,Pixel** str,Color * color);
        void setpng(int height, int width,Pixel** str);
        void draw_rectangle(Rectangle& rectangle,Pixel** str, Color * color);
        void draw_triangle(Triangle& triangle,Pixel** str, Color * color);
        void draw_circle(Circle& circle,Pixel** str, Color * color); 
        void DrawShape(SelectShape& select);      
};
#endif
