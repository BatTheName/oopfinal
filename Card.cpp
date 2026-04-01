#include "Card.h"

Card::Card()
{
	cardNumber = 0;
	cardType = "NULL";
}

Card::Card(int number, string type)
{
	cardNumber = number;
	cardType = type;
}

void Card::setCardNumber(int newNumber)
{
	cardNumber = newNumber;
}

void Card::setCardType(string newType)
{
	cardType = newType;
}

int Card::getCardNumber()
{
	return cardNumber;
}

string Card::getCardType()
{
	return cardType;
}
