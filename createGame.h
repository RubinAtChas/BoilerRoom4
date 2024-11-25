#ifndef createGame_H
#define createGame_H
#include "player.h"
#include "DeckController.h"
#include <stdexcept>
class createGame
{
private:
    DeckController Deck;
    std::vector<Player> players;
    int playerCount;

public:
    void erasePlayer();
    createGame();
    std::vector<Player> createPlayersHand();
    std::vector<Player> createPlayers();
};
createGame::createGame()
{
    Deck.generateDeck();
    Deck.shuffleDeck();
    std::cout << "Hello and welcome to War game" << std::endl;
}
std::vector<Player> createGame::createPlayersHand()
{
    int playerI = 0;
    for (int j = 0; j < Deck.getDeck().size(); j++)
    {
        players.at(playerI).addCards(Deck.getDeck().at(j));
        playerI++;
        if (playerI >= playerCount)
        {
            playerI = 0;
        }
    }
    return players;
}
std::vector<Player> createGame::createPlayers()
{
    do
    {
        try
        {
            std::cout << "How many are playing?" << std::endl;
            std::cin >> playerCount;
            if (std::cin.fail())
            {
                throw "player count most be between 2 and 51!";
            }
            else if (playerCount < 2)
            {
                throw "player count was less then 2!";
            }
            else if (playerCount > 51)
            {
                throw "player count was more then 51!";
            }
        }
        catch (const char *e)
        {
            std::cerr << "Exception caught: " << e << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (playerCount < 1 || playerCount > 51);

    for (int i = 0; i < playerCount; i++)
    {
        std::string name;
        std::cout << "Write your name" << std::endl;
        std::cin >> name;
        Player thisplayer(name);
        players.push_back(thisplayer);
    }
    return players;
}


void createGame::erasePlayer()
{
    for (int i = 0; i < players.size();)
    {
        if (players[i].returnHand().empty())
        {
            
            std::cout << "The player: " << players[i].getName() << " has been eliminated" << std::endl;
            players.erase(players.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

#endif