
#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

class Player
{
    public:
	   Hand hand;
	   int score {0};
       Player() = default;
       Player(Deck &deck, int N) : hand(deck, N) {}
};
  

#endif // PLAYER_H_
