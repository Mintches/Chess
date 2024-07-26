#include "human.h"
#include "../input.h"
#include <iostream>
#include <memory>
using namespace std;

Move Human::getMove(Board *board, Colour player) const {
    Input in;
    pair<int, int> sq1 = in.getCoords();
    pair<int, int> sq2 = in.getCoords();
    Move m;
    if (sq1.first >= 8 || sq1.first < 0 || sq1.second >= 8 || sq1.second < 0
    || sq2.first >= 8 || sq2.first < 0 || sq2.second >= 8 || sq2.second < 0) return m;
    shared_ptr<Square> s = board->getSquare(sq1.first, sq1.second);
    if (s->returnPlayer() != player) return m;
    m = s->verifyMove(board, sq2.first, sq2.second);
    return m;
}
