#include <string>
#include "computer.h"
#include "level3.h"
using namespace std;

Move Level3::getMove(Board *board, Colour colour) const {
    vector<Move> v = board->legalMoves(colour);
    return v.back(); // placeholder so it doesn't crash
}