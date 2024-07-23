#ifndef KING_H
#define KING_H

#include "../board.h"
#include "../square.h"


class King : public Square { // king inherits from square
    public:
        King(int row, int col, Colour player); // constructor
        ~King(); // destructor

        bool verifyMove(Board *board, int torow, int tocol) override;

        void updatePos(int row, int col);

        vector<pair<int, int>> possibleCoords(Board *board) override;
        
        PieceType returnType() override;
};

#endif