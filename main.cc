#include <iostream>

#include "game.h"
#include "Players/level1.h"
#include "Players/human.h"

using namespace std;

const int BOARD_DIMENSION = 8;

int main() {
    Player *p = new Human();
    Player *c = new Level1();
    Game g(p, c);
    g.setupGame();
    g.playGame();
}
