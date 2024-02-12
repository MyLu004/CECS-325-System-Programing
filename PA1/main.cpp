#include <iostream>
#include "Deck.h"

using namespace std;

int main(){
    string player1, player2;

    cout << "Enter the name for player 1: ";
    cin >> player1;

    cout << "Enter the name for player 2: ";
    cin >> player2;
    cout << "\n";

    Deck myDeck;
    cout<< "Original Deck: "<<endl;
    myDeck.display();

    cout <<endl;

    myDeck.shuffle();
    cout<< "Shuffle Deck: "<<endl;
    myDeck.display();

    int player1Win = 0, player2Win = 0, player1ties = 0, player2ties = 0, player1Lose = 0, playere2Lose = 0;
    // int player1Win = 0, player1ties = 0, player1Lose = 0;
    // int player2Win = 0, player2ties = 0, player2Lose = 0;

    for (int i = 0; i < 26; i++){

        cout <<endl;
        cout << "\nGame " << i+1 << ":\n";
        Card myCard1 = myDeck.deal();
        Card myCard2 = myDeck.deal();

        cout << player1 << "=> ";
        myCard1.display();
        cout << "\n";

        cout << player2 << "=> ";
        myCard2.display();
        cout << "\n";

        int result = myCard1.compare(myCard2);

        if(result == 1){
            cout << player1 << "==> Winner";
            player1Win++;
            playere2Lose++;
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
    cout << endl;
    cout << endl;
    cout<< "----- FINAL STATS ------"<<endl;
    cout<< "\t"<<player1 << " vs. "<< player2<< endl;
    cout<< "Wins:\t "<< player1Win <<"          "<< player2Win<<endl;
    cout<< "Loses:\t "<< player1Lose <<"          "<< playere2Lose<<endl;
    cout<< "Ties:\t "<< player1ties <<"           "<< player2ties <<endl;

}