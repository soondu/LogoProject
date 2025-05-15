#pragma once
#ifndef DRAW_HPP
#define DRAW_HPP
#include "pixel.hpp"
#include "color.hpp"

class Draw{
    public:
        Draw (Pixel ** _str, int _r,int _cnt,int _maxx, Color * _color){
            str = _str;
            r = _r;
            color = _color;
            cnt = _cnt;
            maxx=_maxx;
        }
        ~Draw(){}
        void fill(int i, int a, int b);
        void draw(int i, char c);
        void alph(Pixel** str, string wrd, int e);
    private:
        Pixel ** str;
        int z=0; // 몇번째 줄인지 나타내는 변수
        int r; // 어떻게 뒤집는지
        int cnt; //cnt 줄 바꿈 개수
        Color * color; // 글자 색 저장
        int maxx;//최대 가로
};


#endif