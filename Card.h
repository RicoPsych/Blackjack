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
    Card();

    Card(int value, string sign, Suit suit);
    void SetCard(int value, string sign, Suit suit);
    int GetValue() ;
    Suit GetSuit() ;
    string GetSuitString();
    string GetSign() ;

    string GetCardInfo();
    ~Card() ;
};


