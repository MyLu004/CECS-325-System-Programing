//HEADER FOR CARD.CPP
// Author: My Lu
// CECS 325-02 Prog 1
// Due 02/16/2024

//I certify that this program is my own original work. I did not copy any part of this program from any other source. 
//I further certify that I typed each and every line of code in this program
#ifndef Card_h
#define Card_h

#include <iostream>
#include <cmath>

using namespace std;

class Card{
    private:
        char mySuit; 
        char myRank;
    public:
        Card(char mySuit, char myRank); //storing the object: SuitRank into the Card vector
        void display();    //display Card function
        int compare(Card other); //comparison car function
};


#endif