#pragma once
#include <stack>
#include "Card.h"
using namespace std;

class Deck {
private:
    int amount;
    deque<Card> deck;
public:
    Deck() ;
    Deck(int amount);

    void Shuffle();
    int GetAmount();
    int GetSize() ;
    void AddCard(Card card) ;
    Card GetCard();
    void ClearDeck();
    ~Deck();
};