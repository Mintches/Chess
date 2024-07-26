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

int Square::pointValue() {
    int num = 0;
    if (returnType() == PieceType::PAWN) num = 10;
    else if (returnType() == PieceType::BISHOP) num = 30;
    else if (returnType() == PieceType::KNIGHT) num = 30;
    else if (returnType() == PieceType::ROOK) num = 50;
    else if (returnType() == PieceType::KING) num = 90;
    else if (returnType() == PieceType::QUEEN) num = 900;
    return num;
}


shared_ptr<Square> mPiece(int row, int col, char piece) {
    shared_ptr<Square> s;
    if (piece == 'p') s = make_shared<Pawn>(row, col, Colour::BLACK);
    else if (piece == 'n') s = make_shared<Knight>(row, col, Colour::BLACK);
    else if (piece == 'b') s = make_shared<Bishop>(row, col, Colour::BLACK);
    else if (piece == 'k') s = make_shared<King>(row, col, Colour::BLACK, false);
    else if (piece == 'q') s = make_shared<Queen>(row, col, Colour::BLACK);
    else if (piece == 'r') s = make_shared<Rook>(row, col, Colour::BLACK, false);
    else if (piece == 'P') s = make_shared<Pawn>(row, col, Colour::WHITE);
    else if (piece == 'N') s = make_shared<Knight>(row, col, Colour::WHITE);
    else if (piece == 'B') s = make_shared<Bishop>(row, col, Colour::WHITE);
    else if (piece == 'K') s = make_shared<King>(row, col, Colour::WHITE, false);
    else if (piece == 'Q') s = make_shared<Queen>(row, col, Colour::WHITE);
    else if (piece == 'R') s = make_shared<Rook>(row, col, Colour::WHITE, false);
    else if (piece == '_') s = make_shared<EmptySquare>(row, col, Colour::BLUE);
    else if (piece == ' ') s = make_shared<EmptySquare>(row, col, Colour::LIGHT_BLUE);
    return s;
}

shared_ptr<Square> cpyPiece(shared_ptr<Square> piece) {
    shared_ptr<Square> s;
    if (piece->returnType() == PieceType::PAWN) s = make_shared<Pawn>(piece->getRow(), piece->getCol(), piece->returnPlayer());
    if (piece->returnType() == PieceType::ROOK) s = make_shared<Rook>(piece->getRow(), piece->getCol(), piece->returnPlayer(), false);
    if (piece->returnType() == PieceType::BISHOP) s = make_shared<Bishop>(piece->getRow(), piece->getCol(), piece->returnPlayer());
    if (piece->returnType() == PieceType::KNIGHT) s = make_shared<Knight>(piece->getRow(), piece->getCol(), piece->returnPlayer());
    if (piece->returnType() == PieceType::QUEEN) s = make_shared<Queen>(piece->getRow(), piece->getCol(), piece->returnPlayer());
    if (piece->returnType() == PieceType::KING) s = make_shared<King>(piece->getRow(), piece->getCol(), piece->returnPlayer(), false);
    if (piece->returnType() == PieceType::EMPTY) s = make_shared<EmptySquare>(piece->getRow(), piece->getCol(), piece->returnPlayer());
    return s;
}
