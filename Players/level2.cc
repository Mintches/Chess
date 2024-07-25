#include <string>
#include "computer.h"
#include "level2.h"
#include "../pieceType.h"

using namespace std;

Move Level2::getMove(Board *board, Colour player) const {
    PieceType maxCapture = PieceType::EMPTY;
    bool checkMv = false;
    Move bestMv;
    for (auto mv : board->legalMoves()) {
        if (mv.getCheck() >= checkMv) {
            if (mv.getDeleted().back()->returnType() > maxCapture) {
                maxCapture = mv.getDeleted().back()->returnType();
                checkMv = mv.getCheck();
                bestMv = mv;
            }
        }
    }
    return bestMv; // return highest capture move
}