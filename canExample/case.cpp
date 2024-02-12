#include <iostream>

#include "case.h"
#include "can.h"


using namespace std;

Case::Case()
{
    storage.clear();
}

void Case::add(Can c)
{
    storage.push_back(c);
}

void Case::display()
{
    for (int i = 0; i < storage.size(); i++)
       storage[i].display();
}