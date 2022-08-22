#include<Windows.h>
#include "Blackjack.h"


int main()
{
    srand(time(NULL));
    Blackjack game;

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

