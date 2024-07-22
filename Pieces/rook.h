#ifndef ROOK_H
#define ROOK_H

#include "../board.h"
#include "../square.h"

class Board; // forward declaration

class Rook : public Square { // bishop inherits from square
    public:
        Rook(int row, int col, Colour player); // constructor
        ~Rook(); // destructor

        bool verifyMove(Board *board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
};

#endif
