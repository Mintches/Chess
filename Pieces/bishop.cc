#include <utility>

#include "bishop.h"
#include "emptysquare.h"

using namespace std;

Bishop::Bishop(int row, int col, Colour player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

Move Bishop::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    // check if the bishop can physically move there
    if (abs(torow - row) != abs(tocol - col)) return m;
    // check if the bishop is not already on that square
    if (row == torow && col == tocol) return m;
    // check if the destination square has one of your own pieces
    if (board->getSquare(row, col)->returnPlayer() == board->getSquare(torow, tocol)->returnPlayer()) return m;

    // go step by step and check each square on the way
    int shiftrow = 1, shiftcol = 1;
    if (torow < row) shiftrow *= -1;
    if (tocol < col) shiftrow *= -1;
    int currow = row, curcol = col;
    currow += shiftrow;
    curcol += shiftcol;
    while (currow != torow) {
        if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return m;
        currow += shiftrow;
        curcol += shiftcol;
    }
    m.addAdded(new EmptySquare(row, col, Colour::BLUE));
    m.addAdded(new Bishop(torow, tocol, player));
    m.addDeleted(this);
    m.addDeleted(board->getSquare(torow, tocol));
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

void Bishop::updatePos(int torow, int tocol) {

}

PieceType Bishop::returnType() {
    return PieceType::BISHOP;
}