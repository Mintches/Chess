#include "king.h"

King::King(int row, int col, Colour player, bool moved) : Square(row, col, player), moved{moved} {} 

King::~King() {} // do nothing

Move King::verifyMove(Board *board, int torow, int tocol) {
    Move m;
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
        m.addAdded(new King(torow, tocol, player, true));
        m.addDeleted(this);
        m.addDeleted(board->getSquare(torow, tocol));
    } else if (!moved && torow == row) { // check for castle
        int left = 0; // left and right 
        int right = 7;
        int side;
        Rook *rook = nullptr;
        if (tocol - col == 2 && board->getSquare(row, left)->returnType() == PieceType::ROOK) { // right castle
            Square *sq = board->getSquare(row, left);
            rook = dynamic_cast<Rook*>(sq);
            side = left;
        } else if (tocol - col == -2 && board->getSquare(row, right)->returnType() == PieceType::ROOK) { // left castle
            Square *sq = board->getSquare(row, right);
            rook = dynamic_cast<Rook*>(sq);
            side = right;
        }
        if (rook && !rook->isMoved()) {
            int curcol = col;
            int shift = 1;
            if (tocol < col) shift = -1;
            curcol += shift;
            while (tocol != curcol) {
                if (board->verifyCheck(player)) return m;
                curcol += shift;
            }
            // move king
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new King(torow, tocol, player, true));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
            // move rook
            m.addAdded(new Rook(row, tocol - shift, Colour::BLUE, true));
            m.addDeleted(board->getSquare(row, side));
        }
    }
    return m;
}

vector<Move> King::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType King::returnType() {
    return PieceType::KING;
}
