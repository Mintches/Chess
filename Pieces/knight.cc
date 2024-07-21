#include "knight.h"

Knight::Knight(int row, int col, int player) : Square(row, col, player) {} 
Knight::~Knight() {} // do nothing

bool Knight::verifyMove(Board *board, int row, int col) {
    return true;
}

void Knight::updatePos(int row, int col) {

}

PieceType Knight::returnType() {
    return PieceType::KNIGHT;
}
