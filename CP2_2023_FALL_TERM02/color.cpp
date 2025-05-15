#include <iostream>
using namespace std;
#include "color.hpp"

Color* Color::setColor(int c) {
        Color *color=new Color();
    switch (c) {
        case 1:
            color->Red();
            break;
        case 2:
            color->Orange();
            break;
        case 3:
            color->Yellow();
            break;
        case 4:
            color->Green();
            break;
        case 5:
            color->Blue();
            break;
        case 6:
            color->Purple();
            break;
        case 7:
            color->Brown();
            break;
        case 8:
            color->Pink();
            break; 
    }
    return color;
}