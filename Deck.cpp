#include "DeckClass.h"
#include <algorithm>
#include <ctime>

Deck::Deck()
{
    srand(time(NULL));
    createDeck();
    shuffleDeck();
    burnCards(5);
    deckSize = cards.size();
}

void Deck::createDeck()
{
    cards.clear();

    for (int rank = 1; rank <= 10; rank++)
    {
        for (int i = 1; i <= rank; i++)
        {
            Card card(rank, "Number");
            cards.push_back(card);
        }
    }
    Card cardEvent1(0, "Skip");
    cards.push_back(cardEvent1);
    Card cardEvent2(0, "Delete_Two");
    cards.push_back(cardEvent2);
    deckSize = cards.size();
}

void Deck::shuffleDeck()
{
    for (int i = 0; i < cards.size(); i++)
    {
        int r = rand() % cards.size();
        swap(cards[i], cards[r]);
    }
}

void Deck::burnCards(int number)
{
    for (int i = 0; i < number; i++)
    {
        if (!cards.empty())
        {
            burnedCards.push_back(cards.back());
            cards.pop_back();
        }
    }

    deckSize = cards.size();
}

Card Deck::drawCard()
{
    if (cards.empty())
    {
        cout << "Deck is empty!" << endl;
        return Card();
    }

    Card card = cards.back();
    cards.pop_back();

    deckSize = cards.size();

    return card;
}

bool Deck::isEmpty()
{
    return cards.empty();
}

int Deck::getDeckSize()
{
    return deckSize;
}

void Deck::resetDeck()
{
    cards.clear();
    burnedCards.clear();

    createDeck();
    shuffleDeck();
    burnCards(5);

    deckSize = cards.size();
}

void Deck::displayDeck()
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i].getCardNumber() << endl;
    }
}