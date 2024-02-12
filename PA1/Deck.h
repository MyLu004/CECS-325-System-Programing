#ifndef Deck_h
#define Deck_h

#include <vector>
#include "Card.h"

using namespace std;

class Deck{
    private:
        vector<Card> cards;
    public:
        Deck();
        Card deal();
        void display();
        void shuffle();
};

#endif