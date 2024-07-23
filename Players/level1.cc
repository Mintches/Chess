#include <string>
#include <random>
#include <vector>

#include "computer.h"
#include "level1.h"
#include "../colour.h"
#include "../move.h"

//uniform_int_distribution<int> random(1, 1e9);
//mt19937 gen(998244353);

Move Level1::getMove(Board *board, Colour player) const {
    vector<Move> v = board->possibleMoves(player);
    //return v[random(gen) % v.size()];
    return v.back();
}
