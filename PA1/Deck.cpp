//SOURCE CODE DECK.CPP

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

//Deck class
Deck::Deck(){
    //constructor for Deck

    //list of suit
    char suits[] = {'C','S','D','H'};

    //list of ranks
    //how ranks work in the vector: according to the ASCII character set (which commonly use in C++). 
    // 1<2<3<4<5<6<7<8<9<10<J<Q<K 
    //the comparison operator follow the ASCII character order
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

    for (char suit : suits){
        for (char rank : ranks){
            //push the card in term rank:suit in the vector Card
            //push back() -> push the card at the end
            cards.push_back(Card(suit,rank));
        };
    };
};


//Card: returns a 'Card' object
//Deck::deal: allow the access to use the deal function in the Deck class
Card Deck::deal(){
    //retrieve the first card in the calss
    Card dealtCard = cards.front();

    //remove the first card from the deck
    cards.erase(cards.begin());

    //return the dealt card
    return dealtCard;
};

void Deck::display(){
    int countingline = 0;
    //counting line so it can divide into 4 different lines

    // cout<< "display went here:"<<endl;
    for (Card card : cards){
        //get each card from Card dislay
        card.display();
        countingline++; //increment the element until it get to 13 card to get into newline

        if (countingline == 13){
            countingline = 0; //reset the counitng
            cout << endl; // get to the new line
        }
    }
    cout<<endl; //new line
}

void Deck::shuffle(){
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));

    std::srand(static_cast <unsigned int>(std::time(nullptr)));

    //loop through the cards in reverse order
    for (int i = 51; i > 0; --i){
        //generate a random index 'j' between 0 and 'i'
        int j = std::rand()%(i+1);

        //swap the card at index 'i' with the card at index j
        Card temp = cards[i]; //create the temp Card object
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

