#include <iostream>
#include "game.h"

using namespace std;

const int BOARD_DIMENSION = 8;

int main() {
    Game g = {nullptr, nullptr};
    g.setupGame();
    cout << "Hello World!" << endl;
}