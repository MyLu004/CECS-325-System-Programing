
#include <iostream>
#include "Card.h"
#include <cmath>

using namespace std;

Card::Card(char suit, char rank){
    mySuit = suit;
    myRank = rank;
}

void Card::display(){
    cout<< myRank << mySuit << " ";
}

int Card::compare(Card other){
    if(myRank > other.myRank){
        return 1;
    }
    else if (myRank < other.myRank){
        return -1;
    }
    else{
        return 0;
    }
}