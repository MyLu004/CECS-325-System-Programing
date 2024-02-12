#include <iostream>
#include <cmath>

//ARRAY
using namespace std;

int main()
{
    
    //data type for the array
    // in this case, the bracket is empty, which will only able to hold the data we have for know
    int myNumList[] = {2, 7, 12, 24, 36};
    cout <<"my number list: " <<myNumList[0]<<endl; //2

    //we could also assign the size for the array as well
    int mysecondList[6] = {1,2,3,4,5,6};

    //reassing the value as wekk
    mysecondList[2] = 10;
    cout << "my second array list: "<< mysecondList[2]<<endl; //10

    return 0;
}