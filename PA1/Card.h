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
        Card(char mySuit, char myRank);
        void display();    
        int compare(Card other);
};


#endif