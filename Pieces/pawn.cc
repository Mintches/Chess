#include "pawn.h"

Pawn::Pawn(int row, int col, int player) : Square(row, col, player) {} 
Pawn::~Pawn() {} // do nothing

bool Pawn::verify(Board board, int row, int col) {
    return true;
}

void Pawn::updatePos(int row, int col) {

}

PieceType Pawn::returnType() {
    return PieceType::Pawn;
}

void Pawn::promote(PieceType type) {
    
}
