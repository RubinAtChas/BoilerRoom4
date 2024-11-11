#include "DeckController.h"

int main()
{
    DeckController Deck;
    Deck.generateDeck();
    Deck.printDeck();
    Deck.shuffleDeck();
    Deck.printDeck();
    return 0;
}