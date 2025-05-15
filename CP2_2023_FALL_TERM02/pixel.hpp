#pragma once
#ifndef PIXEL_HPP
#define PIXEL_HPP
#include <stdlib.h>
#include <iostream>
using namespace std;
#define PNG_SETJMP_NOT_SUPPORTED
#include <png.h>

struct Pixel {
   png_byte r, g, b, a;
};
#endif 