#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

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
    }
};