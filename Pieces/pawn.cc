#include "pawn.h"

Pawn::Pawn(int row, int col, Colour player) : Square{row, col, player} {}

Pawn::~Pawn() {} // do nothing

Move Pawn::verifyMove(Board *board, int torow, int tocol) { // TODO: enpassant :SKULL:
    // determine foward direction based on colour
    Move m;
    int forward;
    if (player == Colour::WHITE) {
        forward = 1;
    } else if (player == Colour::BLACK) {
        forward = 1;
    }
    if (col - tocol == 0 && board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY) { // move straight forward
        if (row - torow == forward) {
            return m; //true;
        } else if (row - torow == forward * 2 && board->getSquare(torow - forward, tocol)->returnType() == PieceType::EMPTY) {
            return m; //true;
        }
    } else if (abs(col - tocol) == 1 && row - torow == forward 
               && board->getSquare(torow - forward, tocol)->returnType() != PieceType::EMPTY
               && board->getSquare(torow, tocol)->returnPlayer() != player) { // diagonal
        return m; //true;
    }
    return m; //false; // automatically checks if it moved at all
}

void Pawn::updatePos(int row, int col) {

}

vector<Move> Pawn::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Pawn::returnType() {
    return PieceType::PAWN;
}

void Pawn::promote(PieceType type) {
    
}
