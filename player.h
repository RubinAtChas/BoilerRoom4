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

    std::string& getName()
    {
        return name;
    }
    Card playCard()
    {
        Card lastCard = hand.back();
        hand.pop_back();
        return lastCard;
    }
    void addCards(Card newCard)
    {
        hand.push_back(newCard);
    }
    void displayHand()
    {
        for (Card thisCard : hand)
        {
            std::cout << "Suit: " << thisCard.color << " Number: " << thisCard.number << std::endl;
        }
    }
    std::vector<Card> returnHand()
    {
        return hand;
    }
};


#endif