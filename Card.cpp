
#include "Card.h"
using namespace std;


    Card::Card() {
        this->value = 0;
        this->sign = "";
        this->suit = Hearts;
    }

    Card::Card(int value, string sign, Suit suit) {
        this->value = value;
        this->sign = sign;
        this->suit = suit;
    };

    void Card::SetCard(int value, string sign, Suit suit) {
        this->value = value;
        this->sign = sign;
        this->suit = suit;
    }
    int Card::GetValue() { return value; };
    Suit Card::GetSuit() { return suit; };
    string Card::GetSuitString() {
        switch (this->suit) {
        case Hearts:
            return "Hearts";
        case Diamonds:
            return "Diamonds";
        case Clubs:
            return "Clubs";
        case Spades:
            return "Spades";
        default:
            return "Joker";
        }
    };
    string Card::GetSign() { return sign; };

    string Card::GetCardInfo() {
        return this->GetSign() + " " + this->GetSuitString();
    }
    Card::~Card() {};