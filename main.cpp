#include "DeckController.h"

int main()
{
    DeckController Deck;
    Deck.generateDeck();
    Deck.printDeck();
    Deck.randommizeDeck();
    Deck.printDeck();
    return 0;
}