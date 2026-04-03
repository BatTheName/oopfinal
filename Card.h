#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;


class Card
{
private:
	int cardNumber;
	string cardType;

public:
	Card();
	Card(int cardNumber, string cardType);

	void setCardNumber(int newNumber);
	void setCardType(string newType);

	int getCardNumber() const;
	string getCardType() const;
};



#endif
