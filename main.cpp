#include "DeckController.h"
#include "Card.h"
#include "player.h"
#include "createGame.h"
#include <vector>
#include <iostream>

void ViewAllPlayers(std::vector<Player> players)
{
    for (Player thisPlayer : players)
    {
        std::cout << "Player: ";
        thisPlayer.displayName();
        thisPlayer.displayHand();
    }
}
int main()
{
    std::vector<Player> players;
    int choice = 0;
    do
    {
        createGame createGame;
        players = createGame.createPlayers();
        players = createGame.createPlayersHand();
        ViewAllPlayers(players);
        std::cout << "You wanna play another?" << std::endl;
        std::cin >> choice;
    } while (choice == 1);

    return 0;
}
