#include "bishop.h"

Bishop::Bishop(int row, int col, int player) : Square(row, col, player) {} 
Bishop::~Bishop() {} // destructor, does nothing

bool Bishop::verify(Board board, int row, int col) {
    return true;
}

void Bishop::updatePos(int row, int col) {

}

PieceType Bishop::returnType() {
    return PieceType::Bishop;
}