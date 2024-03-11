 // Author: My Lu
// CECS 325-02 Prog 3
// Due 03/12/2024

//I certify that this program is my own original work. I did not copy any part of this program from any other source. 
//I further certify that I typed each and every line of code in this program

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argument, char* argv[]){

    if (argument != 4){
        cout << "need 4 argument to pass the command"<<endl;
    };

    //parse command line arguments

    int count = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    //ofstream outfile ("filename"): creates an object named "filename" of type ofstram
    //ofstream: a class in C++ : represents an output stream to a file
    //myFile : name of the objects that creating of type 'ofstream'
    //filename [aka: numbers.dat] : specifies that we want to open (or create if it doesn't exist), a file name numbers.dat in the 
    //current directory for writing
    ofstream myFile;
    myFile.open("numbers.dat");
    //seed the random number generator
    srand(time(0));
    //generate and write random numbers to the file
    for(int i = 0; i < count; i++){
        int myRandom = rand() % (max-min+1)+min;

        //myFile : an output file stream object ot which you want to write data
        //write myRandom [data] into myFile
        myFile << myRandom << endl;
    }

    //close myFile
    myFile.close();

    return 0;
}