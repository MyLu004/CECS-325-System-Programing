#include <iostream>
#include <typeinfo>
using namespace std;


int minusFunction(int val){
    val--;
    return val;
};

int main(){
    int myvalue = 10;
    try{
        for (int i = 0; i< 15; i--){
            myvalue--;
            if (myvalue<0){
                throw myvalue;
            }
        };
    }
    catch (int myvalue){
        cout<<"NEGATIVE NUMBER \n";
    };

    cout<<"IT END HERE";
    return 0;

};