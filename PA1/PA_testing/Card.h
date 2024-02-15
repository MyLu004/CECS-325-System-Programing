#ifndef CARD_H
#define CARD_H
#include<iostream>
using namespace std;

class Card
{
private: 
	char suit;
	char rank;
public:
	Card(char, char);
	void display() const;
	int compare(Card other) const;
};
#endif // CARD_H