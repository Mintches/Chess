#ifndef SQUARE_H
#define SQUARE_H

#include "stdlib.h"
#include "colour.h"
#include "pieceType.h"

class Board; // forward declaration

class Square {
protected:
    int row;
    int col;
    Colour player;
public:
    Square();
    Square(int row, int col, Colour player); // constructor
    virtual ~Square() = default; // destructor

    Colour returnPlayer(Board *board, int row, int col);
    virtual bool verifyMove(Board *board, int row, int col) = 0;

    //Square getPiece();

    virtual PieceType returnType() = 0;
};

#endif

