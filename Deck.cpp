/********************************************************************
FITS1201 – Object-Oriented Programming
UNJI GAMES Assignment – Version 1
Academic Integrity Declaration
Student Name: FAIZ PERWIZ__________________
Student ID: 251103130126__________________
Submission Date: 04-04-2026_________________
I declare that:
1. This assignment is entirely my own original work.
2. I have not copied code from other students, websites, AI tools,
 or any external sources without proper acknowledgment.
3. I have not used AI tools (such as ChatGPT, GitHub Copilot, or similar)
 to generate any part of this assignment solution.
4. I have only used AI tools, if any, for learning purposes such as
 understanding concepts, syntax, or debugging, and not for generating
code.
5. Any concepts, syntax, or techniques not taught in this course have been
 properly acknowledged with citations in the comments of my code.
6. I understand that failure to comply with these requirements may result
 in academic misconduct proceedings and penalties, including a mark of
 zero for this assignment.
Student Signature: <Faiz Perwiz>
********************************************************************/
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
