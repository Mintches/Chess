#include "human.h"
#include "../input.h"
#include <iostream>
using namespace std;

Move Human::getMove(Board *board, Colour player) const {
    cout << "Please input a move:" << "\n";
    Input in;
    pair<int, int> sq1 = in.getCoords();
    pair<int, int> sq2 = in.getCoords();
    cout << sq1.first << " " << sq1.second << " " << sq2.first << " " << sq2.second << "\n";
    Move m = board->getSquare(sq1.first, sq1.second)->verifyMove(board, sq2.first, sq2.second);
    return m;
}
