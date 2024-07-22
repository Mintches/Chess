#ifndef QUEEN_H
#define QUEEN_H

#include "../square.h"

class Board; // forward declaration

class Queen : public Square { // queen inherits from square
    public:
        Queen(int row, int col, Colour player); // constructor
        ~Queen(); // destructor

        bool verifyMove(Board *board, int row, int col) override;

        void updatePos(int row, int col);

        vector<pair<int, int>> possibleMoves(Board *board) override;
        
        PieceType returnType() override;
};

#endif
