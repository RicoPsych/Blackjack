#pragma once
#include <string>
#include "Suits.cpp"
using namespace std;

class Card {
private:
    int value;
    string sign;
    Suit suit;

public:
    //Empty card
    Card();
    //Create card
    Card(int value, string sign, Suit suit);
    //Set card variables
    void SetCard(int value, string sign, Suit suit);
    //Get value of card
    int GetValue();
    //Get suit of card
    Suit GetSuit();
    //Get suit of card as string
    string GetSuitString();
    //Get sign of card
    string GetSign() ;
    //Get sign and suit of card
    string GetCardInfo();
    ~Card() ;
};


