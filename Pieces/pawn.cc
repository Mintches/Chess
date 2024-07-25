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
            board->removePassantable(); // en passant only valid for immediate move after
            return m; //true;
        } else if (torow - row == forward * 2 
        && board->getSquare(row + forward, tocol)->returnType() == PieceType::EMPTY 
        && board->getSquare(row + forward * 2, tocol)->returnType() == PieceType::EMPTY) { // move forward 2
            m.addAdded(new EmptySquare(row, col, Colour::BLUE));
            m.addAdded(new Pawn(torow, tocol, player));
            m.addDeleted(this);
            m.addDeleted(board->getSquare(torow, tocol));
            // this square is now passantable
            board->setPassantable(torow, tocol);
            return m; //true;
        }
    } else if (abs(col - tocol) == 1 && torow - row == forward) { // move diagonal
    cout << "!" << endl;
        if (board->getSquare(torow, tocol)->returnPlayer() != player) {
            if (board->getSquare(torow, tocol)->returnType() != PieceType::EMPTY) { // normal capture
                m.addAdded(new EmptySquare(row, col, Colour::BLUE));
                m.addAdded(new Pawn(torow, tocol, player));
                m.addDeleted(this);
                m.addDeleted(board->getSquare(torow, tocol));
                board->removePassantable(); // en passant only valid for immediate move after
                return m;
            } else { // destination square is empty
            cout << "word";
                int passantRow = board->getPassantable().first;
                int passantCol = board->getPassantable().second;
                if (passantRow == row && passantCol == tocol) { // additional requirements for en passant capture
                    m.addAdded(new EmptySquare(row, col, Colour::BLUE));
                    m.addAdded(new Pawn(torow, tocol, player));
                    m.addDeleted(this);
                    m.addDeleted(board->getSquare(torow, tocol));
                    // remove en passant captured piece
                    m.addDeleted(board->getSquare(passantRow, passantCol));
                    m.addAdded(new EmptySquare(passantRow, passantCol, Colour::BLUE));
                    board->removePassantable(); // en passant only valid for immediate move after
                    return m;
                }
            }
        }
    }
    return m;
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
