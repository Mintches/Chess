#include "emptysquare.h"

EmptySquare::EmptySquare(int row, int col, Colour player): Square{row, col, player} {} 
EmptySquare::~EmptySquare() {} // do nothing

Move EmptySquare::verifyMove(Board *board, int row, int col) {
    Move m;
    return m;
}

void EmptySquare::updatePos(int row, int col) {

}

vector<Move> EmptySquare::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}

PieceType EmptySquare::returnType() {
    return PieceType::EMPTY;
}
