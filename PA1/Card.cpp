//SOURCE CODE CARD.CPP

#include <iostream>
#include "Card.h"
#include <cmath>

using namespace std;

Card::Card(char suit, char rank){
    mySuit = suit;
    myRank = rank;
}

void Card::display(){
    //display each card
    cout<< myRank << mySuit << " ";
}

int Card::compare(Card other){
    //how ranks work in the vector: according to the ASCII character set (which commonly use in C++). 
    // 1<2<3<4<5<6<7<8<9<10<J<Q<K 
    //the comparison operator follow the ASCII character order
    cout<< "my rank: "<< myRank << endl;
    cout<< "other rank: "<< other.myRank << endl;


    //if player 1 card.rank larger than player 2
    if(myRank > other.myRank){
        return 1;
    }

    //if player 1 card.rank smaller than player 2
    else if (myRank < other.myRank){
        return -1;
    }
    
    //if player 1 card.rank equal to player 2
    else{
        return 0;
    }
}