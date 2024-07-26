#include "human.h"
#include "../input.h"
#include <iostream>
#include <memory>
using namespace std;

Move Human::getMove(Board *board, Colour player) const {
    //cout << "Please input a valid move:" << endl;
    Input in;
    pair<int, int> sq1 = in.getCoords();
    pair<int, int> sq2 = in.getCoords();
    shared_ptr<Square> s = board->getSquare(sq1.first, sq1.second);
    Move m;
    if (s->returnPlayer() != player) return m;
    m = s->verifyMove(board, sq2.first, sq2.second);
    return m;
}
