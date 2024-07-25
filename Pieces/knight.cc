#include "knight.h"

Knight::Knight(int row, int col, Colour player) : Square(row, col, player) {} 
Knight::~Knight() {} // do nothing

Move Knight::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (board->getSquare(row, col)->returnType() == PieceType::EMPTY || board->getSquare(row, col)->returnPlayer() != player) {
        if ((abs(row - torow) == 2 && abs(col - tocol) == 1)
            || (abs(row - torow) == 1 && abs(col - tocol) == 2)) {
            return m;
        }
        return m;
    } else return m;
}

vector<Move> Knight::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Knight::returnType() {
    return PieceType::KNIGHT;
}
