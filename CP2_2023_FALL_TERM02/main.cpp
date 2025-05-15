#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "draw.h"
#include "drawShape.hpp"
#include "pixel.hpp"
#include "color.hpp"
#include "ppng.h"
#include "input.h"
#include "merge.hpp"
#include "printcolorful.hpp"
using namespace std;
#define PNG_SETJMP_NOT_SUPPORTED
#include <png.h>

#define WIDTH 7
#define HEIGHT 7
#define COLOR_DEPTH 8

int main(int argc, char *argv[]) {
    PrintColor p;
  
   //Open(f, png_ptr, info_ptr);

int e=0,r=0,co=0, co_s=0, maxx=1, cnt=0;
    string wrd;
    Inp inp;
    inp.getInput(&wrd, &e, &r, &co); //input.cpp

    inp.findTarget(wrd, &cnt, &maxx); //max와 cnt찾음, target.cpp
struct Pixel * str[ HEIGHT*(cnt+1)+cnt ]; 

   Color *color;
   color=color->setColor(co);

    Png png(str,cnt,maxx);
    png.allo();//png.cpp
    Draw draw(str,r,cnt,maxx,color);

    int word_height=HEIGHT*(cnt+1)+cnt;
    int word_width=WIDTH*maxx;


    SelectShape sel(word_height, word_width); //png 사이즈 정보 sel의 png_HEIGHT, png_WIDTH
    sel.select(&co_s);
    Color *color_shape;
    color_shape=color_shape->setColor(co_s);

    draw.alph(str,wrd, e);//target.cpp 

    png.image();
   

    struct Pixel * str_shape[sel.png_HEIGHT];
    Png_shape png_shape(str_shape, sel); 
    png_shape.allo();//png.cpp 
    //png 가로 세로 정보 : //sel : png_HEIGHT, png_WIDTH = png_shape : height, width
    draw_data d(str_shape,color_shape,sel);
    d.DrawShape(sel);
    png_shape.image();  

    
    int merge_height, merge_width;
    merge_height=(word_height<sel.png_HEIGHT)?sel.png_HEIGHT:word_height;
    merge_width=(word_width<sel.png_WIDTH)?sel.png_WIDTH:word_width;


    struct Pixel * str_logo[merge_height];
    Png_merge png_merge(str_logo, merge_height, merge_width);
    png_merge.allo();
    png_merge.image("mergesource.png");

    png_merge.overlayImages("mergesource.png",png_shape.GetFile(),"new_shape.png");

    png_merge.overlayImages("new_shape.png", png.GetFile(),"LOGO.png");
    p.Print("Your LOGO.png is made!",p.Default,true,true);
    cout<<endl;

    delete color;
    delete color_shape;

    return 0;
}