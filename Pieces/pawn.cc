#include <iostream>

#include "pawn.h"

#include "../square.h"

Pawn::Pawn(int row, int col, Colour player) : Square{row, col, player} {}

Pawn::~Pawn() {} // do nothing

Move Pawn::verifyMove(Board *board, int torow, int tocol) { // TODO: enpassant :SKULL:
    // determine foward direction based on colour
    Move m;
    int forward = 0;
    if (player == Colour::WHITE) {
        forward = -1; // White moves up the grid
    } else if (player == Colour::BLACK) {
        forward = 1; // Black moves down the grid
    }
    //cout << (col - tocol) << "\n";
    if (col == tocol && board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY) { // move straight forward
        if (torow - row == forward) { // move forward 1
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
            if (torow == 0 || torow == 7) { // pawn promotion
                char piece;
                cin >> piece;
                //Square *sq = mPiece(torow, tocol, piece);
                m.addAdded(mPiece(torow, tocol, piece));
            } else {
                m.addAdded(new Pawn(torow, tocol, player));
            }
            return m; //true;
        } else if (torow - row == forward * 2 && board->getSquare(row + forward, tocol)->returnType() == PieceType::EMPTY && board->getSquare(row + forward * 2, tocol)->returnType() == PieceType::EMPTY) { // move forward 2
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Pawn(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
            return m; //true;
        }
    } else if (abs(col - tocol) == 1 && torow - row == forward) { // move diagonal
        int passantRow = board->returnPassantable().first;
        int passantCol = board->returnPassantable().second;
        if (board->getSquare(torow, tocol)->returnType() != PieceType::EMPTY && board->getSquare(torow, tocol)->returnPlayer() != player) { // normal capture
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Pawn(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
            if (passantRow == row && passantCol == tocol) { // additional changes for en passant capture
                m.addDeleted(board->getSquare(passantRow, passantCol));
                m.addAdded(new EmptySquare(passantRow, passantCol, Colour::BLUE));
            }
        }
    }
    return m; // automatically checks if it moved at all
}

vector<Move> Pawn::possibleCoords(Board *board) {
    vector<Move> v;
    return v;
}


PieceType Pawn::returnType() {
    return PieceType::PAWN;
}

void Pawn::promote(PieceType type) {
    
}
