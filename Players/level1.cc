#include <string>
#include <random>
#include <vector>

#include "computer.h"
#include "level1.h"
#include "../colour.h"
#include "../move.h"

uniform_int_distribution<int> r(1, 1e9);
mt19937 gen(998244353);

Move Level1::getMove(Board *board, Colour colour) const {
    vector<Move> v = board->legalMoves(colour);
    return v[r(gen) % v.size()];
}
