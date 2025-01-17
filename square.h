#ifndef SQUARE_H
#define SQUARE_H

#include <utility>
#include <vector>

#include "stdlib.h"
#include "colour.h"
#include "pieceType.h"
#include "move.h"

using namespace std;

class Board; // forward declaration

class Square {
    protected:
        int row;
        int col;
        Colour player;
    public:
        Square();
        Square(int row, int col, Colour player); // constructor
        virtual ~Square() = default; // destructor

        Colour returnPlayer();
        virtual Move verifyMove(Board *board, int torow, int tocol) = 0;
        virtual vector<Move> possibleMoves(Board *board) = 0;
        int getRow();
        int getCol();
        //Square getPiece();

        virtual PieceType returnType() = 0;
        int pointValue();
};

shared_ptr<Square> mPiece(int row, int col, char piece);
shared_ptr<Square> cpyPiece(shared_ptr<Square> piece);

#endif
