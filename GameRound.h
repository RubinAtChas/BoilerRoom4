#include <iostream>
#include <vector>
#include <list>
#include "Card.h"
#include "player.h"

class GameRound
{
private:
    std::vector<Card> table;
    std::vector<int> playerIds;
    std::vector<Player> players;

public:
    GameRound(std::vector<Player> players, std::vector<int> playerIds, std::vector<Card> table) : players(players), playerIds(playerIds), table(table) {}
    void gameRound();
    void checkForWinner();
    void handleStandoff();
};

void GameRound::gameRound()
{

    for (int i = 0; i < players.size(); i++)
    {
        if (std::find(playerIds.begin(), playerIds.end(), players[i].getId()) == playerIds.end())
            continue;

        if (!players[i].hasCards())
            continue;

        Card playedCard = players[i].playCard();
        table.push_back(playedCard);

        players[i].displayName();
        std::cout << " played: " << playedCard.color << " " << playedCard.number << std::endl;
        checkForWinner();
    }
}

void GameRound::checkForWinner()
{
    int highestNumber = -1;
    std::vector<int> winners;

    for (int i = 0; i < playerIds.size(); i++)
    {
        if (!players[i].hasCards()) // ????
            continue;

        if (table[i].number > highestNumber)
        {
            highestNumber = table[i].number;
            winners.clear();
            winners.push_back(i);
        }
        else if (table[i].number == highestNumber)
        {
            winners.push_back(i);
        }
    }

    if (winners.size() == 1)
    {
        int winnerIndex = winners[0];
        std::cout << players[winnerIndex].getName() << " wins this round!" << std::endl;

        for (const auto &card : table)
        {
            players[winnerIndex].addCard(card);
        }
    }
    else
    {
        std::cout << "It's a tie between:";
        for (int idx : winners)
        {
            std::cout << " " << players[idx].getName();
        }
        std::cout << std::endl;

        // std::vector<Player> standoffPlayers;
        // for (int i = 0; i < winners.size(); i++)
        // {
        //     standoffPlayers.push_back(players[i]);
        // }

        handleStandoff();
    }
}

void GameRound::handleStandoff()
{
    for (int i = 0; i < winners.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (players[winners[i]].hasCards())
            {
                Card standoffCard = players[winners[i]].playCard();
                table.push_back(standoffCard);
                std::cout << players[winners[i]].getName() << " plays a standoff card: " << standoffCard.color << " " << standoffCard.number << std::endl;
            }
        }
    }
    gameRound(); // OBS -- Måste göras om för att kolla vem som vinner standoffen
}
