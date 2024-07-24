#include "knight.h"

Knight::Knight(int row, int col, Colour player) : Square(row, col, player) {} 
Knight::~Knight() {} // do nothing

bool Knight::verifyMove(Board *board, int torow, int tocol) {
    if (board->getSquare(row, col)->returnType() == PieceType::EMPTY || board->getSquare(row, col)->returnPlayer() != player) {
        if ((abs(row - torow) == 2 && abs(col - tocol) == 1)
            || (abs(row - torow) == 1 && abs(col - tocol) == 2)) {
            return true;
        }
    } else return false;
}

void Knight::updatePos(int row, int col) {

}

vector<pair<int, int>> Knight::possibleCoords(Board *board) {
    vector<pair<int, int>> v;
    return v;
}


PieceType Knight::returnType() {
    return PieceType::KNIGHT;
}
