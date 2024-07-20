#include <iostream>
#include "player.h"
using namespace std;

string Player::getMove() const {
    string move;
    cin >> move;
    return move;
} // TODO: check valid string
