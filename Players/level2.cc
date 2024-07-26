#include <string>
#include "computer.h"
#include "level2.h"
#include "../pieceType.h"

using namespace std;

Move Level2::getMove(Board *board, Colour colour) const {
    PieceType maxCapture = PieceType::EMPTY;
    Move bestMv;
    for (auto mv : board->legalMoves(colour)) {
        if (bestMv.getAdded().size() == 0) bestMv = mv;
        PieceType thisCapture = PieceType::EMPTY;
        for (auto c : mv.getDeleted()) {
            if (c->returnPlayer() != colour) thisCapture = c->returnType();
            if (thisCapture > maxCapture) {
                maxCapture = thisCapture;
                bestMv = mv;
            }
        }
        if (mv.getCheck() > bestMv.getCheck() && thisCapture >= maxCapture) {
            maxCapture = thisCapture;
            bestMv = mv;
        }
    }
    return bestMv; // return highest capture move
}