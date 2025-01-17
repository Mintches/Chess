#ifndef PAWN_H
#define PAWN_H

#include "../board.h"
#include "../square.h"

#include "knight.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "emptysquare.h"

class Board; // forward declaration

class Pawn : public Square { // pawn inherits from square
    int moveNum;
    public:
        Pawn(int row, int col, Colour player); // constructor
        ~Pawn(); // destructor

        Move verifyMove(Board *board, int torow, int tocol) override;

        vector<Move> possibleMoves(Board *board) override;

        PieceType returnType() override;
    };

#endif
