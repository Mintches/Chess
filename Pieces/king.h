#ifndef KING_H
#define KING_H

#include "../board.h"
#include "../square.h"
#include "emptysquare.h"
#include "rook.h"
#include "../pieceType.h"


class King : public Square { // king inherits from square
    bool moved;
    public:
        King(int row, int col, Colour player, bool moved); // constructor
        ~King(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleMoves(Board *board) override;
        
        PieceType returnType() override;
};

#endif