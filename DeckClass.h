#ifndef DECKCLASS_H
#define DECKCLASS_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
using namespace std;


class Deck
{
private:
    vector<Card> cards;
    vector<Card> burnedCards;
    int deckSize;

public:
    Deck();

    void createDeck();
    void shuffleDeck();
    void burnCards(int number);

    Card drawCard();

    bool isEmpty();
    int getDeckSize();

    void resetDeck();
    void displayDeck();
};

#endif
