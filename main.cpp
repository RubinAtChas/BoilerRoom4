#include "DeckController.h"
#include "Card.h"
#include "player.h"
#include <iostream>

int main()
{
    DeckController Deck;
    Deck.generateDeck();
    Deck.printDeck();
    Deck.shuffleDeck();
    Deck.printDeck();

    int playersCount = 0;
    ;

    std::vector<Player> players;
    std::cout << "Hello and welcome to War game" << std::endl;
    std::cout << "How many are playing?" << std::endl;
    std::cin >> playersCount;
    for (int i = 0; i < playersCount; i++)
    {
        std::string name;
        std::cout << "Write your name" << std::endl;
        std::cin >> name;
        Player thisplayer(name);
        players.push_back(thisplayer);
    }
    int playerI = 0;
    for (int j = 0; j < 52; j++)
    {
        players.at(playerI).addCards(Deck.getDeck().at(j));
        playerI++;
        if (playerI >= playersCount)
        {
            playerI = 0;
        }
    }
    for (Player thisPlayer : players)
    {
        std::cout << "Player: ";
        thisPlayer.displayName();
        thisPlayer.displayHand();
    }

    return 0;
}
