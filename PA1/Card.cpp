//SOURCE CODE CARD.CPP

// Author: My Lu
// CECS 325-02 Prog 1
// Due 02/16/2024

//I certify that this program is my own original work. I did not copy any part of this program from any other source. 
//I further certify that I typed each and every line of code in this program

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
    if(myRank == 'T'){
        cout<< "10" << mySuit << " ";
    }
    else{
        cout<< myRank << mySuit << " ";
    }
    
}

// Card: the player1 object, and the other:is for the player2 object
int Card::compare(Card other){
    //how ranks work in the vector: according to the ASCII character set (which commonly use in C++). 
    // 1<2<3<4<5<6<7<8<9<10<J<Q<K 
    //the comparison operator follow the ASCII character order
    cout<< "my rank: "<< myRank << endl;
    cout<< "other rank: "<< other.myRank << endl;


    //if player 1 card.rank larger than player 2
    if(myRank > other.myRank){
        cout << myRank << endl;
        cout << other.myRank << endl;
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