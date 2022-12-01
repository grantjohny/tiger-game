#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

void Deck::shuffle(){
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard(){
    Card card = deck.back();
    deck.pop_back();
    return card;
}

int Deck::getDeckSize(){
    int deckSize = deck.size();
    return deckSize;
}

Deck::Deck(){
    vector<Card> deckOfCards = deck;

    //Adds 10 purple cards to the deck
    for(int i = 1; i <= 10; i++){
        deck.push_back(Card(i, Card::purple));
    }

    //Adds 10 orange cards to the deck
    for(int i = 1; i <= 10; i++){
        deck.push_back(Card(i, Card::orange));    
    }
    
    //Adds a single tiger card with rank 10, this card ends the game
    deck.push_back(Card(10, Card::tiger));
}



