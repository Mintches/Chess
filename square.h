#ifndef SQUARE_H
#define SQUARE_H

#include "board.h"
#include "pieceType.h"

class Square {
    int row;
    int col;
    int player;
    public:
        Square(int row, int col, int player); // constructor
        ~Square(); // destructor

        bool verifyMove(Board board, int row, int col);

        Square getPiece();

        PieceType returnType();
};

#endif

