#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "Card.h"

class Player
{
private:
    std::string name;
    std::vector<Card> hand;

public:
    Player(std::string name)
        : name(name) {}

    void displayName()
    {
        std::cout << name << std::endl;
    }

    std::string getName()
    {
        return name;
    }

    Card playCard()
    {
        Card lastCard = hand.back();
        hand.pop_back();
        return lastCard;
    }

    void addCard(Card newCard)
    {
        hand.insert(hand.begin(), newCard);
    }

    int remainingCards() const
    {
        return hand.size();
    }

    void displayHand()
    {
        for (Card thisCard : hand)
        {
            std::cout << "Suit: " << thisCard.color << " Number: " << thisCard.number << std::endl;
        }
    }

    bool hasCards()
    {
        return !hand.empty();
    }
};

#endif