#include "DeckController.h"
#include "Card.h"
#include "player.h"
#include <vector>
#include <iostream>

void gameRound(std::vector<Player> &players);
void checkForWinner(std::vector<Player> &players, std::vector<Card> cards);
void handleStandoff(std::vector<Player> &players, const std::vector<int> &winners, std::vector<Card> &table);

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
    for (int j = 0; j < Deck.getDeck().size(); j++)
    {
        players.at(playerI).addCard(Deck.getDeck().at(j));
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

    gameRound(players);

    return 0;
}

void gameRound(std::vector<Player> &players)
{
    std::vector<Card> cards(players.size());

    for (int i = 0; i < players.size(); i++)
    {
        if (!players[i].hasCards())
            continue;

        cards[i] = players[i].playCard();
        players[i].displayName();
        std::cout << cards[i].color << cards[i].number << std::endl;
    }
    checkForWinner(players, cards);
}

void checkForWinner(std::vector<Player> &players, std::vector<Card> cards)
{
    int highestNumber = -1;
    std::vector<int> winners;

    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].number > highestNumber)
        {
            highestNumber = cards[i].number;
            winners.clear();
            winners.push_back(i);
        }
        else if (cards[i].number == highestNumber)
        {
            winners.push_back(i);
        }
    }

    if (winners.size() == 1)
    {
        int winnerIndex = winners[0];
        std::cout << players[winnerIndex].getName() << " wins this round!" << std::endl;

        for (const auto &card : cards)
        {
            players[winnerIndex].addCard(card);
        }
    }
    else
    {
        std::cout << "Its a tie between:";
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
                table.push_back(players[idx].playCard());
                std::cout << players[idx].getName() << " lägger ett standoffkort." << std::endl;
            }
        }
    }
}
