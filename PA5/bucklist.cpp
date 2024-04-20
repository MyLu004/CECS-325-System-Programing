// usage: $ bucketList 100 100 1000000 9000000
// bucketList bucketCount bucketSize min max


#include <iostream>
#include <algorithm>
#include <random>
// #include <chrono>
// #include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;


//initial the globalswaprcount to keep track with the swap counting
int globalSwapCount = 0;

class Bucket{
    private:
        vector<int> myVector;
    public:

        //default constructor
        Bucket(){}

        //-----------DONE
        void generate(int size, int min, int max){
            cout<<"generation function"<<endl;
            ofstream myFile;
            myFile.open("bubble.dat");
            for(int i = 0; i < size; i++){
                int myRandom = rand() % (max-min+1)+min;

                //myFile : an output file stream object ot which you want to write data
                //write myRandom [data] into myFile
                myFile << myRandom << endl;
                cout << "generate: for in"<<endl;

            }
        };

        //-----------DONE
        void sort(){
            cout<<"sort function"<<endl;
            for(int i = 0; i < myVector.size(); i++){
                    int swaps = 0;

                    for (int j = 0; j < myVector.size()-1; j++){
                        if(myVector[j] > myVector[j+1]){
                            //swap the item if the next item is biggier
                            // swapFunction(myArr[j],myArr[j+1]);
                            int temp;
                            temp = myVector[j];
                            myVector[j] = myVector[j+1];
                            myVector[j+1] = temp;
                            globalSwapCount++;
                            swaps = 1;
                        };
                    };
                    // cout <<"my swap: "<<swaps<<endl;
                    if(!swaps) //if there nothing to swap, break
                    break;
                };
        };
            // cout <<"my swap: "<<swaps<<endl
     // Use the bubble sort from Prog3 and Prog4


        //-------------- DONE
        int size(){
            cout<<"size function"<<endl;
            return myVector.size();
        };

        //-----------------
        int atIndex(int location){
            cout<<"atIndex function"<<endl;
            return myVector.at(location);
        }
        //---------------
        // void merge(int* array1, int section1, int* array2, int section2){
        
        int merge(Bucket b) {
            cout<<"merge function"<<endl; 
            vector<int> temp;
            int i = 0, j = 0;

            while (i < myVector.size() && j < b.size()) {
                if (myVector[i] < b.atIndex(j)) {
                    temp.push_back(myVector[i]);
                    i++;
                } else {
                    temp.push_back(b.atIndex(j));
                    j++;
                }
            }

            // Copy any remaining elements from myVector
            while (i < myVector.size()) {
                temp.push_back(myVector[i]);
                i++;
            }

            // Copy any remaining elements from b
            while (j < b.size()) {
                temp.push_back(b.atIndex(j));
                j++;
            }

            // Update myVector with merged elements
            // myVector.clear();
            myVector = temp;

            return 0;
}

};

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
    
    //list vector: cotain the pointer for bptr, where bptr is the vector contain the number
    vector<Bucket> list; // create empty Bucket vector
    Bucket *bptr; //create pointer for type Bucket Vector 


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
    cout<<"it went here"<<endl;
    cout<<"my SIZE: "<< endGame.size()<<endl;
    fstream out("bucketList.out", ios::out);
    for(int i=0; i<endGame.size(); i++) // Bucket::size()
    {
        // myFile2 << myArray[i]<<endl;
        cout<<endGame.atIndex(i)<<endl;
        out << endGame.atIndex(i) << endl; // Bucket::atIndex(int)
        cout << "Global Swap Count:"<<globalSwapCount<<endl;
        cout << "\nbucketList.out has "<<bucketCount * bucketSize<< " sorted numbers\n";
    }
    return 0;
}