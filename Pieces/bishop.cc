#include "bishop.h"
using namespace std;

Bishop::Bishop(int row, int col, int player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

bool Bishop::verifyMove(Board *board, int row, int col) {
    return true;
}

void Bishop::updatePos(int row, int col) {

}

PieceType Bishop::returnType() {
    return PieceType::BISHOP;
}