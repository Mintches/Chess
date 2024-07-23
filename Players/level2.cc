#include <string>
#include "computer.h"
#include "level2.h"
#include "../pieceType.h"

using namespace std;

string Level2::getMove(Board *board, Colour player) const {

    for (auto mv : board->possibleMoves(player)) {
        PieceType maxCapture = PieceType::EMPTY;
        Move bestMv;
        
        if (mv.getCaptured()->returnType() >= maxCapture) {
            bestMv = mv;
        }
    }
    return ""; // return highest capture move
}