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
    //Create deck for blackjack
    void CreateBlackjackDeck();
    //Start a round
    void Start();
    //Hit player action
    void Hit();
    //Stay player action
    void Stay();
    //Check amount of cards in deck and reshuffle if needed.
    void DeckStatus();
    //Check game state
    bool Check();
    //Count value of House cards
    void CountHouse();
    //Count value of Player cards
    void CountPlayer();
    //Print Player cards
    void PrintPlayer();
    //Print House cards
    void PrintHouse();
    ~Blackjack();

};

