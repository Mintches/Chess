#include <utility>
#include <iostream>

#include "bishop.h"
#include "emptysquare.h"

using namespace std;

Bishop::Bishop(int row, int col, Colour player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

Move Bishop::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    std::cout << torow << ":" << tocol;
    if (abs(torow - row) == abs(tocol - col) && row != torow) { // bishop move limit and that it'll actually moved
        if (board->getSquare(torow, tocol)->returnType() != PieceType::EMPTY 
        || board->getSquare(torow, tocol)->returnPlayer() != player) { // destination is capture or empty square
            // go step by step and check each square on the way
            int shiftrow = 1, shiftcol = 1;
            if (torow < row) shiftrow *= -1;
            if (tocol < col) shiftrow *= -1;
            int currow = row, curcol = col;
            currow += shiftrow;
            curcol += shiftcol;
            while (currow != torow) {
                std::cout << currow << ":" << torow << ":" << curcol <<":" << tocol;
                if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;
                currow += shiftrow;
                curcol += shiftcol;
            }
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Bishop(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
        }
    }
    return m;
}

vector<Move> Bishop::possibleCoords(Board *board) {
    vector<Move> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j).getAdded().size() != 0) v.push_back(verifyMove(board, i, j));
        }
    }
    return v;
}

PieceType Bishop::returnType() {
    return PieceType::BISHOP;
}