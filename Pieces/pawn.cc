#include "pawn.h"

Pawn::Pawn(int row, int col, int player) : Square(row, col, player) {}

Pawn::~Pawn() {} // do nothing

bool Pawn::verifyMove(Board *board, int row, int col) {
    return true;
}

void Pawn::updatePos(int row, int col) {

}

PieceType Pawn::returnType() {
    return PieceType::PAWN;
}

void Pawn::promote(PieceType type) {
    
}
