#ifndef BISHOP_H
#define BISHOP_H

#include <utility>
#include <vector>

#include "../board.h"
#include "../square.h"
#include "../move.h"

class Bishop : public Square { // bishop inherits from square
    public:
        Bishop(int row, int col, Colour player); // constructor
        ~Bishop(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleCoords(Board *board);
        
        PieceType returnType() override;
};

#endif
