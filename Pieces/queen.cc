#include "queen.h"

Queen::Queen(int row, int col, Colour player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

Move Queen::verifyMove(Board *board, int torow, int tocol) {
    // a queen is just a bishop and a rook, 2 cases
    /*if (abs(torow - row) == abs(tocol - col)) Bishop::verifyMove(board, row, col); // bishop case
    else if (torow == row || tocol == col) Rook::verifyMove(board, row, col); // rook case
    else return false; // invalid*/
    Move m;
    return m;
}

void Queen::updatePos(int row, int col) {

}

vector<Move> Queen::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Queen::returnType() {
    return PieceType::QUEEN;
}
