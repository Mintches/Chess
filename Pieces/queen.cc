#include "queen.h"

Queen::Queen(int row, int col, int player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

bool Queen::verify(Board board, int row, int col) {
    return true;
}

void Queen::updatePos(int row, int col) {

}

PieceType Queen::returnType() {
    return PieceType::Queen;
}
