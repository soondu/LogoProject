#include <iostream>
#include <string>
#include <limits>
#include "input.h"
#include "pixel.hpp"
#include "shape.hpp"
#include "printcolorful.hpp"
using namespace std;

void Inp::getInput(string* wrd, int* e, int* flip, int* co){
   //문자열 입력
   PrintColor p;
   p.Print("*****write your string (enter a backslash for line change)*****\nyour string: ", p.Default,true);
   getline(cin, *wrd);
   *e=wrd->length();
   int bu;

   //색깔 설정   
   p.Print("***********************choose your color***********************\n", p.Default,true);
   p.Print("1. red\n", p.Red);
   p.Print("2. orange\n", p.Orange);
   p.Print("3. yellow\n", p.Yellow);
   p.Print("4. green\n", p.Green);
   p.Print("5. blue\n", p.Blue);
   p.Print("6. purple\n", p.Purple);
   p.Print("7. brown\n", p.Brown);
   p.Print("8. pink\n", p.Pink);
   p.Print("your choice: ",p.Default,true);

   while(1){
      cin>>bu;
      *co=bu;
      cin.clear();
      if(bu<1||bu>8){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         p.Print("##########Invalid input. Please enter correct number.##########\nyour choice: ",p.Default,true);
      }
      else break;
   }

   //뒤집기
   p.Print("***************which way do you want to flip it?***************\n",p.Default,true);
   p.Print("1. I don't want to flip.\n2. from side to side.\n3. from up and down.\n",p.Default,true);
   p.Print("your choice: ",p.Default,true);
   cin.clear();
   while(1){
      cin>>bu;
      *flip=bu;
      cin.clear();
      if(bu<1||bu>3){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         p.Print("##########Invalid input. Please enter correct number.##########\nyour choice: ",p.Default,true);
      }
      else break;
   }
}

//max와 cnt설정
void Inp::findTarget(string wrd, int* cnt, int* max){
    int ma=0,len=0, pos=0;
    int e=wrd.length();
    for(int i=0;i<e;i++){
        
        if(i==e-1){
            if(wrd[i]=='\\') { len=i-pos-1; }
            else if(wrd[pos]=='\\'){ len=i-pos; }
        }
        else if(wrd[i]=='\\'){
            if(wrd[pos]=='\\'){
                len=i-pos-1;
                pos=i;
            }
            else{
                len=i-pos;
                pos=i;
            }
            *cnt=(*cnt) +1;
        }
        if(ma<len) {
            ma=len;
        }    
    }
    if (*cnt==0) {
        ma=e;
    }
    *max=ma;
}

void SelectShape::select(int* co_s){
    PrintColor p;
    p.Print("***********************choose your shape***********************",p.Pink,true);
    cout<<endl;
    p.Print("1. Rectangle\n2. Triangle\n3. Circle\n",p.Default,true);
    p.Print("If you input other number, the shape will be default value:NONE\n",p.Default,true);
    p.Print("your choice: ",p.Default,true);
    char choice; cin>>choice;
    bool shapecolor = true;
    
    int width=0, height=0;

    switch (choice){
        case '1':
            shape=Shape::REC;
            width = std::min(word_width + 4, 1000);
            height = std::min(word_height + (word_height < 9 ? 4 : 5), 1000);
            rec=Rectangle(height, width);
            png_HEIGHT=rec.height;
            png_WIDTH=rec.width;
            break;
        case '2':
            shape=Shape::TRI;
            width = std::min(std::max(word_width + 5, 19), 1000);
            tri= Triangle(width);
            png_HEIGHT=tri.height;
            png_WIDTH=tri.length;
            break;
        case '3':
            shape=Shape::CIRCLE;
            width=(word_width>400)?200:word_width*0.5+4;
            circle=Circle(width);
            png_HEIGHT=circle.height;
            png_WIDTH=circle.width;
            break;
        default:
            shape=Shape::NONE;
            shapecolor=false;
            break;
    }

    if(shapecolor){
        
      p.Print("***********************choose your color***********************\n",p.Default,true);
      p.Print("1. red\n", p.Red);
      p.Print("2. orange\n", p.Orange);
      p.Print("3. yellow\n", p.Yellow);
      p.Print("4. green\n", p.Green);
      p.Print("5. blue\n", p.Blue);
      p.Print("6. purple\n", p.Purple);
      p.Print("7. brown\n", p.Brown);
      p.Print("8. pink\n", p.Pink);
      p.Print("your choice: ",p.Default,true);
        while(1){
      int bu; cin>>bu;
      *co_s=bu;
      cin.clear();
      if(bu<1||bu>8){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         p.Print("##########Invalid input. Please enter correct number.##########\nyour choice: ",p.Default,true);
      }
      else break;
   }
    }

}