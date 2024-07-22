#ifndef KING_H
#define KING_H

#include "../square.h"

class Board; // forward declaration

class King : public Square { // king inherits from square
    public:
        King(int row, int col, int player); // constructor
        ~King(); // destructor

        bool verifyMove(Board *board, int torow, int tocol) override;

        void updatePos(int row, int col);
        
        PieceType returnType() override;
};

#endif