#include "printcolorful.hpp"
using namespace std;

void PrintColor::Print(const char * text,string color, bool bold, bool tilt){
    cout << color.c_str();  // 색 설정

    if(bold) {
        cout << "\033[1m";  // 굵게
    }

    if(tilt) {
        cout << "\033[3m";  // 기울임
    }

    cout << text;          // 텍스트 출력

    cout << "\033[0m" ; // 모든 속성 초기화
}