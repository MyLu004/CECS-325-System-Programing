// usage: $ bucketList 100 100 1000000 9000000
// bucketList bucketCount bucketSize min max


#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;


//initial the globalswaprcount to keep track with the swap counting
int globalSwapCount = 0;

class Bucket{
    private:
        vector<int> v;
    public:
        Bucket();
        void generate(int size, int min, int max);
        void sort(); // Use the bubble sort from Prog3 and Prog4
        int size();
        int atIndex(int);
        int merge(Bucket b); // merge b into this
};


void generate (int size, int min, int max){
    ofstream myFile;
    myFile.open("bubble.dat");
    for(int i = 0; i < size; i++){
            int myRandom = rand() % (max-min+1)+min;

            //myFile : an output file stream object ot which you want to write data
            //write myRandom [data] into myFile
            myFile << myRandom << endl;
        }
}

void swapFunction(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
};

//TO-DO: Fix the parameter for this function 
void sort(int *myArr, int arrSize){
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

//TO-DO:fix the parameter for this function
void merge(int* array1, int section1, int* array2, int section2){
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




int main(int argc, char *argv[])
{
    srand(time(0));
    int bucketCount = stoi(argv[1]);
    int bucketSize = stoi(argv[2]);
    int bucketMin = stoi(argv[3]);
    int bucketMax = stoi(argv[4]);
    cout << "Bucket Count:"<<bucketCount<<endl;
    cout << "Bucket Size:"<<bucketSize<<endl;
    cout << "Bucket Min Value:"<<bucketMin<<endl;
    cout << "Bucket Max value:"<<bucketMax<<endl;
    vector<Bucket> list; // create empty Bucket vector
    Bucket *bptr;


    for(int i=0; i<bucketCount; i++) // creating bucketCount Buckets
    {
        bptr = new Bucket; // allocating new Bucket
        bptr->generate(bucketSize, bucketMin, bucketMax);

        //Bucket::generate(int,int,int,int)

        list.push_back(*bptr); // pushing Bucket onto list
    }
    for (auto it = list.begin(); it != list.end(); it++)
    {
        it->sort(); // Bucket::sort
    }
    Bucket endGame; // create empty Bucket to merge ALL buckets
    while (list.size() > 0) // vector<Bucket>::size()
    {
        endGame.merge(list[0]); // merge first bucket in list into

        endGame;

        list.erase(list.begin()); // erase the first bucket in the list
    }
    // write all the numbers in endGame bucket to a file
    fstream out("bucketList.out", ios::out);
    for(int i=0; i<endGame.size(); i++) // Bucket::size()
    {
        out << endGame.atIndex(i) << endl; // Bucket::atIndex(int)
        cout << "Global Swap Count:"<<globalSwapCount<<endl;
        cout << "\nbucketList.out has "<<bucketCount * bucketSize<< " sorted numbers\n";
    }
    return 0;
}