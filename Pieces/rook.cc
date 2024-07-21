#include "rook.h"

Rook::Rook(int row, int col, int player) : Square(row, col, player) {} 
Rook::~Rook() {} // do nothing

bool Rook::verifyMove(Board *board, int row, int col) {
    return true;
}

void Rook::updatePos(int row, int col) {

}

PieceType Rook::returnType() {
    return PieceType::ROOK;
}
