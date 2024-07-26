#include "rook.h"
#include "emptysquare.h"
#include <iostream>

Rook::Rook(int row, int col, Colour player, bool moved) : Square(row, col, player), moved{moved} {} 
Rook::~Rook() {} // do nothing

Move Rook::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY 
    || board->getSquare(torow, tocol)->returnPlayer() != player) { // destination is capture or empty square
        if ((row != torow && col == tocol) || (row == torow && col != tocol)) { // rook move limit and that it'll actually moved
            // go step by step and check each square on the way
            // get shifts in horizontal and vertical direction
            int shiftrow = torow - row;
            int shiftcol = tocol - col;
            if (shiftrow == 0) { // horizontal
                shiftcol = 1;
                if (tocol < col) shiftcol = -1;
            } else { // vertical
                shiftrow = 1;
                if (torow < row) shiftrow = -1;
            }
            int currow = row, curcol = col;
            currow += shiftrow;
            curcol += shiftcol;
            while (currow != torow || curcol != tocol) {
                if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;
                currow += shiftrow;
                curcol += shiftcol;
            }
            //moved = true;
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addAdded(make_shared<Rook>(torow, tocol, player, true));
            m.addDeleted(board->getSquare(row, col));
            m.addDeleted(board->getSquare(torow, tocol));
        }
    }
    return m;
}

vector<Move> Rook::possibleMoves(Board *board) {
    vector<Move> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j).getAdded().size() != 0) v.push_back(verifyMove(board, i, j));
        }
    }
    return v;
}


PieceType Rook::returnType() {
    return PieceType::ROOK;
}

bool Rook::isMoved() {
    return moved;
}
