#ifndef DECK_H
#define DECK_H
#include "Card.h"
using namespace std;
#include<vector>

class Deck 
{
private:
	vector<Card> Inventory;
public: 
	Deck();
	Card deal();
	void display();
	void shuffle();
};
#endif // DECK_H