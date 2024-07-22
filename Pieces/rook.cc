#include "rook.h"

Rook::Rook(int row, int col, Colour player) : Square(row, col, player) {} 
Rook::~Rook() {} // do nothing

bool Rook::verifyMove(Board *board, int torow, int tocol) {
    // check if rook can physical move there
    if (row != torow && col != tocol) return false;
    // check if the rook is not already on that square
    if (row == torow && col == tocol) return false;
    // check if destination square has one of your own pieces
    if (returnPlayer(board, row, col) == returnPlayer(board, torow, tocol)) return false;
    
    // go step by step to the destination and see if there's pieces blocking
    int currow = row, curcol = col;
    int shift = 1;
    if (row == torow) { // the rook moves horizontally
        if (col > tocol) shift = -1;
        curcol += shift;
        while (col != tocol) {
            if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return false;
            curcol += shift;
        }
    } else { // the rook moves vertically
        if (row > torow) shift = -1;
        currow += shift;
        while (row != torow) {
            if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return false;
            currow += shift;
        }
    }
    return true;
}

void Rook::updatePos(int row, int col) {

}

PieceType Rook::returnType() {
    return PieceType::ROOK;
}
