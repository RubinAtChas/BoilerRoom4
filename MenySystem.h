#include <iostream>
void displayRules()
{
    std::cout << "The objective of the game is to win all of the cards." << std::endl
              << "The deck is divided evenly among the players, giving each a down stack." << std::endl
              << "Each player reveals the top card of their deck." << std::endl
              << "The player with the higher card takes both of the cards played and moves them to their stack." << std::endl
              << "Aces are high." << std::endl
              << "If the two cards played are of equal value, then there is a war." << std::endl
              << "Both players place the next 3 cards from their pile face down and then another card face - up." << std::endl
              << "The owner of the higher face - up card wins the war and adds all the cards on the table to the bottom of their deck." << std::endl
              << "If the face - up cards are again equal then the battle repeats with another set of face - down / up cards." << std::endl
              << "This repeats until one player's face-up card is higher than their opponent" << std::endl
              << "The Game ends when one player has all the cards in his deck!" << std::endl;
}
bool startMeny()
{
    std::cout << "Welcome to card game WAR" << std::endl;
    int choice = 0;
    bool isGamerunning = false;
    do
    {
        std::cout << "1. How to play" << std::endl
                  << "2. Start Game" << std::endl
                  << "3. Exit Game" << std::endl;
        std::cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
                displayRules();
                break;
            case 2:
                isGamerunning = true;
                break;
            case 3:
                std::cout << "Exiting Game...";
                isGamerunning = false;
                break;
            default:
                throw std::runtime_error("Chose between 1 and 3!");
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << " Your input was " << choice << '\n';
        }

    } while (choice != 3 && choice != 2);
    return isGamerunning;
};
