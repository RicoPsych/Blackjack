#include <windows.h>
#include <iostream>
#include <string>
#include <stack>

#include "Suits.cpp"
#include "Card.h"
#include "Deck.h"

using namespace std;

class BlackJack
{
private:
    Deck deck;
    deque<Card>player;
    int player_value;
    deque<Card>house;
    int house_value;
    bool stay;
public:
    BlackJack() {
        deck = Deck(1);
        CreateBlackjackDeck();
        stay = false;
    };
    void CreateBlackjackDeck() {
        for (int ii = 0; ii < deck.GetAmount(); ii++) {

            for (int n = Hearts; n <= Spades; n++)
                for (int i = 1; i <= 13; i++) {
                    switch (i) {
                    case 1:
                        deck.AddCard(Card(11, "Ace", static_cast<Suit>(n)));
                        break;
                    case 11:
                        deck.AddCard(Card(10, "Jack", static_cast<Suit>(n)));
                        break;
                    case 12:
                        deck.AddCard(Card(10, "Queen", static_cast<Suit>(n)));
                        break;
                    case 13:
                        deck.AddCard(Card(10, "King", static_cast<Suit>(n)));
                        break;
                    default:
                        deck.AddCard(Card(i, to_string(i), static_cast<Suit>(n)));
                    }
                }
        }
        deck.Shuffle();
    }
    void Start() {
        house.clear();
        player.clear();
        stay = false;
        house.push_back(deck.GetCard());
        house.push_back(deck.GetCard());
        
        player.push_back(deck.GetCard());
        player.push_back(deck.GetCard());

        PrintHouse();
        PrintPlayer();
    };

    void Hit() {
        player.push_back(deck.GetCard());

        PrintPlayer();
    };

    void Stay() {
        stay = true;
        CountHouse();
        while(house_value < 17) {
            house.push_back(deck.GetCard());
            CountHouse();
        }
        PrintHouse();
        PrintPlayer();
    };

    void DeckStatus() {
        cout << deck.GetSize() << " Cards Left in current Deck\n\n";
        if (deck.GetSize() < 10) {
            deck.ClearDeck();
            cout << "Reshuffling...\n\n";
            CreateBlackjackDeck(); 
        }
    }

    bool Check() {

        CountPlayer();
        CountHouse();

        if (player_value > 21) {
            cout << "Bust!\n";
            return true;
        }
        else if (house_value > 21) {
            cout << "House Bust!\n";
            return true;
        }
        else if (house_value > player_value && stay) {
            cout << "You Lost!\n";
            return true;
        }
        else if (house_value < player_value && stay){
            cout << "You Won!\n";
            return true;
        }
        else if (house_value == player_value && stay) {
            cout << "Tie!\n";
            return true;

        }
        
        return false;

    };
    void CountHouse() {
        house_value = 0;
        int aces = 0;
        for (int i = 0; i < house.size(); i++) {
            
            house_value += house.at(i).GetValue();
            if (house.at(i).GetValue() == 11) {
                aces++;
            }
        }
        while (house_value > 21 && aces > 0) {
            house_value -= 10;
            aces--;
        };

    }
    void CountPlayer() {
        player_value = 0;
        int aces = 0;
        for (int i = 0; i < player.size(); i++) {
            player_value += player.at(i).GetValue();
            if (player.at(i).GetValue() == 11) {
                aces++;
            }
        }
        while (player_value > 21 && aces > 0) {
            player_value -= 10;
            aces--;
        };
    }

    void PrintPlayer() {
        cout << "Player: ";
        for (int i = 0; i < player.size(); i++) {
            cout<< player.at(i).GetCardInfo() << " ";
        }
        cout << "\n";
    }
    void PrintHouse() {
        cout << "House: ";
        
        for (int i = 0; i < house.size(); i++) {
            if (!stay && i == 0) {
                cout << "********* ";
                continue;
            };
            cout<< house.at(i).GetCardInfo() << " ";
        }
        cout << "\n";
    }

    ~BlackJack() {};

};


int main()
{
    srand(time(NULL));
    BlackJack game;

    bool quit = false;
    while (!quit) {
        game.Start();
        string command;
        while (true) {
            cin >> command;
            if (command == "q" || command == "quit") {
                quit = true;
                break;
            }
            if (command == "h" || command == "hit" || command == "Hit") {
                game.Hit();
            } 
            else
            {
                game.Stay();
            }
            if (game.Check()) {
                game.DeckStatus();
                break;
            };
        }
        Sleep(1000);
    }
    return 0;
}

