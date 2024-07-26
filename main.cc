#include <iostream>
#include <memory>

#include "game.h"
#include "input.h"
#include "Observers/textObserver.h"
#include "Observers/graphicsObserver.h"

using namespace std;

// maybe a global const for board dimensions?

void run() {
    string in;
    Input inp;
    unique_ptr<Game> g = make_unique<Game>();
    unique_ptr<TextObserver> to = make_unique<TextObserver>(g.get());
    unique_ptr<GraphicsObserver> go = make_unique<GraphicsObserver>(g.get());
    g->attach(to.get());
    g->attach(go.get());
    cout << "Please input either 'game' or 'setup'" << endl;
    while (cin >> in) {
        if (in == "game") {
            unique_ptr<Player> p1 = inp.createPlayer();
            unique_ptr<Player> p2 = inp.createPlayer();
            g->setPlayerTypes(p1.get(), p2.get());
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

int main() {
    run();
}
