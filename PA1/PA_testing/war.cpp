#include<iostream>
#include "Deck.h"
#include "Card.h"
#include<string>
using namespace std;
int main()
{
	string firstPlayer, secondPlayer;
	Deck deck; 
	cout<<"Enter the name of the first player: ";
	cin>> firstPlayer;
	cout<<"Enter the name of the second player: ";
	cin>> secondPlayer; 
	cout<<endl;
	cout<<"Original Deck"<<endl;
	deck.display();
	srand(time(0));
}
	