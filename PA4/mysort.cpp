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
// #include <cmath>
#include <fstream>
// #include <string>
// #include <ctime>
// #include <cstdlib>

#include <chrono>
#include <pthread.h>
 
using namespace std;


//public variable
const int mySize = 1000000;

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

//structure sortStuff is defined to hold information about a section of the array to be sorted
struct sortStuff{
    int *start; // pointer - start of the array
    int size; // size - section of the array
};

// bridge function for pthread_create
// serves as an intermediate between the pthread and the sorting function (bubble)

/*
void* : cast to a pointer to 'sortStuff'

*/
void *bridge(void *ptr) {
    sortStuff *arg = (sortStuff *)ptr;

    // -> pointer structure of sortStuff to (*arg).size or (*arg).start
    // bubble is called with start pointer and size passed from the sortStuff
    bubble(arg->start, arg->size);
    return NULL;
}

void merge(int array1[], int section1, int array2[], int section2){
    //allocate memory for the temp array
    int* temp = new int[section1+section2];

    //loop and compare, and sort
    //merge sort structure

    //initialize the indices for array and merge array
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < section1 && j < section2){

        //if element array1 is larger than array 2
        if(array1[i] < array2[j]){
            temp[k] = array1[i];
            k++; //incremenet to the next idx of temp
            i++; // increment to the next idx of array1
        }
        else{
            temp[k] = array2[j];
            k++;
            j++; // increment to the next idx of array2
        }
    }

    //copy remaining elements from the first section [like in case we going through on the seciton 2, and sorted section2, so mean 
    // section1 , the left over element (already sorted) is the largest]

    while(i < section1){
        temp[k] = array1[i];
        k++;
        i++;
    };

    while(j < section1){
        temp[k] = array2[j];
        k++;
        j++;
    };

    //after had all the value in the temp array,temp is sorted [definitely], copy all numbers from temp back to array1


    for (int myidx = 0; myidx < section1+section2; myidx++){
        array1[myidx] = temp[myidx];
    };

    //delete the temp memory [heap]
    delete[] temp;
    
}




int main(int argument, char* argv[]){

    //Purpose: sort numbers from numbers.dat, output to stdout (standard out)
    //Description: Uses bubble sort function on an array of integers
    //It will accept up to 1 million numbers from the input file, but will run successfully with less
    //It accepts 2 command line arguments which is the input file and the output file name

    //open inoout file  
    ifstream myFile(argv[1]);
    if(!myFile){
        cerr <<"error, cannot open file"<<endl;
    };

    //read number fron input file into array
    
    int myArray[mySize];
    int count = 0; //size of the array
    int num;
    while (myFile >> num && count < mySize){
        myArray[count++] = num;
    }
    myFile.close();

    //sorting the array using bubble

    //PTHREAD START
    pthread_t myThread[8];
    sortStuff myStuff[8];

    //calculate section for each size
    //1,000,000,000 / 8 = 125 000 000 for each
    int myStuffSize = mySize / 8;

    //creating thread to sort sections of the array
    for (int i = 0; i < 8; i++){
        myStuff[i].start = &myArray[i*myStuffSize];
        myStuff[i].size = myStuffSize;

        pthread_create(&myThread[i], NULL, bridge, (void *)&myStuff[i]);
    };

    //joining thread
    for (int i = 0; i<8; i++){
        pthread_join(myThread[i], NULL);
    }

    //after all thread done, starting merge

    

    //bubble(myArray,count);

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