#include <iostream>

#include "pawn.h"
#include "emptysquare.h"

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
                Square *sq;
                if (piece == 'p')sq = new Pawn(torow, tocol, Colour::BLACK);
                else if (piece == 'n') sq = new Knight(torow, tocol, Colour::BLACK);
                else if (piece == 'b') sq = new Bishop(torow, tocol, Colour::BLACK);
                else if (piece == 'k') sq = new King(torow, tocol, Colour::BLACK);
                else if (piece == 'q') sq = new Queen(torow, tocol, Colour::BLACK);
                else if (piece == 'r') sq = new Rook(torow, tocol, Colour::BLACK);
                else if (piece == 'P') sq = new Pawn(torow, tocol, Colour::WHITE);
                else if (piece == 'N') sq = new Knight(torow, tocol, Colour::WHITE);
                else if (piece == 'B') sq = new Bishop(torow, tocol, Colour::WHITE);
                else if (piece == 'K') sq = new King(torow, tocol, Colour::WHITE);
                else if (piece == 'Q') sq = new Queen(torow, tocol, Colour::WHITE);
                else if (piece == 'R') sq = new Rook(torow, tocol, Colour::WHITE);
                else if (piece == '_') sq = new EmptySquare(torow, tocol, Colour::BLACK);
                else if (piece == ' ') sq = new EmptySquare(torow, tocol, Colour::WHITE);
                m.addAdded(sq);
            } else {
                m.addAdded(new Pawn(torow, tocol, player));
            }
            return m; //true;
        } else if (torow - row == forward * 2 && board->getSquare(torow + forward, tocol)->returnType() == PieceType::EMPTY) { // move forward 2
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
