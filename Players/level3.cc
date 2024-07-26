#include <string>
#include "computer.h"
#include "level3.h"
using namespace std;

Move Level3::getMove(Board *board, Colour colour) const {
    Move bestMv;
    /*PieceType maxCapture = PieceType::EMPTY;
    bool checkMv = false;
    bool escapeCapture = false;

    Colour oppColour = (colour == Colour::WHITE ? Colour::BLACK : Colour::WHITE);
    vector<Square *> willBeCaptured;

    for (auto mv : board->legalMoves(oppColour)) {
        for (auto willCapture : mv.getAdded()) {
            if (willCapture->returnPlayer() == colour && find(willBeCaptured.begin(), willBeCaptured.end(), willCapture) != willBeCaptured.end()) 
                willBeCaptured.push_back(willCapture).get();
        }
    }

    for (auto mv : board->legalMoves(colour)) {
        if (bestMv.isEmpty()) bestMv = mv;
        for (auto mvPiece : mv.getAdded()) {
            if (find(willBeCaptured.begin(), willBeCaptured.end(), mvPiece)) {
                board->movePiece()
            }
        }
    }

    // loop through all legal moves, check one by one
    for (auto mv : board->legalMoves(colour)) {
        if (bestMv.isEmpty()) bestMv = mv;
        board->movePiece(mv);
        bool safeMove = true;

        // check opponent moves and see if any of them attack a piece
        
        for (auto oppMv : board->legalMoves(oppColour)) {
            if (oppMv.getDeleted().back()->returnType() != PieceType::EMPTY) {
                safeMove = false;
                break;
            }
        }
        board->undoMove();

        if (safeMove) { // the move avoids capture, go with it
            if (mv.getCheck() > checkMv ||
            (mv.getCheck() == checkMv && mv.getDeleted().back()->returnType() > maxCapture)) {
                // next prioritize capturing and checks (like level 2)
                maxCapture = mv.getDeleted().back()->returnType();
                checkMv = mv.getCheck();
                bestMv = mv;
            }
        } 
        else { // no moves avoid capture, follow via level 2 priority
            if (mv.getCheck() > checkMv ||
            (mv.getCheck() == checkMv && mv.getDeleted().back()->returnType() > maxCapture)) {
                maxCapture = mv.getDeleted().back()->returnType();
                checkMv = mv.getCheck();
                bestMv = mv;
            }
        }
    }*/
    return bestMv; 
}

//bool notCaptured()