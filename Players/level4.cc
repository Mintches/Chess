#include <string>
#include "computer.h"
#include "level4.h"
using namespace std;

const int INF = 9999999;

int minimax(Board board, int depth, int alpha, int beta, bool mxPlayer) {
    if (verifyCheckmate(Colour::WHITE) || verifyCheckmate(Colour::BLACK) || 
    verifyStalemate(Colour::WHITE) || verifyStalemate(Colour::BLACK) || verifyDraw() || depth == 0) return board.eval();
    
}

string Level4::getMove(Board board) const {
    return ""; // TODO: return a Level 4 move
}