#ifndef ROOK_H
#define ROOK_H

#include "square.h"
#include  "board.h"

class Rook : public Square { // bishop inherits from square
    public:
        Rook(int row, int col, int player); // constructor
        ~Rook(); // destructor

        bool verifyMove(Board board, int row, int col) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
}

#endif
