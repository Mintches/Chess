#ifndef PAWN_H
#define PAWN_H

#include "../board.h"
#include "../square.h"

class Board; // forward declaration

class Pawn : public Square { // pawn inherits from square
public:
    Pawn(int row, int col, Colour player); // constructor
    ~Pawn(); // destructor

    bool verifyMove(Board *board, int row, int col) override;

    void updatePos(int row, int col);

    vector<pair<int, int>> possibleCoords(Board *board) override;

    PieceType returnType() override;
    
    void promote(PieceType type);
};

#endif
