#include "queen.h"
#include "emptysquare.h"
#include <iostream>

Queen::Queen(int row, int col, Colour player) : Square(row, col, player) {} 

Queen::~Queen() {} // do nothing

Move Queen::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    // a queen is just a bishop and a rook, 2 cases
    if (abs(torow - row) == abs(tocol - col)) { // bishop case
        if (abs(torow - row) != abs(tocol - col)) return m;
        if (row == torow && col == tocol) return m;
        if (board->getSquare(row, col)->returnPlayer() == board->getSquare(torow, tocol)->returnPlayer()) return m;
    
        int shiftrow = 1, shiftcol = 1;
        if (torow < row) shiftrow *= -1;
        if (tocol < col) shiftrow *= -1;
        int currow = row, curcol = col;
        currow += shiftrow;
        curcol += shiftcol;
        while (currow != torow) {
            if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m; // false
            currow += shiftrow;
            curcol += shiftcol;
        }
        m.addAdded(new EmptySquare(row, col, Colour::BLUE));
        m.addAdded(new Queen(torow, tocol, player));
        m.addDeleted(this);
        m.addDeleted(board->getSquare(torow, tocol));
        return m;
    } else if (torow == row || tocol == col) { // rook case
        Move m;
        if (row != torow && col != tocol) return m; // false
        if (row == torow && col == tocol) return m; // false;
        if (board->getSquare(row, col)->returnPlayer() == board->getSquare(torow, tocol)->returnPlayer()) return m; // false;
        
        int currow = row, curcol = col;
        int shift = 1;
        if (row == torow) { // horizontally
            if (col > tocol) shift = -1;
            curcol += shift;
            while (col != tocol) {
                if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m; //false
                curcol += shift;
            }
        } else { // vertically
            if (row > torow) shift = -1;
            currow += shift;
            while (row != torow) {
                if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m; //false
                currow += shift;
            }
        }
        m.addAdded(new EmptySquare(row, col, Colour::BLUE));
        m.addAdded(new Queen(torow, tocol, player));
        m.addDeleted(this);
        m.addDeleted(board->getSquare(torow, tocol));
        return m; 
    }
    else return m; // invalid, empty move
}

vector<Move> Queen::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Queen::returnType() {
    return PieceType::QUEEN;
}
