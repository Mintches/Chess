#include "knight.h"

Knight::Knight(int row, int col, Colour player) : Square(row, col, player) {} 
Knight::~Knight() {} // do nothing

bool Knight::verifyMove(Board *board, int torow, int tocol) {
    if (returnPlayer(board, torow, tocol) != player) {
        if ((abs(row - torow) == 3 && abs(col - tocol) == 1)
            || (abs(row - torow) == 1 && abs(col - tocol) == 3)) {
            return true;
        }
    } else {
        return false;
    }
}

void Knight::updatePos(int row, int col) {

}

PieceType Knight::returnType() {
    return PieceType::KNIGHT;
}
