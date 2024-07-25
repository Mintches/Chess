#include "square.h"
#include "colour.h"
#include "Pieces/bishop.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include "Pieces/king.h"
#include "Pieces/rook.h"
#include "Pieces/knight.h"

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


Square* mPiece(int row, int col, char piece) {
    Square *s;
    if (piece == 'p') s = new Pawn(row, col, Colour::BLACK);
    else if (piece == 'n') s = new Knight(row, col, Colour::BLACK);
    else if (piece == 'b') s = new Bishop(row, col, Colour::BLACK);
    else if (piece == 'k') s = new King(row, col, Colour::BLACK);
    else if (piece == 'q') s = new Queen(row, col, Colour::BLACK);
    else if (piece == 'r') s = new Rook(row, col, Colour::BLACK);
    else if (piece == 'P') s = new Pawn(row, col, Colour::WHITE);
    else if (piece == 'N') s = new Knight(row, col, Colour::WHITE);
    else if (piece == 'B') s = new Bishop(row, col, Colour::WHITE);
    else if (piece == 'K') s = new King(row, col, Colour::WHITE);
    else if (piece == 'Q') s = new Queen(row, col, Colour::WHITE);
    else if (piece == 'R') s = new Rook(row, col, Colour::WHITE);
    else if (piece == '_') s = new EmptySquare(row, col, Colour::BLUE);
    else if (piece == ' ') s = new EmptySquare(row, col, Colour::LIGHT_BLUE);
    return s;
}