#include "DeckController.h"
#include "Card.h"
#include "Player.h"
#include <vector>
#include <iostream>

void gameRound(std::vector<Player> &players);
void checkForWinner(std::vector<Player> &players, std::vector<Card> &table);
void handleStandoff(std::vector<Player> &players, const std::vector<int> &winners, std::vector<Card> &table);

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
        Player thisplayer(name);
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
        gameRound(players);
    }

    std::cout << "Game over! Winner is: " << players[0].getName() << std::endl;

    return 0;
}

void gameRound(std::vector<Player> &players)
{
    std::vector<Card> table;

    for (int i = 0; i < players.size(); i++)
    {
        if (!players[i].hasCards())
            continue;

        Card playedCard = players[i].playCard();
        table.push_back(playedCard);

        players[i].displayName();
        std::cout << " played: " << playedCard.color << " " << playedCard.number << std::endl;
    }

    checkForWinner(players, table);
}

void checkForWinner(std::vector<Player> &players, std::vector<Card> &table)
{
    int highestNumber = -1;
    std::vector<int> winners;

    for (int i = 0; i < players.size(); i++)
    {
        if (!players[i].hasCards())
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

        handleStandoff(players, winners, table);
    }
}

void handleStandoff(std::vector<Player> &players, const std::vector<int> &winners, std::vector<Card> &table)
{
    for (int idx : winners)
    {
        if (players[idx].hasCards())
        {
            int count = std::min(3, players[idx].remainingCards() - 1);
            for (int i = 0; i < count; ++i)
            {
                table.push_back(players[idx].playCard());
            }

            if (players[idx].hasCards())
            {
                Card standoffCard = players[idx].playCard();
                table.push_back(standoffCard);
                std::cout << players[idx].getName() << " plays a standoff card: " << standoffCard.color << " " << standoffCard.number << std::endl;
            }
        }
    }
    checkForWinner(players, table);
}
