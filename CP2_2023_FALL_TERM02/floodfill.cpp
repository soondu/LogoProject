#include "floodfill.hpp"
using namespace std;
Pixel**floodfill(Pixel**str, Color* color,SelectShape & sel,int row, int col){
    int HEIGHT=sel.png_HEIGHT;
    int WIDTH=sel.png_WIDTH;

    // 범위 유효성 체크
    if (row >= HEIGHT || col >= WIDTH || row < 0 || col < 0) {
        return str;
    }
    
    bool select_color=false;
    if(str[row][col].r == color->getR()&&str[row][col].g == color->getG()&&str[row][col].b == color->getB()){
        select_color=true; //사용자가 선택한 색이 맞다!(외곽선을 만났다!)
    }
    if (row >= HEIGHT || col >= WIDTH || row < 0 || col < 0 ||select_color) {
        return str; //범위 넘거나 사용자가 선택한 색(외곽선을 만났다!)이면 재귀 함수 종료.
    }
 
    str[row][col].r = color->getR();
    str[row][col].g = color->getG();
    str[row][col].b = color->getB();
    str[row][col].a = 255;
    floodfill(str, color, sel,row + 1, col); //우
    floodfill(str, color,sel,row - 1, col); //좌
    floodfill(str, color,sel,row, col + 1); //하
    floodfill(str, color,sel,row, col - 1); //상
    
    return str;
}