#ifndef KNIGHT_H
#define KNIGHT_H

#include "square.h"
#include  "board.h"

class Knight : public Square { // knight inherits from square
    public:
        Knight(int row, int col, int player); // constructor
        ~Knight(); // destructor

        bool verifyMove(Board board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
}

#endif
