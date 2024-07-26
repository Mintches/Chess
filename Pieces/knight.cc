#include "knight.h"
#include "emptysquare.h"

Knight::Knight(int row, int col, Colour player) : Square(row, col, player) {} 
Knight::~Knight() {} // do nothing

Move Knight::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (board->getSquare(row, col)->returnType() == PieceType::EMPTY || board->getSquare(torow, tocol)->returnPlayer() != player) {
        if ((abs(row - torow) == 2 && abs(col - tocol) == 1)
            || (abs(row - torow) == 1 && abs(col - tocol) == 2)) { // knight move limits
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addAdded(make_shared<Knight>(torow, tocol, player));
            m.addDeleted(board->getSquare(row, col));
            m.addDeleted(board->getSquare(torow, tocol));
            return m;
        }
    }
    return m;
}

vector<Move> Knight::possibleMoves(Board *board) {
    vector<Move> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j).getAdded().size() != 0) v.push_back(verifyMove(board, i, j));
        }
    }
    return v;
}


PieceType Knight::returnType() {
    return PieceType::KNIGHT;
}
