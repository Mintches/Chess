#include <string>
#include "computer.h"
#include "level3.h"
using namespace std;

Move Level3::getMove(Board *board, Colour colour) const {
    Move bestMv;
    PieceType maxCapture = PieceType::EMPTY;
    bool checkMv = false;

    // loop through all legal moves, check one by one
    for (auto mv : board->legalMoves(colour)) {
        board->makeMove(mv);
        bool safeMove = true;

        // check opponent moves and see if any of them attack a piece
        Colour oppColour = (colour == Colour::WHITE ? Colour::BLACK : Colour::WHITE)
        for (auto oppMv : board->legalMoves(oppColour)) {
            if (oppMv.getDeleted().back()->returnType() != PieceType::EMPTY) {
                safeMove = false;
                break;
            }
        }
        board->undoMove(mv);

        if (safeMove) { // the move avoids capture, go with it
            if (mv.getCheck() > checkMv ||
            (mv.getCheck() == checkMv && mv.getDeleted().back()->returnType() > maxCapture)) {
                // next prioritize capturing and checks (like level 2)
                maxCapture = mv.getDeleted().back()->returnType();
                checkMv = mv.getCheck();
                bestMv = mv;
            }
        } else { // no moves avoid capture, follow via level 2 priority
            if (mv.getCheck() > checkMv ||
            (mv.getCheck() == checkMv && mv.getDeleted().back()->returnType() > maxCapture)) {
                maxCapture = mv.getDeleted().back()->returnType();
                checkMv = mv.getCheck();
                bestMv = mv;
            }
        }
    }
    return bestMv; 
}