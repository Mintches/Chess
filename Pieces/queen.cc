#include "queen.h"

Queen::Queen(int row, int col, int player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

bool Queen::verifyMove(Board *board, int row, int col) {
    // check if queen can physical move there
    if ((row != torow && col != tocol) && (abs(torow - row) != abs(tocol - col))) return false;
    // check if the queen is not already on that square
    if (row == torow && col == tocol) return false;
    // check if destination square has one of your own pieces
    if (returnPlayer(board, row, col) == returnPlayer(board, torow, tocol)) return false;
}

void Queen::updatePos(int row, int col) {

}

PieceType Queen::returnType() {
    return PieceType::QUEEN;
}
