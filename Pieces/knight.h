#ifndef KNIGHT_H
#define KNIGHT_H

#include "../board.h"
#include "../square.h"

class Board; // forward declaration

class Knight : public Square { // knight inherits from square
    public:
        Knight(int row, int col, Colour player); // constructor
        ~Knight(); // destructor

        bool verifyMove(Board *board, int row, int col) override;

        void updatePos(int row, int col);

        vector<pair<int, int>> possibleMoves(Board *board) override;
        
        PieceType returnType() override;
};

#endif
