#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include <algorithm>
#include <random>

class DeckController
{
private:
    std::vector<Card> Deck;

public:
    void generateDeck()
    {
        std::vector<std::string> colorcard = {"Hearts",
                                              "Club",
                                              "Dimonds",
                                              "Spade"};
        std::vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        for (std::string thisColor : colorcard)
        {
            for (int thisCardNum : number)
            {
                Card card;
                card.color = thisColor;
                card.number = thisCardNum;
                Deck.push_back(card);
            }
        }
    }
    void shuffleDeck()
    {
        std::random_device rd;  // Frö för att skapa en bra initial seed
        std::mt19937 rng(rd()); // Mersenne Twister slumpmotor med frö från random_device

        // Blanda kortleken
        std::shuffle(begin(Deck), end(Deck), rng);
    }
    void printDeck()
    {
        int index = 0;
        for (Card thisCard : Deck)
        {
            std::cout << "I: " << index << " Suit: " << thisCard.color << " Number: " << thisCard.number << std::endl;
            index++;
        }
    }
    std::vector<Card> getDeck()
    {
        return Deck;
    }
};