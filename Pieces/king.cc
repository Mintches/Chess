#include "king.h"

King::King(int row, int col, Colour player) : Square(row, col, player) {} 

King::~King() {} // do nothing

Move King::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (board->getSquare(row, col)->returnPlayer() != player) return m; // right colour
    if (abs(torow - row) + abs(tocol - col) == 1) { // king move limits
        // ~two kings, chillin in a hot tub, 5 ft apart cuz~
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (board->getSquare(torow + i, tocol + j)->returnType() == PieceType::KING && i != 0 && j != 0) {
                    return m;
                }
            }
        }
        m.addAdded(new EmptySquare(row, col, Colour::BLUE));
        m.addAdded(new King(torow, tocol, player));
        m.addDeleted(this);
        m.addDeleted(board->getSquare(torow, tocol));
    } /*else if (!moved && torow == row) { // check for castle
        if (tocol - col == 2 && board->getSquare(row, 7)->returnType() == PieceType::ROOK) { // right castle
            if (rook moved) {
            }
        } else if (tocol - col == -2 && board->getSquare(row, 0)->returnType() == PieceType::ROOK) { // left castle
            if (rook moved) {
            }
        }
    }*/
    return m;
}

vector<Move> King::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType King::returnType() {
    return PieceType::KING;
}
