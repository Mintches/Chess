#include <utility>

#include "bishop.h"

using namespace std;

Bishop::Bishop(int row, int col, Colour player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

bool Bishop::verifyMove(Board *board, int torow, int tocol) {
    // check if the bishop can physically move there
    if (abs(torow - row) != abs(tocol - col)) return false;
    // check if the bishop is not already on that square
    if (row == torow && col == tocol) return false;
    // check if the destination square has one of your own pieces
    if (board->getSquare(row, col)->returnPlayer() == board->getSquare(torow, tocol)->returnPlayer()) return false;

    // go step by step and check each square on the way
    int shiftrow = 1, shiftcol = 1;
    if (torow < row) shiftrow *= -1;
    if (tocol < col) shiftrow *= -1;
    int currow = row, curcol = col;
    currow += shiftrow;
    curcol += shiftcol;
    while (currow != torow) {
        if (board->getSquare(currow, curcol)->returnType() != PieceType::EMPTY) return false;
        currow += shiftrow;
        curcol += shiftcol;
    }
    return true;
}

vector<pair<int, int>> Bishop::possibleMoves(Board *board) {
    vector<pair<int, int>> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j)) v.push_back({i, j});
        }
    }
    return v;
}

void Bishop::updatePos(int torow, int tocol) {

}

PieceType Bishop::returnType() {
    return PieceType::BISHOP;
}