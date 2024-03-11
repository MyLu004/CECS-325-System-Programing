
#include <iostream>
#include <cmath>

using namespace std;

void addingFunction(int &a, int &b,int &myanswer){
    cout<<"my a: "<< a<<endl;
    cout<<"my b: "<< b<<endl;

    myanswer = a+b;
};

int main(){
    int x = 10;
    int &y = x; //y reference from x [technique is x but had different name is y]

    y += 4;
    cout<<"my y: "<<y<<endl;

    int answer;

    addingFunction(x,y,answer);
    cout<<"my final answer: "<<answer<<endl;

};