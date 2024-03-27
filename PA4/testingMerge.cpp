#include <iostream>
#include <pthread.h>
#include <string>

using namespace std;

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
};

int main(){

    int array1[5] = {2,4,6,8,10};
    int array2[5] = {1,3,5,7,9};
    int array3[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i<10; i++){
        array1[i] = array3[i];
        cout<<array1[i]<<endl;
    }

    cout<<sizeof(array1)<<endl;
}