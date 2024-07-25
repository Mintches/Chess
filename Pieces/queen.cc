#include "queen.h"
#include "emptysquare.h"
#include <iostream>

Queen::Queen(int row, int col, Colour player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

Move Queen::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    if (abs(torow - row) == abs(tocol - col) && row != torow) { // bishop move limit and that it'll actually moved
        if (board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY 
        || board->getSquare(torow, tocol)->returnPlayer() != player) { // destination is capture or empty square
            // go step by step and check each square on the way
            int shiftrow = 1, shiftcol = 1;
            if (torow < row) shiftrow *= -1;
            if (tocol < col) shiftcol *= -1;
            int currow = row, curcol = col;
            currow += shiftrow;
            curcol += shiftcol;
            while (currow != torow) {
                //std::cout << currow << ":" << torow << ":" << curcol <<":" << tocol << endl;
                if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;
                currow += shiftrow;
                curcol += shiftcol;
            }
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Queen(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
        }
    } else if ((row != torow && col == tocol) || (row == torow && col != tocol)) { // rook move limits and not already on that square
        if (board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY 
        || board->getSquare(torow, tocol)->returnPlayer() != player) { // destination is capture or empty square
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
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Queen(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
        }
    }
    return m;
}

vector<Move> Queen::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Queen::returnType() {
    return PieceType::QUEEN;
}
