#include "DeckController.h"
#include "Card.h"
#include "player.h"
#include "createGame.h"
#include <vector>
#include <iostream>
#include "MenySystem.h"
#include "GameRound.h"

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
    createGame createGame;
    players = createGame.createPlayers();
    players = createGame.createPlayersHand();
    ViewAllPlayers(players);
    while (players.size() > 1)
    {
        std::vector<int> playerIds;
        for (Player player : players)
        {
            playerIds.push_back(player.getId());
        }
        std::vector<Card> table;
        GameRound currentRound(players, playerIds, table);
        currentRound.gameRound();
        players = currentRound.getPlayers();
    }

    std::cout << "Game over! Winner is: " << players[0].getName() << std::endl;

    return 0;
}
