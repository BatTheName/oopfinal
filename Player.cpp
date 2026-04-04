#include "Player.h"
#include <iostream>

Player::Player() : name("Unknown"), score(0) {}

Player::Player(const std::string& name) : name(name), score(0) {}

std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

bool Player::checkPair() const {
    for (size_t i = 0; i < hand.size(); i++) {
        for (size_t j = i + 1; j < hand.size(); j++) {
            if (hand[i].getCardNumber() == hand[j].getCardNumber()) {
                return true;
            }
        }
    }
    return false;
}

void Player::addPenaltyPoints(int points) {
    score += points;
}

// extra function for ASCII card
void Player::displayHand() {
    std::cout << "\n" << name << "'s Hand:\n\n";

    // Top
    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << " _____  ";
    }
    std::cout << std::endl;

    // Middle
    for (size_t i = 0; i < hand.size(); i++) {      
        if (hand[i].getCardType() == "Number") {
            std::cout << "|  " << hand[i].getCardNumber() << "  | ";
        }
        else if (hand[i].getCardType() == "Skip") {
            std::cout << "|     | "; // A skip card will only be displayed as a blank card
        }
        else if (hand[i].getCardType() == "Delete_Two") {
            int i = 0;
            while (i < 2 && hand.size() > 1) {
                hand.erase(hand.end() - 2); // This will remove the last 2 cards, the cards before the Delete Two card
                i++;
            }
        }
        else {
            std::cout << "| " << hand[i].getCardType()[0] << "  | ";
        }
    }
    std::cout << std::endl;

    // Bottom
    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << "|_____| ";
    }
    std::cout << std::endl;
}


void Player::resetHand() {
    hand.clear();
}