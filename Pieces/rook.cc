#include "rook.h"

Rook::Rook(int row, int col, Colour player) : Square(row, col, player) {} 
Rook::~Rook() {} // do nothing

Move Rook::verifyMove(Board *board, int torow, int tocol) {
    // check if rook can physical move there
    Move m;
    if (row != torow && col != tocol) return m; //false;
    // check if the rook is not already on that square
    if (row == torow && col == tocol) return m; //false;
    // check if destination square has one of your own pieces
    if (board->getSquare(row, col)->returnPlayer() == board->getSquare(torow, tocol)->returnPlayer()) return m;//return false;
    
    // go step by step to the destination and see if there's pieces blocking
    int currow = row, curcol = col;
    int shift = 1;
    if (row == torow) { // the rook moves horizontally
        if (col > tocol) shift = -1;
        curcol += shift;
        while (col != tocol) {
            if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;//false;
            curcol += shift;
        }
    } else { // the rook moves vertically
        if (row > torow) shift = -1;
        currow += shift;
        while (row != torow) {
            if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;//false;
            currow += shift;
        }
    }
    return m; //true;
}

void Rook::updatePos(int row, int col) {

}

vector<Move> Rook::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Rook::returnType() {
    return PieceType::ROOK;
}
