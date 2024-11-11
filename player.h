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
std::vector<Card>hand;
public:
Player(std::string name, std::vector<Card>hand)
: name(name),hand(hand){}

void displayName()
{
    std::cout << name << std::endl;

}
Card playCard()
{
    Card lastCard = hand.back();
    hand.pop_back();
    return lastCard;
}
void addCards(std::vector<Card>playedCards)
{
    hand.insert(hand.begin(),playedCards.begin(),playedCards.end());
}

};

#endif