#include "king.h"
#include "../pieceType.h"

King::King(int row, int col, Colour player) : Square(row, col, player) {} 

King::~King() {} // do nothing

bool King::verifyMove(Board *board, int torow, int tocol) {
    if (abs(torow - row) > 1 || abs(tocol - col) > 1) return false;
    else return true;
}

void King::updatePos(int row, int col) {

}

PieceType King::returnType() {
    return PieceType::KING;
}
