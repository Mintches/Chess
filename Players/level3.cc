#include <string>
#include "computer.h"
#include "level3.h"
using namespace std;

Move Level3::getMove(Board *board, Colour colour) const {
    Move bestMv;
    PieceType maxCapture = PieceType::EMPTY;
    bool escapeCapture = false;

    Colour oppColour = (colour == Colour::WHITE ? Colour::BLACK : Colour::WHITE);

    for (auto mv : board->legalMoves(colour)) {
        if (bestMv.isEmpty()) bestMv = mv;
        bool escapeCaptureMove = false;
        for (auto mvPiece : mv.getDeleted()) {
            willCapture(board, oppColour, colour, mvPiece);
            if (mvPiece->returnPlayer() == colour && willCapture(board, oppColour, colour, mvPiece)) {
                board->movePiece(mv);
                if (!willCapture(board, oppColour, colour, mvPiece)) escapeCaptureMove = true;
                board->undoMove();
            }
        }
        if (escapeCaptureMove && !escapeCapture) {
            escapeCapture = true;
            bestMv = mv;
        }
        if (!escapeCapture || escapeCaptureMove) {
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
    }
    return bestMv; 
}

bool willCapture(Board *board, Colour oppPlayer, Colour currPlayer, shared_ptr<Square> s) {
    board->legalMoves(oppPlayer);
    for (auto mv : board->legalMoves(oppPlayer)) {
        for (auto target : mv.getDeleted()) {
            if (target == s) {
                return true;
            }
        }
    }
    return false;
}