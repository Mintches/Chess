#include "emptysquare.h"

EmptySquare::EmptySquare(int row, int col, Colour player): Square{row, col, player} {} 
EmptySquare::~EmptySquare() {} // do nothing

bool EmptySquare::verifyMove(Board *board, int row, int col) {
    return true;
}

void EmptySquare::updatePos(int row, int col) {

}

vector<pair<int, int>> EmptySquare::possibleMoves(Board *board) {
    vector<pair<int, int>> v;
    return v;
}

PieceType EmptySquare::returnType() {
    return PieceType::EMPTY;
}
