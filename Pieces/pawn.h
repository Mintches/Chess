#ifndef PAWN_H
#define PAWN_H

#include "../square.h"

class Board; // forward declaration

class Pawn : public Square { // bishop inherits from square
    public:
        Pawn(int row, int col, int player); // constructor
        ~Pawn(); // destructor

        bool verifyMove(Board *board, int row, int col) override;

        void updatePos(int row, int col);

        PieceType returnType() override;
        
        void promote(PieceType type);
};

#endif