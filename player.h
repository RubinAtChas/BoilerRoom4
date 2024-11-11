#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"

class Player
{
public:
std::string name;
std::vector<Card>hand;
};

#endif