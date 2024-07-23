#include "square.h"
#include "colour.h"

Square::Square(): row{0}, col{0}, player{Colour::WHITE} {}

Square::Square(int row, int col, Colour player) : row{row}, col{col}, player{player} {}

/*Square Square::getPiece() {
    return *this;
}*/

int Square::getRow() { return row; }
int Square::getCol() { return col; }

/*PieceType Square::returnType() { // incomplete
    return PieceType;
}*/

Colour Square::returnPlayer() {
    return player;
}
