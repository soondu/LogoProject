#pragma once
#ifndef INPUT_HPP
#define INPUT_HPP
#include <stdlib.h>
#include <iostream>
#include <string>
#include "shape.hpp"

using namespace std;
class Inp{
    public:
        void getInput(string* wrd, int *e, int* flip, int* co);
        void findTarget(string wrd, int* cnt, int* max);
        ~Inp(){}

};
class SelectShape{
    public:
        enum Shape{
            NONE = 'N',
            REC = 'R',
            TRI = 'T',
            CIRCLE = 'C'
        };
        int png_HEIGHT;
        int png_WIDTH;
        int word_height;
        int word_width;
        void select(int* co_s);
        Rectangle rec; //초기 도형 설정
	    Triangle tri;
	    Circle circle;
        Shape shape;
        SelectShape(int _word_height, int _word_width) 
        : word_height(_word_height),word_width(_word_width),rec(0, 0), tri(0), circle(0),
        shape(Shape::NONE),png_HEIGHT(0),png_WIDTH(0){}
        ~SelectShape(){}
};
#endif