#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    char val1 = '2';
    val1 = '3';
    val1 = val1;
    cout<<val1;
}