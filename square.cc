#include "square.h"

Square::Square(): row{0}, col{0}, player{Colour::WHITE} {}

Square::Square(int row, int col, Colour player) : row{row}, col{col}, player{player} {}

/*Square Square::getPiece() {
    return *this;
}*/

/*PieceType Square::returnType() { // incomplete
    return PieceType::QUEEN;
}*/

Colour Square::returnPlayer() {
    return player;
}
