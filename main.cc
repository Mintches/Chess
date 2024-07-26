#include <iostream>
#include <memory>

#include "game.h"
#include "input.h"
#include "Observers/textObserver.h"
#include "Observers/graphicsObserver.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in;
    Input inp;
    unique_ptr<Game> g = make_unique<Game>();
    unique_ptr<TextObserver> to = make_unique<TextObserver>(g.get());
    g->attach(to.get());
    for (int i = 0; i < argc; i++) {
        string tst = "graphics";
        if (argv[i] == tst) {
            unique_ptr<GraphicsObserver> go = make_unique<GraphicsObserver>(g.get());
            g->attach(go.get());
            break;
        }
    }
    cout << "Please input either 'game' or 'setup':" << endl;
    while (cin >> in) {
        if (in == "game") {
            unique_ptr<Player> p1 = inp.createPlayer();
            unique_ptr<Player> p2 = inp.createPlayer();
            g->setPlayerTypes(p1.get(), p2.get());
            g->playGame();
            continue;
        } 
        else if (in == "setup") {
            g->setupGame(); // should add its setup into game's board
        } 
        else {
            cout << "Not a valid commmand." << endl;
        }
        cout << "Please input either 'game' or 'setup':" << endl;
    }
    g->printScore();
}
