#include<iostream>
#include "Card.h"
using namespace std;

Card::Card(char s, char r)
{
	suit = s;
	rank = r;
}

void Card::display() const
{
	if(rank=='T')
	{
		cout<<"10"<< suit<< " ";
	}
	else 
	{
		cout<<rank<<suit << " ";
	}
}


int Card::compare(Card otherCard)const
{
	char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	int rankVal = 0, otherRankVal = 0;
	for (int i =0; i<13; i++)
	{
		if (rank == ranks[i])
		{
			rankVal = i;
		}
		if (otherCard.rank == ranks[i]){
			otherRankVal = i;
		}
	}

	if (rankVal== otherRankVal)
	{
		return 0;
	}
	else if (rankVal > otherRankVal)
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}