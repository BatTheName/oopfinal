#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player {
private:
    std::string name;
    int score;
    std::vector<Card> hand;

public:
    Player();
    Player(const std::string& name);

    std::string getName() const;
    int getScore() const;

    void addCard(const Card& card);
    const std::vector<Card>& getHand() const;

    bool checkPair() const;

    void addPenaltyPoints(int points);

    void displayHand();

    void resetHand();
};

#endif