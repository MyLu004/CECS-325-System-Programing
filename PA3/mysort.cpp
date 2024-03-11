#include <iostream>
// #include <vector>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void swapFunction(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
};

void bubble(int *myArr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        int swaps = 0;

        for (int j = 0; j < arrSize-1; j++){
            if(myArr[j] > myArr[j+1]){
                //swap the item if the next item is biggier
                swapFunction(myArr[j],myArr[j+1]);
                swaps = 1;
            };
        };
        if(!swaps)
        break;
    };

};

int main(){
    cout<<"what up"<<endl;

    int myArr[5] = {5,6,2,12,0};
    int arrSize = sizeof(myArr)/sizeof(myArr[0]);
    cout<<"my array size: "<<arrSize<<endl;
    cout<<"Array before sorting"<<endl;
    
    for(int i=0; i < arrSize; i++)
        cout<< myArr[i]<<" ";
    cout<<endl;

    bubble(myArr, arrSize);

    cout<<"Array after sorting"<<endl;
    
    for(int i=0; i < arrSize; i++)
        cout<< myArr[i]<<" ";
    cout<<endl;

    return 0;
};