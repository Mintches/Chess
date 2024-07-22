#include "bishop.h"
using namespace std;

Bishop::Bishop(int row, int col, int player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

bool Bishop::verifyMove(Board *board, int torow, int tocol) {
    // check if the bishop can physically move there
    if (abs(torow - row) != abs(tocol - col)) return false;
    // check if the bishop is not already on that square
    if (row == torow && col == tocol) return false;
    // check if the destination square has one of your own pieces
    if (returnPlayer(board, row, col) == returnPlayer(board, torow, tocol)) return false;

    // go step by step and check each square on the way
    int shiftrow = 1, shiftcol = 1;
    if (torow < row) shiftrow *= -1;
    if (tocol < col) shiftrow *= -1;
    int currow = row, curcol = col;
    currow += shiftrow;
    curcol += shiftcol;
    while (currow != torow) {
        if (board->checkSquare(currow, curcol)->returnType() != PieceType::EMPTY) return false;
        currow += shiftrow;
        curcol += shiftcol;
    }
    return true;
}

void Bishop::updatePos(int row, int col) {

}

PieceType Bishop::returnType() {
    return PieceType::BISHOP;
}