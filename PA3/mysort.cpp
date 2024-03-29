 // Author: My Lu
// CECS 325-02 Prog 3
// Due 03/12/2024

//I certify that this program is my own original work. I did not copy any part of this program from any other source. 
//I further certify that I typed each and every line of code in this program


/*main function mysort need to do:
1. Read the contents of the input file (numbers.dat).
2. Populate an array with the numbers read from the file.
3. Call mysort function to sort the array.
4. Write the sorted array back to an output file (mysort.out).
5. Verify that the output file is sorted.
*/
#include <iostream>
// #include <vector>
#include <cmath>
#include <fstream>
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
        // cout <<"my swap: "<<swaps<<endl;
        if(!swaps) //if there nothing to swap, break
        break;
    };

};




int main(int argument, char* argv[]){

    //Purpose: sort numbers from numbers.dat, output to stdout (standard out)
    //Description: Uses bubble sort function on an array of integers
    //It will accept up to 1 million numbers from the input file, but will run successfully with less
    //It accepts 2 command line arguments which is the input file and the output file name

    //open in/out file
    ifstream myFile(argv[1]);
    if(!myFile){
        cerr <<"error, cannot open file"<<endl;
    };

    //read number fron input file into array
    const int mySize = 1000000;
    int myArray[mySize];
    int count = 0; //size of the array
    int num;
    while (myFile >> num && count < mySize){
        myArray[count++] = num;
    }
    myFile.close();

    //sorting the array using bubble

    bubble(myArray,count);

    ofstream myFile2(argv[2]);
    if(!myFile2){
        cerr <<"Error: unable ot open output file"<<endl;
    };

    //write sorted numbers to output file
    for (int i = 0; i < count ; i++){
        myFile2 << myArray[i]<<endl;
    }

    myFile2.close();

    return 0;
};
