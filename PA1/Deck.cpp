#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

Deck::Deck(){
    char suits[] = {'C','S','D','H'};
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

    for (char suit : suits){
        for (char rank : ranks){
            cards.push_back(Card(suit,rank));
        };
    };
};

Card Deck::deal(){
    Card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
};

void Deck::display(){
    int countingline = 0;
    // cout<< "display went here:"<<endl;
    for (Card card : cards){
        
        card.display();
        countingline++;

        if (countingline == 13){
            countingline = 0;
            cout << endl;
        }
    }
    cout<<endl;
}

void Deck::shuffle(){
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));

    std::srand(static_cast <unsigned int>(std::time(nullptr)));

    for (int i = 51; i > 0; --i){
        int j = std::rand()%(i+1);

        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

