#include <iostream>
using namespace std;
class PrintColor{
    public:
        string Red="\033[0;31m";
        string Orange="\033[38;5;208m";
        string Yellow="\033[0;33m";
        string Green="\033[0;32m";
        string Blue="\033[0;34m";
        string Purple="\033[38;5;93m";
        string Brown="\033[38;5;94m";
        string Pink= "\033[38;5;13m";
        string Default= "\033[0m";

        bool bold; 
        bool tilt;
        void Print(const char * text,string color= "\033[0m", bool bold=false, bool tilt=false);
        PrintColor(){}
        ~PrintColor(){}
};