#include "DeckController.h"
#include "Card.h"
#include "Player.h"
#include <vector>
#include <iostream>

void gameRound(std::vector<Player> &players, std::vector<int> playerIds);
void checkForWinner(std::vector<Player> &players, std::vector<Card> &table);
void handleStandoff(std::vector<Player> &players, std::vector<int> winners, std::vector<Card> &table);

int main()
{
    DeckController Deck;
    Deck.generateDeck();
    Deck.printDeck();
    Deck.shuffleDeck();
    Deck.printDeck();

    int playersCount = 0;

    std::vector<Player> players;
    std::cout << "Hello and welcome to War game" << std::endl;
    std::cout << "How many are playing?" << std::endl;
    std::cin >> playersCount;

    for (int i = 0; i < playersCount; i++)
    {
        std::string name;
        std::cout << "Write your name" << std::endl;
        std::cin >> name;
        Player thisplayer(name, i);
        players.push_back(thisplayer);
    }

    int playerI = 0;
    for (int j = 0; j < Deck.getDeck().size(); j++)
    {
        players.at(playerI).addCard(Deck.getDeck().at(j));
        playerI++;
        if (playerI >= playersCount)
        {
            playerI = 0;
        }
    }

    for (Player &thisPlayer : players)
    {
        std::cout << "Player: ";
        thisPlayer.displayName();
        thisPlayer.displayHand();
    }

    while (players.size() > 1)
    {
        std::vector<int> playerIds;
        for (Player player : players)
        {
            playerIds.push_back(player.getId());
        }
        std::vector<Card> table;
        gameRound();
    }

    std::cout << "Game over! Winner is: " << players[0].getName() << std::endl;

    return 0;
}
