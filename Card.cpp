#include "Card.h"
#include <iostream>

using namespace std;

string Card::printCard(){
    string cardString;

    if(color == 0){
        cardString = "purple:" + to_string(rank);
    }
    else if(color == 1){
        cardString = "orange:" + to_string(rank);
    }
    else{
        cardString = "tiger:" + to_string(rank);
    }

    return cardString;
}

int Card::getRank(){
    return rank;
}

Card::Color Card::getColor(){
    return color;
}

int Card::getValue(){
    return value;
}

Card::Card(int rank, Color color){
    this->rank = rank;
    this->color = color;
    if(color == purple){
        value = rank;
    }
    else if(color == orange || color == tiger){
        value = rank * 2;
    }    
}

