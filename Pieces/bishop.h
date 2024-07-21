#ifndef BISHOP_H
#define BISHOP_H

#include "square.h"
#include  "board.h"

class Bishop : public Square { // bishop inherits from square
    public:
        Bishop(int row, int col, int player); // constructor
        ~Bishop(); // destructor

        bool verifyMove(Board board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
}

#endif
