#include "king.h"
#include "../pieceType.h"

King::King(int row, int col, Colour player) : Square(row, col, player) {} 

King::~King() {} // do nothing

Move King::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (abs(torow - row) + abs(tocol - col) == 1 && (abs(torow - row) == 1 || abs(tocol - col) == 1)) { // king move limits
        if (board->getSquare(torow, tocol)->returnPlayer() != player) { // check if capture
            if (board->getSquare(torow, tocol)->returnType() != PieceType::KING) { // can't capture other king
                return m;
            }
        }
    }
    return m;
} // maybe check that it's not right beside another king? althought verifyCheck() should deal with that case

vector<Move> King::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType King::returnType() {
    return PieceType::KING;
}
