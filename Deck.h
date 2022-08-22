#pragma once
#include <stack>
#include "Card.h"
using namespace std;

class Deck {
private:
    int amount;
    deque<Card> deck;
public:
    //Create 1 deck;
    Deck();
    //Create set amount of decks
    Deck(int amount);
    //Shuffle deck
    void Shuffle();
    //Get amount of decks
    int GetAmount();
    //Get size
    int GetSize();
    //Add cards to deck
    void AddCard(Card card);
    //Get top card
    Card GetCard();
    //Empty deck
    void ClearDeck();
    ~Deck();
};