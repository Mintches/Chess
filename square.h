#ifndef SQUARE_H
#define SQUARE_H

#include "pieceType.h"

class Board; // forward declaration

class Square {
    int row;
    int col;
    int player;
    public:
        Square();
        Square(int row, int col, int player); // constructor
        ~Square(); // destructor

        virtual bool verifyMove(Board *board, int row, int col);

        Square getPiece();

        virtual PieceType returnType();
};

#endif

