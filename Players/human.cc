#include "human.h"
#include "../input.h"
#include <iostream>
using namespace std;

Move Human::getMove(Board *board, Colour player) const {
    Input in;
    pair<int, int> sq1 = in.getSquare();
    pair<int, int> sq2 = in.getSquare();
    Move m = board->getSquare(sq1.first, sq1.second)->verifyMove(board, sq2.first, sq2.second);
    return m;
}
