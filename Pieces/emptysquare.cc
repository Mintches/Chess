#include "emptysquare.h"

EmptySquare::EmptySquare(int row, int col, int player): Square{row, col, player} {} 
EmptySquare::~EmptySquare() {} // do nothing

bool EmptySquare::verifyMove(Board *board, int row, int col) {
    return true;
}

void EmptySquare::updatePos(int row, int col) {

}

PieceType EmptySquare::returnType() {
    return PieceType::EMPTY;
}
