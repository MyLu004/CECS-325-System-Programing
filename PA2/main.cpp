#include <iostream>
// #include <vector>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Card{ // will creates Cards
    private:
        char mySuit;
        char myRank;
    public:
        //default Card Constructions : needed for array in Deck Class
        Card(){
            mySuit;
            myRank;
        };

        //Card Constructions : constructor to create a card, seeting the suit and rank
        Card(char suit, char rank){
            mySuit = suit;
            myRank = rank;
        };
        
    //display function : display the card
    void display(){
        if(myRank == 'T'){
            cout<<"10"<< mySuit<<" ";
        }
        else{
            cout<<myRank<<mySuit<<" ";
        }
    };

    //return 1 for win, 0 for tie, -1 for lose
    int ComparingmyCard(Card other){
        // cout<<"my rank: "<<myRank<<endl;
        // cout<<"other rank: "<<other.myRank<<endl;

        char listComparingRanks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
        int myRankval, otherRankval = 0;

        for(int i = 1; i<=13;i++){
            if(myRank == listComparingRanks[i]){
                myRankval = i;
            }
            if(other.myRank == listComparingRanks[i]){
                otherRankval = i;
            }
        };  
        
        //compare integer
        if(myRankval > otherRankval){
            return 1;
        }
        if(myRankval < otherRankval){
            return -1;
        }
        else{
            return 0;
        }  
    };
};

class Deck //will create the deck of 52 cards
{
    private:
        //initial the vector for Card
        Card myCard[52];

    public:
        //deck construction : will creates a deck of 52 cards
        int turn = 0;
        Deck()
        {   
            int total = 0;
            char suit[] = {'C','S','D','H'};
            char rank[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

            for (int i = 0; i < size(suit);i++)
            {
                // cout<<"my suit: "<< i<<": "<<suit[i]<<endl;
                for (int j = 0; j < size(rank); j++)
                {
                    // myCard.push_back(Card(suit[i],rank[j]));

                    myCard[total] = Card(suit[i],rank[j]);
                    total++;
                };
            };

        }; 

    //return the Card object 
    //Deck:deal : using the function in Deck class
    Card deal()
    {
        if(turn > 52){
            throw "DECK EMPTY";
        };
        return myCard[turn++];
    };
    
    //DISPLAY Function
    void display()
    {
        int countingline = 0;

        for (Card card: myCard)
        {
            card.display();
            countingline++;

            if (countingline == 13)
            {
                countingline = 0;
                cout<<endl;
            };
        };
    }
    //SHUFFLE function
    void shuffle(){
        // srand(time(0));
        srand(time(0));
        for (int i = 51; i>0; --i){
            int j = rand()%(i+1);

            //swapping card
            swap(myCard[i],myCard[j]);
        };
    };
    //BOOL isEmpty
    bool isEmpty(){
        return turn == 52;   
    }
};

int main(){
    string player1,player2;

    //TODO: set the game input later for user
    int game;

    cout<<"Enter name player1: ";
    cin >> player1;

    cout<<"Enter name player2: ";
    cin >> player2;

    cout<<"How many game will they play?";
    cin >> game;

    //create Deck object
    Deck myDeck;
    
    cout<<endl<<"Original Deck: "<<endl;
    myDeck.display();

    cout<<endl<<"Shuffle Deck: "<<endl;
    myDeck.shuffle();
    myDeck.display();

    // //variable for score
    int player1Win = 0, player1ties = 0, player1Lose = 0;
    int player2Win = 0, player2ties = 0, player2Lose = 0;

    try{
        for (int i = 0; i < game; i++){
            if(myDeck.isEmpty()){
                throw "Error - Deck is Empty";
            };

            cout<<endl;
            cout<<"\nGame"<< i+1<<endl;
            Card player1Card = myDeck.deal();
            Card player2Card = myDeck.deal();

            //display player card
            cout<<player1<< "==>";
            player1Card.display();
            cout<<endl;

            cout<<player2<< "==>";
            player2Card.display();
            cout<<endl;

            int result = player1Card.ComparingmyCard(player2Card);

            //calculate the result base on the result_variable from the card.cpp
            if(result == 1){
                cout << player1 << "==> Winner";
                player1Win++;
                player2Lose++;
            }
            else if(result == -1){
                cout << player2 << "==> Winner";
                player2Win++;
                player1Lose++;
            }
            else{
                cout<< "Tie Game"<<endl;
                player1ties++;
                player2ties++;
            }  
      };
    }

    catch (const char* errormsg){
        cout<<"\n\n";
        cout<< errormsg <<endl;
    };
    
    cout << "\n\n";
    cout<< "----- FINAL STATS ------"<<endl;
    cout<< "\t"<<player1 << " vs. "<< player2<< endl;
    cout<< "Wins:\t "<< player1Win <<"          "<< player2Win<<endl;
    cout<< "Loses:\t "<< player1Lose <<"          "<< player2Lose<<endl;
    cout<< "Ties:\t "<< player1ties <<"           "<< player2ties <<endl;

    // cout<<endl<<"IT END HERE" <<endl;
    return 0;
};
