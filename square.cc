#include "square.h"

Square::Square(): row{0}, col{0}, player{0} {}

Square::Square(int row, int col, int player) : row{row}, col{col}, player{player} {}

/*Square Square::getPiece() {
    return *this;
}*/

/*PieceType Square::returnType() { // incomplete
    return PieceType::QUEEN;
}*/

int returnPlayer(Board *board, int row, int col) {
    
}
