#include "bishop.h"
using namespace std;

Bishop::Bishop(int row, int col, int player): Square{row, col, player} {} 

Bishop::~Bishop() {} // do nothing

bool Bishop::verifyMove(Board *board, int torow, int tocol) {
    if (abs(torow - row) != abs(tocol - col)) return false;
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