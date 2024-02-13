//HEADER FOR CARD.CPP

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