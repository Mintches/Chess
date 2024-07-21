#ifndef KING_H
#define KING_H

#include "square.h"
#include  "board.h"

class King : public Square { // king inherits from square
    public:
        King(int row, int col, int player); // constructor
        ~King(); // destructor

        bool verifyMove(Board board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
}

#endif