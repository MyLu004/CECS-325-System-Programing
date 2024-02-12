#include <iostream>

//include file.h to able to access to the class in diff file
#include "can.h"
#include "case.h"

using namespace std;

int main(){
    Can c1;
    Can c2("Cocacola", 14);
    c2.display();

    Case myCase;
    myCase.add(Can("Bean", 18));
    myCase.add(Can("Pespi", 10));
    myCase.add(Can("Sprite", 12));

    cout << "stuff in my case: "<<endl;
    myCase.display();

    return 0;
}