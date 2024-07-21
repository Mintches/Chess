#include "square.h"

Square::Square(int row, int col, int player) : row(row), col(col), player(player) {}
Square::~Square() {} // do nothing

bool Square::verifyMove(Board board, int row, int col) { // incomplete
    return true;
}

Square Square::getPiece() {
    return *this;
}

PieceType Square::returnType() { // incomplete
    return PieceType::Queen;
}

