#ifndef KING_H
#define KING_H

#include "../board.h"
#include "../square.h"


class King : public Square { // king inherits from square
    public:
        King(int row, int col, Colour player); // constructor
        ~King(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        void updatePos(int row, int col);

        vector<Move> possibleCoords(Board *board) override;
        
        PieceType returnType() override;
};

#endif