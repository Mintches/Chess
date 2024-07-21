#ifndef EMPTY_SQUARE_H
#define EMPTY_SQUARE_H

#include "square.h"
#include  "board.h"

class EmptySquare : public Square { // emptysquare inherits from square
    public:
        EmptySquare(int row, int col, int player); // constructor
        ~EmptySquare(); // destructor

        bool verifyMove(Board board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
}

#endif
