
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


void mySwap(int &x,int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;

}

int main(){
    int a;
    int b;
    
    a= 10;
    b=20;

    cout <<"before swapping: "<<endl;
    cout << a << "\n" <<b <<endl;

    mySwap(a,b);

    cout << "after swapping: "<<endl;
    cout << a << "\n" <<b <<endl;
}