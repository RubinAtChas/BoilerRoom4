#include "DeckController.h"
#include "player.h"

int main()
{  
    DeckController Deck;
    Deck.generateDeck();
    Deck.printDeck();
    Deck.shuffleDeck();
    Deck.printDeck();
    
    int playersCount;
    std::vector<Player> players;
    std::cout << "Hello and welcome to War game" << std::endl;
    std::cout << "How many are playing?" << std::endl;
    std::cin >> playersCount;
    int handCount = 52 / playersCount;
    for (int i = 0; i < playersCount; i++)
    {
        
        std::string name;
        std::cout << "Write your name" << std::endl;
        std::cin >> name;
        std::vector<Card> playersCards;
        std::vector<Card> deck = Deck.getDeck();
        players.push_back(Player(name, playersCards.insert(playersCards.begin(),deck.begin(),playersCount -1)))
    }
    

   
   
    return 0;
}
