#include <iostream>

#include "game.h"
#include "input.h"
#include "Observers/textObserver.h"
#include "Observers/graphicsObserver.h"

using namespace std;

// maybe a global const for board dimensions?

int main() {
    string in;
    Input inp;
    Game *g = new Game();
    TextObserver *to = new TextObserver{g};
    // GraphicsObserver *go = new GraphicsObserver{g};
    g->attach(to);
    // g->attach(go);
    cout << "Please input either 'game' or 'setup'" << endl;
    while (cin >> in) {
        if (in == "game") {
            Player *p1 = inp.createPlayer();
            Player *p2 = inp.createPlayer();
            g->setPlayerTypes(p1, p2);
            g->playGame();// game should check if there's already a board. if not, it uses standard chess setup
            continue;
        } 
        else if (in == "setup") {
            g->setupGame(); // should add its setup into game's board
        } 
        else {
            cerr << "Not a valid commmand" << endl;
        }
        cout << "Please input either 'game' or 'setup'" << endl;
    }

    g->printScore();
}
