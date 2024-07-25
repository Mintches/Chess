#ifndef QUEEN_H
#define QUEEN_H

#include "../square.h"
#include "../board.h"

class Board; // forward declaration

class Queen : public Square { // queen inherits from square
    public:
        Queen(int row, int col, Colour player); // constructor
        ~Queen(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleMoves(Board *board) override;
        
        PieceType returnType() override;
};

#endif
