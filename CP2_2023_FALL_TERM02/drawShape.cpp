#include "drawShape.hpp"
#include "pixel.hpp"
#include "color.hpp"
#include "shape.hpp"
#include "input.h"
#include "floodfill.hpp"
#include <cmath>
using namespace std;


void draw_data::draw(int x1, int x2,  int y2,int height,Pixel** str, Color * color){ 
	//가로 x1<=col<=x2, 세로 y2-height<=row<y2
    for (int col =x1 ; col <= x2; col++) {
		for (int i= 0; i <height; i++) {
			str[y2-i][col].r = color->getR(); // red
			str[y2-i][col].g = color->getG(); // green
			str[y2-i][col].b = color->getB(); // blue
			str[y2-i][col].a = 255; // alpha (opacity)
			
		}
	}
}



void draw_data::draw_line(int x1, int x2, int y1, int y2,Pixel** str,Color * color){
	int dx=abs(x2-x1);
	int dy=-abs(y2-y1);
	int x_inc=(x1<x2)?1:-1;
	int y_inc=(y1<y2)?1:-1;
	int error=dx+dy;
	int x=x1;
	int y=y1;

	while(x!=x2 || y!=y2){
		if(x>=0&&y>=0&&x<select.png_WIDTH||y<select.png_HEIGHT){ //좌표가 유효한 범위에 있는가
			str[y][x].r = color->getR(); // red
			str[y][x].g = color->getG(); // green
			str[y][x].b = color->getB(); // blue
			str[y][x].a = 255; // alpha (opacity)
		}
		int error2=2*error;
		if(error2>dy){
			error+=dy;
			x+=x_inc;
		}
		if(error<dx){
			error+=dx;
			y+=y_inc;
		}
				
	}
}

void draw_data::draw_rectangle(Rectangle& rectangle,Pixel** str, Color * color){
	draw(rectangle.left_low.x, rectangle.right_low.x, rectangle.left_low.y, rectangle.height, str,color);
}
void draw_data::draw_triangle(Triangle& triangle,Pixel** str, Color * color){
	draw_line(triangle.left_low.x,triangle.up.x, triangle.left_low.y, triangle.up.y, str, color);
	draw_line(triangle.left_low.x,triangle.right_low.x, triangle.left_low.y, triangle.right_low.y, str, color);
	draw_line(triangle.right_low.x,triangle.up.x, triangle.right_low.y, triangle.up.y, str, color);
	draw(triangle.up.x, triangle.up.x+1,1,1,str,color);

	int centerY=triangle.height*0.5;
	int centerX=triangle.length*0.5;
	floodfill(str,color,select,centerY, centerX);
}
void draw_data::draw_circle(Circle& circle,Pixel** str, Color * color){
	for (int i = 0; i <= 360; ++i) {
		long double angle = i * M_PI / 180.0;
		int x = circle.pos.x+ round(circle.radius * cos(angle));
		int y = circle.pos.y + round(circle.radius * sin(angle));
		int x1 = circle.pos.x+ round((circle.radius-1) * cos(angle));
		int y1 = circle.pos.y + round((circle.radius-1) * sin(angle));
		int x2 = circle.pos.x+ round((circle.radius-1) * cos(angle));
		int y2 = circle.pos.y -1+ round((circle.radius-1) * sin(angle));
		int x3 = circle.pos.x+ round((circle.radius-1) * cos(angle));
		int y3 = circle.pos.y+1 + round((circle.radius-1) * sin(angle));

		if(x>=0&&x<=circle.right_end.x&&y>=0&&y<=circle.down_end.y){ //original
			draw(x, x , y, 1, str, color);
			if(x1>=0&&x1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)	
			{draw(x1, x1 , y1, 1, str, color);}	
			if(x2>=0&&x2<=circle.right_end.x&&y2>=0&&y2<=circle.down_end.y)	
			{draw(x2, x2 , y2, 1, str, color);}
			if(x3>=0&&x3<=circle.right_end.x&&y3>=0&&y3<=circle.down_end.y)	
			{draw(x3, x3 , y3, 1, str, color);}
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)	
			{draw(x1+1, x1+1 , y1, 1, str, color);}	
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)	
			{draw(x1-1, x1-1 , y1, 1, str, color);}	
		}
		if(x>=0&&x<=circle.right_end.x&&y+1>=0&&y+1<=circle.down_end.y){ //하
			draw(x, x , y+1, 1, str, color);
			if(x1>=0&&x1<=circle.right_end.x&&y1+1>=0&&y1+1<=circle.down_end.y)
			{draw(x1, x1 , y1+1, 1, str, color);}
			if(x2>=0&&x2<=circle.right_end.x&&y2+1>=0&&y2+1<=circle.down_end.y)
			{draw(x2, x2 , y2+1, 1, str, color);}
			if(x3>=0&&x3<=circle.right_end.x&&y3+1>=0&&y3+1<=circle.down_end.y)
			{draw(x3, x3 , y3+1, 1, str, color);}
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1+1>=0&&y1+1<=circle.down_end.y)
			{draw(x1+1, x1+1 , y1+1, 1, str, color);}
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1+1>=0&&y1+1<=circle.down_end.y)
			{draw(x1-1, x1 -1, y1+1, 1, str, color);}
		}
		if(x+1>=0&&x+1<=circle.right_end.x&&y>=0&&y<=circle.down_end.y){ //우
			draw(x+1, x+1 , y, 1, str, color);
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)
			{draw(x1+1, x1+1 , y1, 1, str, color);}
			if(x2+1>=0&&x2+1<=circle.right_end.x&&y2>=0&&y2<=circle.down_end.y)
			{draw(x2+1, x2+1 , y2, 1, str, color);}
			if(x3+1>=0&&x3+1<=circle.right_end.x&&y3>=0&&y3<=circle.down_end.y)
			{draw(x3+1, x3+1 , y3, 1, str, color);}
			if(x1+2>=0&&x1+2<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)
			{draw(x1+2, x1+2 , y1, 1, str, color);}
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)
			{draw(x1-1, x1-1 , y1, 1, str, color);}
			
		}
		if(x>=0&&x<=circle.right_end.x&&y-1>=0&&y-1<=circle.down_end.y){ //상
			draw(x, x , y-1, 1, str, color);
			if(x1>=0&&x1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1, x1 , y1-1, 1, str, color);}
			if(x1>=0&&x1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1, x1 , y1-1, 1, str, color);}
			if(x1>=0&&x1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1, x1 , y1-1, 1, str, color);}
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1+1, x1 +1, y1-1, 1, str, color);}
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1-1, x1-1 , y1-1, 1, str, color);}
			
		}
		if(x+1>=0&&x+1<=circle.right_end.x&&y-1>=0&&y-1<=circle.down_end.y){ //대각1
			draw(x+1, x+1 , y-1, 1, str, color);
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1+1, x1+1 , y1-1, 1, str, color);}
			if(x2+1>=0&&x2+1<=circle.right_end.x&&y2-1>=0&&y2-1<=circle.down_end.y)
			{draw(x2+1, x2+1 , y2-1, 1, str, color);}
			if(x3+1>=0&&x3+1<=circle.right_end.x&&y3-1>=0&&y3-1<=circle.down_end.y)
			{draw(x3+1, x3+1 , y3-1, 1, str, color);}
			if(x1+2>=0&&x1+2<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1+2, x1+2 , y1-1, 1, str, color);}
		}
		if(x-1>=0&&x-1<=circle.right_end.x&&y>=0&&y<=circle.down_end.y){ //좌
			draw(x-1, x-1 , y, 1, str, color);
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1>=0&&y1<=circle.down_end.y)
			{draw(x1-1, x1-1 , y1, 1, str, color);}
			if(x2-1>=0&&x2-1<=circle.right_end.x&&y2>=0&&y2<=circle.down_end.y)
			{draw(x2-1, x2-1 , y2, 1, str, color);}
			if(x3-1>=0&&x3-1<=circle.right_end.x&&y3>=0&&y3<=circle.down_end.y)
			{draw(x3-1, x3-1 , y3, 1, str, color);}
		}
		if(x-1>=0&&x-1<=circle.right_end.x&&y-1>=0&&y-1<=circle.down_end.y){ //대각3
			draw(x-1, x-1 , y-1, 1, str, color);
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1-1, x1-1 , y1-1, 1, str, color);}
			if(x2-1>=0&&x2-1<=circle.right_end.x&&y2-1>=0&&y2-1<=circle.down_end.y)
			{draw(x2-1, x2-1 , y2-1, 1, str, color);}
			if(x3-1>=0&&x3-1<=circle.right_end.x&&y3-1>=0&&y3-1<=circle.down_end.y)
			{draw(x3-1, x3-1 , y3-1, 1, str, color);}
			if(x1-2>=0&&x1-2<=circle.right_end.x&&y1-1>=0&&y1-1<=circle.down_end.y)
			{draw(x1-2, x1-2 , y1-1, 1, str, color);}
		}
		if(x-1>=0&&x-1<=circle.right_end.x&&y+1>=0&&y+1<=circle.down_end.y){ //대각4
			draw(x-1, x-1 , y+1, 1, str, color);
			if(x1-1>=0&&x1-1<=circle.right_end.x&&y2+1>=0&&y2+1<=circle.down_end.y)
			{draw(x1-1, x1-1 , y2+1, 1, str, color);}
			if(x2-1>=0&&x2-1<=circle.right_end.x&&y2+1>=0&&y2+1<=circle.down_end.y)
			{draw(x2-1, x2-1 , y2+1, 1, str, color);}
			if(x3-1>=0&&x3-1<=circle.right_end.x&&y3+1>=0&&y3+1<=circle.down_end.y)
			{draw(x3-1, x3-1 , y3+1, 1, str, color);}
			if(x1-2>=0&&x1-2<=circle.right_end.x&&y2+1>=0&&y2+1<=circle.down_end.y)
			{draw(x1-2, x1-2 , y2+1, 1, str, color);}
		}
		if(x+1>=0&&x+1<=circle.right_end.x&&y+1>=0&&y+1<=circle.down_end.y){ //대각2
			draw(x+1, x+1 , y+1, 1, str, color);
			if(x1+1>=0&&x1+1<=circle.right_end.x&&y1+1>=0&&y1+1<=circle.down_end.y)
			{draw(x1+1, x1+1 , y1+1, 1, str, color);}
			if(x2+1>=0&&x2+1<=circle.right_end.x&&y2+1>=0&&y2+1<=circle.down_end.y)
			{draw(x2+1, x2+1 , y2+1, 1, str, color);}
			if(x3+1>=0&&x3+1<=circle.right_end.x&&y3+1>=0&&y3+1<=circle.down_end.y)
			{draw(x3+1, x3+1 , y3+1, 1, str, color);}
			if(x1+2>=0&&x1+2<=circle.right_end.x&&y1+1>=0&&y1+1<=circle.down_end.y)
			{draw(x1+2, x1+2 , y1+1, 1, str, color);}
		}
		
	}
	floodfill(str,color,select,circle.pos.y, circle.pos.x);
}

void draw_data::DrawShape(SelectShape& select) {
    switch (select.shape) {
    case SelectShape::Shape::REC:
		SetPng::setpng(select.png_HEIGHT,select.png_WIDTH,str);
        draw_rectangle(select.rec, str, color);
        break;
    case SelectShape::Shape::TRI:
		SetPng::setpng(select.png_HEIGHT, select.png_WIDTH,str);
        draw_triangle(select.tri, str, color);
        break;
    case SelectShape::Shape::CIRCLE:
		SetPng::setpng(select.png_HEIGHT,select.png_WIDTH,str);
        draw_circle(select.circle, str, color);
        break;
    default:
        break;
    }
}
