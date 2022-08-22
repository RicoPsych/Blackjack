#pragma once
#include <iostream>
#include <string>
#include <stack>

#include "Suits.cpp"
#include "Card.h"
#include "Deck.h"

class Blackjack
{
private:
    Deck deck;
    deque<Card>player;
    int player_value;
    deque<Card>house;
    int house_value;
    bool stay;
public:
    Blackjack();
    void CreateBlackjackDeck();
    void Start();
    void Hit();
    void Stay();
    void DeckStatus();
    bool Check();
    void CountHouse();
    void CountPlayer();
    void PrintPlayer();
    void PrintHouse();
    ~Blackjack();

};

