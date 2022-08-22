
#include "Deck.h"
using namespace std;


    Deck::Deck() {
        this->amount = 1;
    };
    Deck::Deck(int amount) {
        this->amount = amount;
    }

    void Deck::Shuffle() {
        for (int i = 0; i < deck.size() * 3; i++) {
            Card card = deck.back();
            deck.pop_back();


            int random = rand() % deck.size();
            deque<Card>::iterator iterator = deck.begin();
            iterator += random;

            deck.insert(iterator, card);
        }
    }
    int Deck::GetAmount() { return amount; }
    int Deck::GetSize() { return deck.size(); };
    void Deck::AddCard(Card card) {
        deck.push_back(card);
    }
    Card Deck::GetCard() {
        Card card = deck.back();
        deck.pop_back();
        return card;
    }
    void Deck::ClearDeck() {
        deck.clear();
    }
    Deck::~Deck() { };