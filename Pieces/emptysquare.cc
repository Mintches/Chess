#include "emptysquare.h"

EmptySquare::EmptySquare(int row, int col, Colour player): Square{row, col, ((row + col) % 2 == 0) ? Colour::LIGHT_BLUE : Colour::BLUE} {
    //if ((row + col) % 2 == 0) player = Colour::LIGHT_BLUE;
    //else player = Colour::BLUE;
} 
EmptySquare::~EmptySquare() {} // do nothing

Move EmptySquare::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    return m;
}

vector<Move> EmptySquare::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}

PieceType EmptySquare::returnType() {
    return PieceType::EMPTY;
}
