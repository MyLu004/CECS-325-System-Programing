#include <iostream>
// #include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int max = 124;
    int min = 45;

    // it will given the same random output 
    //to able get the different random output, using time to generate
    //srand(0); -> the default value for srand
    srand(time(0));
    for (int i = 0; i < 5; i++){
        cout<< rand() % (max-min+1)+min<<" - "<< time(0)<< endl;
        // generate random between min and max
        // modules the max-min+1, then add min to add up the value
    };

    return 0;
}