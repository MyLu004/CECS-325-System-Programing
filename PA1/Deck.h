//HEADER FOR DECK.CPP
// Author: My Lu
// CECS 325-02 Prog 1
// Due 02/16/2024

//I certify that this program is my own original work. I did not copy any part of this program from any other source. 
//I further certify that I typed each and every line of code in this program

#ifndef Deck_h
#define Deck_h

#include <vector>
#include "Card.h"

using namespace std;

//class Deck
class Deck{
    private:
        //declare private membere variable card, which is a vector of Card objects.
        vector<Card> cards; //vector to hold the cards in the deck
    public:
        //public member variable
        Deck(); // the constructor of Deck class
        Card deal(); //the function deal to get the card from each players, by turns
        void display(); // display every cards [for original and shuffle]
        void shuffle(); // shuffle cards in random order
};

#endif