#include <iostream>

#include "game.h"
#include "Players/computer.h"
#include "Players/human.h"

using namespace std;

const int BOARD_DIMENSION = 8;

int main() {
    Player *p = new Human();
    Player *c = new Computer();
    Game g(p, c);
    g.setupGame();
    cout << "Hello World!" << endl;
}
