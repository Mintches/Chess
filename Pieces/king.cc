#include "king.h"
#include "../pieceType.h"

King::King(int row, int col, int player) : Square(row, col, player) {} 
King::~King() {} // do nothing

bool King::verify(Board board, int row, int col) {
    return true;
}

void King::updatePos(int row, int col) {

}

PieceType King::returnType() {
    return PieceType::King;
}
