#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

string Hand::printHand(){
    //string handString = "Your Hand: [1] " + hand[0].printCard() + " [2] " + hand[1].printCard() + " [3] " + hand[2].printCard() + " [4] " + hand[3].printCard() + " [5] " + hand[4].printCard();
    string handString;
    int handSize = hand.size();
    for(int i = 0; i < handSize; ++i){
	    cout << "[" << i + 1 << "]" << hand[i].printCard() << " ";
    }
    return handString;
}

Card Hand::dealCard(int num){
    Card card = hand[num];
    hand.erase(hand.begin() + (num));
    return card;
}

int Hand::getHandSize(){
    int handSize = hand.size();
    return handSize;
}

Hand::Hand(Deck &deck, int N){
    for(int i = 0; i < N; i++){
    	hand.push_back(deck.drawCard());
    }
}
