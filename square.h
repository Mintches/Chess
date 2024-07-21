#ifndef SQUARE_H
#define SQUARE_H

#include "board.h"

class Square {
    virtual:
        int row;
        int col;
        int player;
    public:
        Square(int row, int col, int player); // constructor
        ~Square(); // destructor

        bool verifyMove(Board board, int row, int col);

        Square getPiece();

        enum {Pawn, Knight, Bishop, Rook, Queen, King, Blank};
        PieceType returnType();
};

#endif

