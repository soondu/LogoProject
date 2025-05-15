#ifndef COLOR_HPP
#define COLOR_HPP
class Color{
   protected:
      int r, g, b,a;
   public:
      Color(): r(0), g(0), b(0),a(255){}
      ~Color(){}

      int getR() const { return r; }
      int getG() const { return g; }
      int getB() const { return b; }

      void Red(){ r=240; g=0; b=0; a=255;}
      void Pink(){ r=255; g=153; b=204; a=255;}
      void Orange(){ r=255; g=128; b=0; a=255;}
      void Yellow(){ r=255; g=255; b=70; a=255;}
      void Green(){ r=0; g=153; b=0; a=255;}
      void Blue(){ r=0; g=100; b=255; a=255;}
      void Purple(){ r=153; g=51; b=255; a=255;}
      void Brown(){ r=139; g=69; b=19; a=255;}
      Color* setColor(int);
};
#endif