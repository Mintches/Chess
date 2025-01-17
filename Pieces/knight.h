#ifndef KNIGHT_H
#define KNIGHT_H

#include "../board.h"
#include "../square.h"

class Board; // forward declaration

class Knight : public Square { // knight inherits from square
    public:
        Knight(int row, int col, Colour player); // constructor
        ~Knight(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleMoves(Board *board) override;
        
        PieceType returnType() override;
};

#endif
