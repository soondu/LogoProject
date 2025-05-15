#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <cmath>
using namespace std;

class Pos{
	public:
		int x;
		int y;
		Pos(int x=0, int y=0) 
		:x(x), y(y){}
        ~Pos(){}
};
class Rectangle{
    public:
        int height; //최소 10x10
        int width;
        Pos right_low, right_up, left_low, left_up;
        Rectangle(int height, int width):height(height), width(width),right_low(width-1,height-1),
        right_up(width-1,0),left_low(0, height-1),left_up(0,0){}
        ~Rectangle(){}
};

class Triangle{ //최소 19
    public:
        int height;
        int length;
        Pos right_low, left_low, up;
        Triangle(int length):height(length),length(length),
        right_low(length-1, height-1),left_low(0,height-1), up(static_cast<int>(length*0.5), 0){}
        ~Triangle(){}
};
class Circle { //최소 6
public:
    int radius;
    int height;
    int width;
    Pos pos, right_end, left_end, up_end, down_end;
    Circle(int r) : radius(r),pos(radius, radius),height(2*radius+1),width(2*radius+1),
    right_end(pos.x+radius,pos.y),left_end(pos.x-radius,pos.y),up_end(pos.x, pos.y-radius),down_end(pos.x,pos.y+radius){}
    ~Circle(){}
};
#endif