#include "human.h"
#include <iostream>
using namespace std;

Move Human::getMove(Board *board, Colour player) const {
    string strMv;
    cin >> strMv;
    // tokenize strMv, check that it exists in the possible player moves
    vector<Move> v = board->possibleMoves(player); // placeholder
    return v.back();
}
