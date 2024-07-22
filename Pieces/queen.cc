#include "queen.h"

Queen::Queen(int row, int col, int player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

bool Queen::verifyMove(Board *board, int row, int col) {
    // a queen is just a bishop and a rook, 2 cases
    if (abs(torow - row) == abs(tocol - col)) Bishop::verifyMove(board, row, col); // bishop case
    else if (torow == row || tocol == col) Rook::verifyMove(board, row, col); // rook case
    else return false; // invalid
    return true;
}

void Queen::updatePos(int row, int col) {

}

PieceType Queen::returnType() {
    return PieceType::QUEEN;
}
