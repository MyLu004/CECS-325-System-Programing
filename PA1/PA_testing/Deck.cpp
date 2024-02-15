#include<iostream>
using namespace std;
#include "Deck.h"
#include "Card.h"
#include <cstdlib>
#include <ctime>
Deck::Deck()
{	
	char suit [] = {'C', 'S', 'D', 'H'}; // Clubs, Diamonds, Hearts, Spades
	char rank [] = {'A','2','3','4','5','6','7','8','9','T', 'J', 'Q', 'K'}; 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Inventory.push_back(Card(suit[i],rank[j])); 
		}	
	}
}
Card Deck::deal()
{
	Card dealt = Inventory.back();
	Inventory.pop_back();
	return dealt;
}

void Deck::display()
{
	// for(int i=0; i<Inventory.size(); i++)
	// { 
	// 	Inventory[i].display();
	// 	if(i<Inventory.size()-1) 
	// 	{
	// 		cout<<", ";		
	// 	}
	// }
    int coutingLine = 0;
    for (Card myInvent : Inventory)
	{
		myInvent.display();
        coutingLine++;

        if (coutingLine == 13){
            coutingLine = 0;
            cout << endl;
        }
	}
	cout<<endl;  

}
void Deck::shuffle() // Fisher-Yates Algorithm...
{
	int sizeOfDeck = Inventory.size();
	for (int i = sizeOfDeck-1 ; i > 0; i--)
	{
		int j = rand() % (i+1);
		swap(Inventory[i], Inventory[j]);
	}
}