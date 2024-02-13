#include <iostream>
#include "Deck.h"

using namespace std;

int main(){
    string player1, player2;

    //asking player input
    cout << "Enter the name for player 1: ";
    cin >> player1;

    cout << "Enter the name for player 2: ";
    cin >> player2;
    cout << "\n";

    //create Deck object
    Deck myDeck;
    cout<< "Original Deck: "<<endl;
    //call display function to display the deck card
    myDeck.display();

    cout <<endl;

    //then shuffle the card
    myDeck.shuffle();
    cout<< "Shuffle Deck: "<<endl;
    //call display function to display the deck card [display function from Deck class]
    myDeck.display();

    //int player1Win = 0, player2Win = 0, player1ties = 0, player2ties = 0, player1Lose = 0, playere2Lose = 0;

    //create the variable to hold the result for the end game
    int player1Win = 0, player1ties = 0, player1Lose = 0;
    int player2Win = 0, player2ties = 0, player2Lose = 0;

    //there are 26 game in total
    //i is for counting the amount of game
    for (int i = 0; i < 26; i++){

        cout <<endl; //create new line
        cout << "\nGame " << i+1 << ":\n";
        Card myCard1 = myDeck.deal(); //retrieve the card from the start
        Card myCard2 = myDeck.deal(); //retrieve the card from the start

        //display the card from player 1 [display function from Card class]
        cout << player1 << "=> ";
        myCard1.display();
        cout << "\n";

        //display the card from player 2 [display function from Card class]
        cout << player2 << "=> ";
        myCard2.display();
        cout << "\n";

        //get the integer result by going through the compare function from card.cpp
        int result = myCard1.compare(myCard2);

        //calculate the result base on the result_variable from the card.cpp
        if(result == 1){
            cout << player1 << "==> Winner";
            player1Win++;
            player2Lose++;
        }
        else if(result == -1){
            cout << player2 << "==> Winnter";
            player2Win++;
            player1Lose++;
        }
        else{
            cout<< "Tie Game"<<endl;
            player1ties++;
            player2ties++;
        }
    }

    //display the result in the end game
    cout << endl;
    cout << endl;
    cout<< "----- FINAL STATS ------"<<endl;
    cout<< "\t"<<player1 << " vs. "<< player2<< endl;
    cout<< "Wins:\t "<< player1Win <<"          "<< player2Win<<endl;
    cout<< "Loses:\t "<< player1Lose <<"          "<< player2Lose<<endl;
    cout<< "Ties:\t "<< player1ties <<"           "<< player2ties <<endl;

}