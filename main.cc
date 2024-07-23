#include <iostream>

#include "game.h"
#include "input.h"

using namespace std;

// maybe a global const for board dimensions?

int main() {
    string in;
    Game g;
    while (cin >> in) {
        if (in == "game") {
            Player *p1 = createPlayer();
            Player *p2 = createPlayer();
            g.setPlayerTypes(p1, p2);
            g.playGame(); // game should check if there's already a board. if not, it uses standard chess setup
        } else if (in == "setup") {
            g.setPlayer(Colour::WHITE);
            g.setupGame(); // should add its setup into game's board
        } else {
            cerr << "Not a valid commmand" << endl;
        }
    }

    g.printScore();
}
