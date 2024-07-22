#ifndef PAWN_H
#define PAWN_H

#include "../square.h"

class Board; // forward declaration

class Pawn : public Square { // pawn inherits from square
    bool moved;
public:
    Pawn(int row, int col, Colour player, bool moved); // constructor
    ~Pawn(); // destructor

    bool verifyMove(Board *board, int row, int col) override;

    void updatePos(int row, int col);

    PieceType returnType() override;
    
    void promote(PieceType type);
};

#endif
