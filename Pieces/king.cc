#include "king.h"
#include "../pieceType.h"

King::King(int row, int col, Colour player) : Square(row, col, player) {} 

King::~King() {} // do nothing

bool King::verifyMove(Board *board, int torow, int tocol) {
    if (abs(torow - row) + abs(tocol - col) == 1 && (abs(torow - row) == 1 || abs(tocol - col) == 1)) { // king move limits
        if (board->getSquare(torow, tocol)->returnPlayer() != player) { // check if capture
            if (board->getSquare(torow, tocol)->returnType() != PieceType::KING) { // can't capture other king
                return true;
            }
        }
    }
    return false;
} // maybe check that it's not right beside another king? althought verifyCheck() should deal with that case

void King::updatePos(int row, int col) {

}

vector<pair<int, int>> King::possibleCoords(Board *board) {
    vector<pair<int, int>> v;
    return v;
}


PieceType King::returnType() {
    return PieceType::KING;
}
