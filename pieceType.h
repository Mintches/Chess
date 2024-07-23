#ifndef PIECETYPE_H
#define PIECETYPE_H

enum class PieceType { // follows minimax point procedure
    EMPTY = 0, 
    PAWN = 10, 
    KNIGHT = 30, 
    BISHOP = 31, 
    ROOK = 50, 
    QUEEN = 90, 
    KING = 900
};

#endif
