#include <string>
#include <random>
#include <vector>

#include "computer.h"
#include "../board.h"
#include "../colour.h"
#include "../move.h"

string Level1::getMove(Board board, Colour player) const {
    vector<Move> v = board.possibleMoves(player);
    return v[random(gen) % v.size()];
}
