#ifndef EMPTY_SQUARE_H
#define EMPTY_SQUARE_H

#include "../square.h"
#include "../colour.h"

class Board; // forward declaration

class EmptySquare : public Square { // emptysquare inherits from square
    public:
        EmptySquare(int row, int col, Colour player); // constructor
        ~EmptySquare(); // destructor

        Move verifyMove(Board *board, int row, int col) override;

        void updatePos(int row, int col);

        vector<Move> possibleCoords(Board *board) override;
        
        PieceType returnType() override;
};

#endif
