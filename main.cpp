#include "DeckController.h"
#include "Card.h"
#include "player.h"
#include "createGame.h"
#include <vector>
#include <iostream>
#include "MenySystem.h"

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
    bool continueGame = false;
    std::vector<Player> players;
    continueGame = startMeny();
    while (continueGame == true)
    {
        createGame createGame;
        players = createGame.createPlayers();
        players = createGame.createPlayersHand();
        ViewAllPlayers(players);
    }

    return 0;
}
