#ifndef BISHOP_H
#define BISHOP_H

#include <utility>
#include <vector>

#include "../square.h"
#include "../move.h"

class Board; // forward declaration

class Bishop : public Square { // bishop inherits from square
    public:
        Bishop(int row, int col, Colour player); // constructor
        ~Bishop(); // destructor

        bool verifyMove(Board *board, int torow, int tocol) override;

        void updatePos(int torow, int tocol);

        vector<pair<int, int>> possibleMoves(Board *board);
        
        PieceType returnType() override;
};

#endif
