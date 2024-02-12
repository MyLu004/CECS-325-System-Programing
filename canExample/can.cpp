#ifndef can_h
#define can_h

#include <iostream>
#include <string>
#include "can.h"

using namespace std;

//class :: constructor
Can::Can()
{
    //attribute
    contents = "Empty";
    size = 0;
};

Can::Can(string cont, int s)
{
    contents = cont;
    size = s;
};

void Can::display(){
    std::cout<< " " << size << " ounces of "<< contents << endl;
}

#endif