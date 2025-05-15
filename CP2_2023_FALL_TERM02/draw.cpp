#include "pixel.hpp"
#include "color.hpp"
#include "draw.h"
#define WIDTH 7
#define HEIGHT 7
#define COLOR_DEPTH 8
using namespace std;

/*draw alphabet*/
void Draw:: alph(Pixel** str, string wrd,int e){
    int idx=0;
    
    char target='\\';
    
    for(int i=0;i<e;i++){
      //set idx(=len)
      idx=wrd.find(target);
      if (i==e-1) {
         idx=wrd.length();
      }
      else if(idx==-1) { continue; }

      //draw alphabet
      if(r==1||r==3){
         for(int i=0;i<idx;i++) {
            draw(i, wrd[i]);
         }
      }
      if(r==2){
        for(int i=0;i<idx;i++) {
            draw(i, wrd[idx-i-1]);
        }
      }      
      z++;

      if(i==e-1){
         wrd.clear();
      }
      else wrd = wrd.substr(idx+1);

   }
}

void Draw:: fill(int i, int a, int b){
   int j=z;
   if(r==1) {
     str[a+HEIGHT*j+j][b+WIDTH*i].r=color->getR();
     str[a+HEIGHT*j+j][b+WIDTH*i].g=color->getG();
     str[a+HEIGHT*j+j][b+WIDTH*i].b=color->getB();
     str[a+HEIGHT*j+j][b+WIDTH*i].a=255;
   }
   else if(r==2){
     str[a + HEIGHT * j + j][WIDTH - 1 - b + WIDTH * i].r = color->getR();
     str[a + HEIGHT * j + j][WIDTH - 1 - b + WIDTH * i].g = color->getG();
     str[a + HEIGHT * j + j][WIDTH - 1 - b + WIDTH * i].b = color->getB();
     str[a + HEIGHT * j + j][WIDTH - 1 - b + WIDTH * i].a = 255;
   }
   else if(r==3){
      str[-a+HEIGHT*(cnt-j+1)+cnt-j-1][b+WIDTH * i].r = color->getR();
      str[-a+HEIGHT*(cnt-j+1)+cnt-j-1][b+WIDTH * i].g = color->getG();
      str[-a+HEIGHT*(cnt-j+1)+cnt-j-1][b+WIDTH * i].b = color->getB();
      str[-a+HEIGHT*(cnt-j+1)+cnt-j-1][b+WIDTH * i].a = 255;
   }
}

void Draw::draw(int i, char c){
   switch(c){
   case ' ':
   break;

   case 'a':
   fill(i, 2, 2);fill(i,2,3);fill(i,2,4);
     fill(i, 3, 5);
    fill(i, 4, 2); fill(i, 4, 3); fill(i,4,4);fill(i,4,5);
    fill(i,5,1);fill(i,5,5);
    fill(i, 6, 2); fill(i, 6, 3); fill(i,6,4);fill(i,6,5);
   break;

    case 'b':
    fill(i, 1, 1);
    fill(i, 2, 1);
    fill(i, 3, 1); fill(i, 3, 2); fill(i, 3, 3);fill(i,3,4);
    fill(i, 4, 1);fill(i, 4, 5);
    fill(i, 5, 1);fill(i, 5, 5);
    fill(i, 6, 1); fill(i, 6, 2); fill(i, 6, 3);fill(i,6,4);
    break;

    case 'c':
    fill(i,2, 2); fill(i,2,3);fill(i,2,4);fill(i,2,5);
    fill(i,3,1);
    fill(i,4,1);
    fill(i,5,1);
    fill(i, 6, 2); fill(i, 6, 3);fill(i,6,4);fill(i,6,5);
    break;

    case 'd':
    fill(i,0,5);
    fill(i,1,5);
    fill(i,2,5);
    fill(i,3,2); fill(i,3,3); fill(i,3,4);fill(i,3,5);
    fill(i,4,1);fill(i,4,5);
    fill(i,5,1);fill(i,5,5);
    fill(i, 6, 2); fill(i, 6, 3); fill(i,6,4);fill(i,6,5);
    break;

    case 'e':
    fill(i, 2, 2);fill(i,2,3);fill(i,2,4);
    fill(i,3,1);fill(i,3,5);
    fill(i,4,1);fill(i,4,2);fill(i,4,3);fill(i,4,4);
    fill(i,5,1);
    fill(i, 6, 2); fill(i, 6, 3); fill(i,6,4);fill(i,6,5);
    break;

    case 'f': 
    fill(i,0,3);fill(i,0,4);
    fill(i,1,2);
    fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);
    fill(i,3,2);
    fill(i,4,2);
    fill(i,5,2);
    fill(i,6,2);
    break;

    case 'g': 
    fill(i,1,3);fill(i,1,4);
    fill(i,2,2);fill(i,2,5);
    fill(i,3,2);fill(i,3,5);
    fill(i,4,3);fill(i,4,4);fill(i,4,5);
    fill(i,5,5);
    fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);
    break;

    case 'h': 
    fill(i, 0, 1);
    fill(i, 1, 1);
    fill( i, 2, 1);
    fill( i, 3, 1); fill(i, 3, 2);fill(i,3,3);fill(i,3,4);
    fill( i, 4, 1);fill(i, 4, 5);
    fill( i, 5, 1);fill(i, 5, 5);
    fill( i, 6, 1);fill(i,6,5);
    break;

    case 'i': 
    fill(i,0,3);
    fill(i,2,2);fill(i,2,3);
    fill(i,3,3);
    fill(i,4,3);
    fill(i,5,3);
    fill(i,6,2);fill(i,6,3);fill(i,6,4);
    break;

    case 'j': 
    fill(i,0,3);
    fill(i,2,3);
    fill(i,3,3);
    fill(i,4,3);
   fill(i,5,1); fill(i,5,3);
    fill(i,6,2);
    break;

    case 'k': 
   fill(i, 0, 1);
    fill(i, 1, 1);
    fill( i, 2, 1); fill(i,2,4);
    fill( i, 3, 1); fill(i, 3, 3);
    fill( i, 4, 1);fill(i, 4, 2);
    fill( i, 5, 1);fill(i, 5, 3);
    fill( i, 6, 1);fill(i,6,4);
    break;

    case 'l': 
   fill(i, 0, 2);
    fill(i, 1, 2);
    fill( i, 2, 2);
    fill( i, 3, 2);
    fill( i, 4, 2);
    fill( i, 5, 2);
    fill( i, 6, 3); fill(i, 6, 4);
    break;

   case 'm':
   fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,3);fill(i,3,5);
   fill(i,4,1);fill(i,4,3);fill(i,4,5);   
   fill(i,5,1);fill(i,5,3);fill(i,5,5);
   fill(i,6,1);fill(i,6,3);fill(i,6,5);
   break;
   
   case 'n': 
   fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);   
   fill(i,5,1);fill(i,5,5);
   fill(i,6,1);fill(i,6,5);
   break;

   case 'o': 
   fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);   
   fill(i,5,1);fill(i,5,5);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'p': 
   fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,5); 
   fill(i,4,1);fill(i,4,5);
   fill(i,5,1);fill(i,5,2);fill(i,5,3);fill(i,5,4);
   fill(i,6,1);
   break;

   case 'q': 
   fill(i,2,2);fill(i,2,3);fill(i,2,4);fill(i,2,5);
   fill(i,3,1);fill(i,3,5); 
   fill(i,4,1);fill(i,4,5);
   fill(i,5,2);fill(i,5,3);fill(i,5,4);fill(i,5,5);
   fill(i,6,5);
   break;

   case 'r':    
   fill(i,2,1);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,2);
   fill(i,3,1);
   fill(i,4,1);   
   fill(i,5,1);
   fill(i,6,1);
   break;

   case 's': 
   fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);
   fill(i,4,2);fill(i,4,3);fill(i,4,4);
   fill(i,5,5);
   fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 't': 
   fill(i,1,3);
   fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);fill(i,2,5);
   fill(i,3,3);
   fill(i,4,3);
   fill(i,5,3);
   fill(i,6,4);fill(i,6,5);
   break;

   case 'u': 
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);   
   fill(i,5,1);fill(i,5,5);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'v': 
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);   
   fill(i,5,2);fill(i,5,4);
   fill(i,6,3);;
   break;

   case 'w': 
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,3);fill(i,4,5);   
   fill(i,5,1);fill(i,5,3);fill(i,5,5);
   fill(i,6,2);fill(i,6,4);
   break;

   case 'x': 
   fill(i,2,1);fill(i,2,5);
   fill(i,3,2);fill(i,3,4);
   fill(i,4,3);
   fill(i,5,2);fill(i,5,4);
   fill(i,6,1);fill(i,6,5);
   break;

   case 'y':
   fill(i,2,2);fill(i,2,4);
   fill(i,3,2);fill(i,3,4);
   fill(i,4,2);fill(i,4,3);fill(i,4,4);
   fill(i,5,4);
   fill(i,6,2);fill(i,6,3);
   break;

   case 'z': 
   fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,4);
   fill(i,4,3);   
   fill(i,5,2);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case '0':
   fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
   fill(i, 1, 1);fill(i, 1, 4);fill(i, 1, 5);
   fill(i, 2, 1);fill(i, 2, 4);fill(i, 2, 5);
   fill(i, 3, 1);fill(i, 3, 3);fill(i, 3, 5);
   fill(i, 4, 1);fill(i, 4, 2);fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 2);fill(i, 5, 5);
   fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);
   break;

   case '1':
   fill(i, 0, 3);
   fill(i, 1, 2);fill(i, 1, 3);
   fill(i, 2, 1);fill(i, 2, 3);
   fill(i, 3, 3);
   fill(i, 4, 3);
   fill(i, 5, 3);
   fill(i, 6, 1);fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);fill(i, 6, 5);
   break;

   case '2':
   fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);   
   fill(i, 1, 1); fill(i, 1, 5); 
   fill(i, 2, 5);
   fill(i, 3, 2);fill(i, 3, 3);fill(i, 3, 4);   
   fill(i, 4, 1);
   fill(i, 5, 1);
   fill(i, 6, 1);fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);fill(i, 6, 5);
   break;    

   case '3':
   fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
   fill(i, 1, 1); fill(i, 1, 5);
   fill(i, 2, 5);
   fill(i, 3, 3);fill(i, 3, 4);  
   fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 5);
   fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);
   break;

   case '4':
   fill(i, 0, 4);
   fill(i, 1, 3);fill(i, 1, 4);
   fill(i, 2, 2);fill(i, 2, 4);
   fill(i, 3, 2);fill(i, 3, 4);
   fill(i, 4, 1);fill(i, 4, 4);
   fill(i, 5, 1);fill(i, 5, 2);fill(i, 5, 3);fill(i, 5, 4);fill(i, 5, 5);
   fill(i, 6, 4);
   break;

   case '5':
   fill(i, 0, 1);fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);fill(i, 0, 5);
   fill(i, 1, 1);
   fill(i, 2, 1);fill(i, 2, 2);fill(i, 2, 3);fill(i, 2, 4);
   fill(i, 3, 5);
   fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 5);
   fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);
   break;

   case '6':
   fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);fill(i, 0, 5);
   fill(i, 1, 1);
   fill(i, 2, 1);
   fill(i, 3, 1);fill(i, 3, 2);fill(i, 3, 3);fill(i, 3, 4);fill(i, 3, 5);
   fill(i, 4, 1);fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 5);
   fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);
   break;

   case '7':
   fill(i, 0, 1);fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);fill(i, 0, 5);
   fill(i, 1, 5);
   fill(i, 2, 4);
   fill(i, 3, 3);
   fill(i, 4, 2);
   fill(i, 5, 2);
   fill(i, 6, 2);
   break;

   case '8':
   fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
   fill(i, 1, 1);fill(i, 1, 5);
   fill(i, 2, 1);fill(i, 2, 5);
   fill(i, 3, 2);fill(i, 3, 3);fill(i, 3, 4);
   fill(i, 4, 1);fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 5);
   fill(i, 6, 2);fill(i, 6, 3);fill(i, 6, 4);
   break;

   case '9':
   fill(i,0, 2);fill(i,0,3);fill(i,0,4);
    fill(i,1,1);fill(i,1,5);
    fill(i,2,1);fill(i,2,5);
    fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
    fill(i,4,5);
    fill(i,5,5);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
    break;

   case 'A':
   fill(i,0,2);fill(i,0,3);fill(i,0,4);
   fill(i,1,1);fill(i,1,5);
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);
   fill(i,5,1);fill(i,5,5);
   fill(i,6,1);fill(i,6,5);
   break;

   case 'B':
   fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);
   fill(i,1,1);fill(i,1,5);
   fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);
   fill(i,5,1);fill(i,5,5);
   fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'C':
   fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
   fill(i,1,1);
   fill(i,2,1);
   fill(i,3,1);
   fill(i,4,1);
   fill(i,5,1);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);fill(i,6,5);
   break;

   case 'D':
   fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);
   fill(i,1,1);fill(i,1,5);
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);
   fill(i,5,1);fill(i,5,5);
   fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'E':
   fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
   fill(i,1,1);
   fill(i,2,1);
   fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
   fill(i,4,1);
   fill(i,5,1);
   fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);fill(i,6,5);
   break;

   case 'F':
   fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
   fill(i,1,1);
   fill(i,2,1);
   fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
   fill(i,4,1);
   fill(i,5,1);
   fill(i,6,1);
   break;

   case 'G':
   fill(i,0,2);fill(i,0,3);fill(i,0,4);
   fill(i,1,1);fill(i,1,5);
   fill(i,2,1);
   fill(i,3,1);
   fill(i,4,1);fill(i,4,4);fill(i,4,5);
   fill(i,5,1);fill(i,5,5);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'H':
   fill(i,0,1);fill(i,0,5);
   fill(i,1,1);fill(i,1,5);
   fill(i,2,1);fill(i,2,5);
   fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
   fill(i,4,1);fill(i,4,5);
   fill(i,5,1);fill(i,5,5);
   fill(i,6,1);fill(i,6,5);
   break;

   case 'I':
   fill(i,0,2);fill(i,0,3);fill(i,0,4);
   fill(i,1,3);
   fill(i,2,3);
   fill(i,3,3);
   fill(i,4,3);
   fill(i,5,3);
   fill(i,6,2);fill(i,6,3);fill(i,6,4);
   break;

   case 'J':
   fill(i,0,3);fill(i,0,4);fill(i,0,5);
   fill(i,1,4);
   fill(i,2,4);
   fill(i,3,4);
   fill(i,4,4);
   fill(i,5,1);fill(i,5,4);
   fill(i,6,2);fill(i,6,3);
   break;

   case 'K':
   fill(i,0,1);fill(i,0,5);
   fill(i,1,1);fill(i,1,4);
   fill(i,2,1);fill(i,2,3);
   fill(i,3,1);fill(i,3,2);
   fill(i,4,1);fill(i,4,3);
   fill(i,5,1);fill(i,5,4);
   fill(i,6,1);fill(i,6,5);
   break;

   case 'L':
   fill(i,0,1);
   fill(i,1,1);
   fill(i,2,1);
   fill(i,3,1);
   fill(i,4,1);
   fill(i,5,1);
   fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);fill(i,6,5);
   break;

   case 'M':
   fill(i,0,1);fill(i,0,5);
   fill(i,1,1);fill(i,1,2);fill(i,1,4);fill(i,1,5);
   fill(i,2,1);fill(i,2,3);fill(i,2,5);
   fill(i,3,1);fill(i,3,3);fill(i,3,5);
   fill(i,4,1);fill(i,4,3);fill(i,4,5);
   fill(i,5,1);fill(i,5,3);fill(i,5,5);
   fill(i,6,1);fill(i,6,3);fill(i,6,5);
   break;

   case 'N':
   fill(i, 0, 1);fill(i, 0, 5);
   fill(i, 1, 1);fill(i,1,2);fill(i, 1, 5);
   fill(i, 2, 1);fill(i,2,3);fill(i, 2, 5);
   fill(i,3,1);fill(i, 3, 3);fill(i,3,5);
   fill(i, 4, 1);fill(i,4,4);fill(i, 4, 5);
   fill(i, 5, 1);fill(i, 5, 5);
   fill(i, 6, 1);fill(i, 6, 5);
   break;
 case 'O':
fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
fill(i, 1, 1);fill(i, 1, 5);
fill(i, 2, 1);fill(i, 2, 5);
fill(i, 3, 1);fill(i, 3, 5);
fill(i, 4, 1);fill(i, 4, 5);
fill(i, 5, 1);fill(i, 5, 5);
fill(i, 6, 2);fill(i,6,3);fill(i, 6, 4);
break;
case 'P':
 fill(i,0,1);fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
 fill(i, 1, 1);fill(i, 1, 5);
 fill(i, 2, 1);fill(i, 2, 5);
 fill(i, 3, 1);fill(i, 3, 2);fill(i, 3, 3);fill(i, 3, 4);
 fill(i, 4, 1);
 fill(i, 5, 1);
 fill(i, 6, 1);
 break;
case 'Q':
fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
fill(i, 1, 1);fill(i, 1, 5);
fill(i, 2, 1);fill(i, 2, 5);
fill(i, 3, 1);fill(i, 3, 5);
fill(i, 4, 1);fill(i,4,3);fill(i, 4, 5);
fill(i, 5, 1);fill(i,5,4);fill(i, 5, 5);
fill(i, 6, 2);fill(i,6,3);fill(i, 6, 4);
break;
case 'R':
 fill(i,0,1);fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
 fill(i, 1, 1);fill(i, 1, 5);
 fill(i, 2, 1);fill(i, 2, 5);
 fill(i, 3, 1);fill(i, 3, 2);fill(i, 3, 3);fill(i, 3, 4);
 fill(i, 4, 1);fill(i,4,2);
 fill(i, 5, 1);fill(i,5,3);
 fill(i, 6, 1);fill(i,6,4);fill(i,6,5);
 break;

case 'S':
 fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
 fill(i,1,1);
 fill(i,2,1);
 fill(i,3,2);fill(i,3,3);fill(i,3,4);
 fill(i,4,5);
 fill(i,5,5);
 fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);
 break;

case 'T':
 fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
 fill(i,1,3);
 fill(i,2,3);
 fill(i,3,3);
 fill(i,4,3);
 fill(i,5,3);
 fill(i,6,3);
 break;

case 'U':
fill(i, 0, 1);fill(i, 0, 5);
fill(i, 1, 1);fill(i, 1, 5);
fill(i, 2, 1);fill(i, 2, 5);
fill(i, 3, 1);fill(i, 3, 5);
fill(i, 4, 1);fill(i, 4, 5);
fill(i, 5, 1);fill(i, 5, 5);
fill(i, 6, 2);fill(i,6,3);fill(i, 6, 4);
break;

case 'V':
 fill(i,0,1);fill(i,0,5);
 fill(i,1,1);fill(i,1,5);
 fill(i,2,1);fill(i,2,5);
 fill(i,3,1);fill(i,3,5);
 fill(i,4,2);fill(i,4,4); 
 fill(i,5,2);fill(i,5,4);
 fill(i,6,3);
 break;

case 'W':
 fill(i,0,1);fill(i,0,5);
 fill(i,1,1);fill(i,1,5);
 fill(i,2,1);fill(i,2,3);fill(i,2,5);
 fill(i,3,1);fill(i,3,3);fill(i,3,5);
 fill(i,4,1);fill(i,4,3);fill(i,4,5); 
 fill(i,5,1);fill(i,5,3);fill(i,5,5);
 fill(i,6,2);fill(i,6,4);
 break; 

 case 'X':
 fill(i,0,1);fill(i,0,5);
 fill(i,1,1);fill(i,1,5);
 fill(i,2,2);fill(i,2,4);
 fill(i,3,3);
 fill(i,4,2);fill(i,4,4);
 fill(i,5,1);fill(i,5,5);
 fill(i,6,1);fill(i,6,5);
 break; 

 case 'Y':
 fill(i,0,1);fill(i,0,5);
 fill(i,1,1);fill(i,1,5);
 fill(i,2,2);fill(i,2,4);
 fill(i,3,3);
 fill(i,4,3);
 fill(i,5,3);
 fill(i,6,3);
 break; 

 case 'Z':
 fill(i,0,1);fill(i,0,2);fill(i,0,3);fill(i,0,4);fill(i,0,5);
 fill(i,1,5);
 fill(i,2,4);
 fill(i,3,3);
 fill(i,4,2); 
 fill(i,5,1);
 fill(i,6,1);fill(i,6,2);fill(i,6,3);fill(i,6,4);fill(i,6,5);
 break;

case '!':
 fill(i,0,3);
 fill(i,1,3);
 fill(i,2,3);
 fill(i,3,3);
 fill(i,4,3);
 fill(i,6,3);
 break;
case '?': 
      fill(i,0, 2);fill(i,0,3);fill(i,0,4);
      fill(i,1,1);fill(i,1,5);
      fill(i,2,4);
      fill(i,3,3);
      fill(i,4,3);
      fill(i,6,3);
      break;
case '#':
     fill(i,0,1);fill(i,0,5);
     fill(i,1,0);fill(i,1,1);fill(i,1,2);fill(i,1,3);fill(i,1,4);fill(i,1,5);
     fill(i,1,6);fill(i,2,1);fill(i,2,5);
     fill(i,3,1);fill(i,3,5);
     fill(i,4,1);fill(i,4,5);
     fill(i,5,0);fill(i,5,1);fill(i,5,2);fill(i,5,3);fill(i,5,4);fill(i,5,5);
     fill(i,5,6);fill(i,6,1);fill(i,6,5);
     break;
case '"':
     fill(i,0 ,2);fill(i,0,4);
     fill(i,1 ,2);fill(i,1,4);
     break;
case '$':
     fill(i,0 ,3);
     fill(i,1,2);fill(i,1,3);fill(i,1,4);fill(i,1,5);
     fill(i,2,1);fill(i,2,3);
     fill(i,3,2);fill(i,3,3);fill(i,3,4);
     fill(i,4,3);fill(i,4,5);
     fill(i,5,1);fill(i,5,2);fill(i,5,3);fill(i,5,4);
     fill(i,6,3);
     break;
case '%':
 fill(i,0 ,6);
 fill(i,1,2);fill(i,1,5);
 fill(i,2,4);
 fill(i,3,3);
 fill(i,4,2);
 fill(i,5,1);fill(i,5,5);
 fill(i,6,0);
 break;
case '&':
 fill(i,0 ,2);fill(i,0,3);
 fill(i,1,1);fill(i,1,4);
 fill(i,2,1);fill(i,2,4);
 fill(i,3 ,2);fill(i,3,3);
 fill(i,4,1);fill(i,4,3);fill(i,4,5);
 fill(i,5,1);fill(i,5,4);
 fill(i,6,2);fill(i,6,3);fill(i,6,5);
 break;
case '(':
 fill(i,0 ,3);
 fill(i,1,2);
 fill(i,2,2);
 fill(i,3,2);
 fill(i,4,2);
 fill(i,5,2);
 fill(i,6,3);
 break;
case ')':
 fill(i,0 ,4);
 fill(i,1,5);
 fill(i,2,5);
 fill(i,3,5);
 fill(i,4,5);
 fill(i,5,5);
 fill(i,6,4);
 break;
case '*':
 fill(i,1,1);fill(i,1,5);
 fill(i,2,2);fill(i,2,4);
 fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
 fill(i,4,2);fill(i,4,4);
 fill(i,5,1);fill(i,5,5);
 break;
case '-':
 fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
 break;
case '+':
 fill(i,1,3);
 fill(i,2,3);
 fill(i,3,1);fill(i,3,2);fill(i,3,3);fill(i,3,4);fill(i,3,5);
 fill(i,4,3);
 fill(i,5,3);
 break;
case ',':
 fill(i,4,3);
 fill(i,5,3);
 fill(i,6,2);
 break;
case '.':
 fill(i,5,2);fill(i,5,3);
 fill(i,6,2);fill(i,6,3);
 break;
case '/':
 fill(i,0 ,6);
 fill(i,1,5);
 fill(i,2,4);
 fill(i,3,3);
 fill(i,4,2);
 fill(i,5,1);
 fill(i,6,0);
 break;
case '<':
 fill(i,0 ,4);
 fill(i,1,3);
 fill(i,2,2);
 fill(i,3,1);
 fill(i,4,2);
 fill(i,5,3);
 fill(i,6,4);
 break;
case '>':
 fill(i,0 ,2);
 fill(i,1,3);
 fill(i,2,4);
 fill(i,3,5);
 fill(i,4,4);
 fill(i,5,3);
 fill(i,6,2);
 break;
case '=':
 fill(i,2,1);fill(i,2,2);fill(i,2,3);fill(i,2,4);fill(i,2,5);
 fill(i,4,1);fill(i,4,2);fill(i,4,3);fill(i,4,4);fill(i,4,5);
 break;
case '[':
 fill(i,0,2);fill(i,0 ,3);
 fill(i,1,2);
 fill(i,2,2);
 fill(i,3,2);
 fill(i,4,2);
 fill(i,5,2);
 fill(i,6,2);fill(i,6,3);
 break;
case ']':
 fill(i,0 ,4);fill(i,0,5);
 fill(i,1,5);
 fill(i,2,5);
 fill(i,3,5);
 fill(i,4,5);
 fill(i,5,5);
 fill(i,6,4);fill(i,6,5);
 break;
case '@':
fill(i, 0, 2);fill(i, 0, 3);fill(i, 0, 4);
fill(i, 1, 1);fill(i, 1, 5);
fill(i, 2, 1);fill(i,2,3);fill(i,2,4);fill(i, 2, 5);
fill(i, 3, 1);fill(i,3,3);fill(i, 3, 5);
fill(i, 4, 1);fill(i,4,3);fill(i, 4, 5);
fill(i, 5, 1);
fill(i, 6, 2);fill(i,6,3);fill(i, 6, 4);
break;
case ':':
 fill(i,1,3);
 fill(i,5,3);
 break;
case ';':
 fill(i,1,3);
 fill(i,3,3);
 fill(i,4,3);
 fill(i,5,2);
 break;
 case '~':
 fill(i,2,2);
 fill(i,3,1);fill(i,3,3);fill(i,3,5);
 fill(i,4,1);fill(i,4,3);fill(i,4,5);
 fill(i,5,4);
 break;
case '_':
 fill(i,6,2);fill(i,6,3);fill(i,6,4);
 break;
case '{':
 fill(i,0 ,3);
 fill(i,1,2);
 fill(i,2,2);
 fill(i,3,1);fill(i,3,2);
 fill(i,4,2);
 fill(i,5,2);
 fill(i,6,3);
 break;
case '}':
 fill(i,0 ,3);
 fill(i,1,4);
 fill(i,2,4);
 fill(i,3,4);fill(i,3,5);
 fill(i,4,4);
 fill(i,5,4);
 fill(i,6,3);
 break;
case '^':
 fill(i,0 ,3);
 fill(i,1,2);fill(i,1,4);
 fill(i,2,1);fill(i,2,5);
 break;
case '\'':
fill(i,0,3);
fill(i,1,3);
fill(i,2,2);
 
}
}