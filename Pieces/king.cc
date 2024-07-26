#include "king.h"

King::King(int row, int col, Colour player, bool moved) : Square(row, col, player), moved{moved} {} 

King::~King() {} // do nothing

Move King::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY
    || board->getSquare(torow, tocol)->returnPlayer() != player) {
        if (abs(torow - row) + abs(tocol - col) == 1) { // king move limits
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addAdded(make_shared<King>(torow, tocol, player, true));
            m.addDeleted(board->getSquare(this->getRow(), this->getCol()));
            m.addDeleted(board->getSquare(torow, tocol));
            moved = true;
        }
    } else if (!moved && torow == row && (torow = 7 || torow == 0)) { // check for castle
        int left = 0; // left and right 
        int right = 7;
        int side;
        Rook *rook = nullptr;
        if (tocol - col == 2 && board->getSquare(row, right)->returnType() == PieceType::ROOK) { // right castle
            Square *sq = board->getSquare(row, right).get();
            rook = dynamic_cast<Rook*>(sq);
            side = right;
        } else if (tocol - col == -3 && board->getSquare(row, left)->returnType() == PieceType::ROOK) { // left castle
            Square *sq = board->getSquare(row, left).get();
            rook = dynamic_cast<Rook*>(sq);
            side = left;
        }
        if (rook && !rook->isMoved()) {
            int curcol = col;
            int shift = 1; // if castle right, 
            if (tocol < col) shift = -1; // if castle left
            curcol += shift;
            while (tocol != curcol) {
                if (board->verifyCheck(player)) return m;
                curcol += shift;
            }
            // move king
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addAdded(make_shared<King>(torow, tocol, player, true));
            m.addDeleted(board->getSquare(this->getRow(), this->getCol()));
            m.addDeleted(board->getSquare(torow, tocol));
            // move rook
            m.addAdded(make_shared<EmptySquare>(row, side, Colour::BLUE));
            m.addAdded(make_shared<Rook>(row, tocol - shift, player, true));
            m.addDeleted(board->getSquare(row, side));
            m.addDeleted(board->getSquare(row, tocol - shift));
        }
    }
    return m;
}

vector<Move> King::possibleMoves(Board *board) {
    vector<Move> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j).getAdded().size() != 0) v.push_back(verifyMove(board, i, j));
        }
    }
    return v;
}


PieceType King::returnType() {
    return PieceType::KING;
}
