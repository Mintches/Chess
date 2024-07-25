#ifndef ROOK_H
#define ROOK_H

#include "../board.h"
#include "../square.h"

class Board; // forward declaration

class Rook : public Square { // bishop inherits from square
    bool moved;
    public:
        Rook(int row, int col, Colour player, bool moved); // constructor
        ~Rook(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleMoves(Board *board) override;
        
        PieceType returnType() override;

        bool isMoved();
};

#endif
