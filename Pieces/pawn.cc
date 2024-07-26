#include <iostream>

#include "pawn.h"

#include "../square.h"

Pawn::Pawn(int row, int col, Colour player) : Square{row, col, player} {}

Pawn::~Pawn() {} // do nothing

Move Pawn::verifyMove(Board *board, int torow, int tocol) {
    Move m;
    // determine foward direction based on colour
    int forward = 0;
    if (player == Colour::WHITE) {
        forward = -1; // White moves up the grid
    } else if (player == Colour::BLACK) {
        forward = 1; // Black moves down the grid
    }
    if (col == tocol && board->getSquare(torow, tocol)->returnType() == PieceType::EMPTY) { // move straight forward
        if (torow - row == forward) { // move forward 1
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addDeleted(board->getSquare(row, col));
            m.addDeleted(board->getSquare(torow, tocol));
            if (torow == 0 || torow == 7) { // pawn promotion
                char piece;
                cin >> piece;
                //Square *sq = mPiece(torow, tocol, piece);
                if (piece != 'k' && piece != 'K') {
                    m.addAdded(mPiece(torow, tocol, piece));
                    m.addDeleted(board->getSquare(row, col));
                }
            } else {
                m.addAdded(make_shared<Pawn>(torow, tocol, player));
                m.addDeleted(board->getSquare(row, col));
            }
            board->removePassantable(); // en passant only valid for immediate move after
            return m; //true;
        } else if (torow - row == forward * 2 
        && board->getSquare(row + forward, tocol)->returnType() == PieceType::EMPTY 
        && board->getSquare(row + forward * 2, tocol)->returnType() == PieceType::EMPTY) { // move forward 2
            m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
            m.addAdded(make_shared<Pawn>(torow, tocol, player));
            m.addDeleted(board->getSquare(row, col));
            m.addDeleted(board->getSquare(torow, tocol));
            // this square is now passantable
            board->setPassantable(torow, tocol);
            return m; //true;
        }
    } else if (abs(col - tocol) == 1 && torow - row == forward) { // move diagonal
    cout << "!" << endl;
        if (board->getSquare(torow, tocol)->returnPlayer() != player) {
            if (board->getSquare(torow, tocol)->returnType() != PieceType::EMPTY) { // normal capture
                m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
                m.addAdded(make_shared<Pawn>(torow, tocol, player));
                m.addDeleted(board->getSquare(row, col));
                m.addDeleted(board->getSquare(torow, tocol));
                board->removePassantable(); // en passant only valid for immediate move after
                return m;
            } else { // destination square is empty
            cout << "word" << endl;
                int passantRow = board->getPassantable().first;
                int passantCol = board->getPassantable().second;
                cout << passantRow <<":"<< passantCol << endl;
                if (passantRow == row && passantCol == tocol) { // additional requirements for en passant capture
                    m.addAdded(make_shared<EmptySquare>(row, col, Colour::BLUE));
                    m.addAdded(make_shared<Pawn>(torow, tocol, player));
                    m.addDeleted(board->getSquare(row, col));
                    m.addDeleted(board->getSquare(torow, tocol));
                    // remove en passant captured piece
                    m.addAdded(make_shared<EmptySquare>(passantRow, passantCol, Colour::BLUE));
                    m.addDeleted(board->getSquare(passantRow, passantCol));
                    board->removePassantable(); // en passant only valid for immediate move after
                    return m;
                }
            }
        }
    }
    return m;
}

vector<Move> Pawn::possibleMoves(Board *board) {
    vector<Move> v;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (verifyMove(board, i, j).getAdded().size() != 0) v.push_back(verifyMove(board, i, j));
        }
    }
    return v;
}

PieceType Pawn::returnType() {
    return PieceType::PAWN;
}
