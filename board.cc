#include <iostream>
#include <utility>
#include <vector>

#include "board.h"
#include "square.h"
#include "Pieces/pawn.h"
#include "Pieces/knight.h"
#include "Pieces/queen.h"
#include "Pieces/king.h"
#include "Pieces/bishop.h"
#include "Pieces/rook.h"
#include "Pieces/emptysquare.h"
#include "colour.h"
#include "boardIterator.h"

using namespace std;

Board::Board() {
    resetBoard();
}

Board::Board(const Board& b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = cpyPiece(b.arr[i][j]);
        }
    }
}

vector<Move> Board::legalMoves(Colour player) { // list of moves, considers checks
    vector<Move> moves;
    // compile moves from each piece
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i][j]->returnPlayer() == player) {
                vector<Move> pieceMoves = arr[i][j]->possibleMoves(this);
                for (auto mv : pieceMoves) {
                    bool alreadyChecking = false;
                    Colour oppPlayer = (player == Colour::WHITE ? Colour::BLACK : Colour::WHITE);
                    if (verifyCheck(oppPlayer)) alreadyChecking = true;
                    if (movePiece(mv) && !verifyCheck(player)) { // if no self-checked
                        if (!alreadyChecking && verifyCheck(oppPlayer)) mv.setCheck(true);
                        moves.push_back(mv);
                    }
                    undoMove();
                }
            }
        }
    }
    return moves;
}

bool Board::checkLegal(Move m, Colour player) {
    if (m.isEmpty()) return false;
    bool retval = true;
    movePiece(m);
    if (verifyCheck(player)) retval = false;
    undoMove();
    return retval;
}

shared_ptr<Square> Board::getSquare(int row, int col) {
    return arr[row][col]; // TODO: check the row and col are valid
}

bool Board::verifyCheck(Colour player) { // is player being checked
    // find king
    int kingRow = -1;
    int kingCol = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (arr[i][j]->returnType() == PieceType::KING && arr[i][j]->returnPlayer() == player) {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
    }
    // see if any pieces could capture king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!arr[i][j]->verifyMove(this, kingRow, kingCol).isEmpty()) return true;
        }
    }
    return false;
}

bool Board::verifyCheckmate(Colour player) { // is player checkmated
    return legalMoves(player).empty() && verifyCheck(player);
}

bool Board::verifyStalemate(Colour player) { // is player stuck
    return legalMoves(player).empty() && !verifyCheck(player);
}

bool Board::verifySetup() {
    int kingBlack = 0;
    int kingWhite = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (arr[i][j]->returnPlayer() == Colour::WHITE) {
                if (arr[i][j]->returnType() == PieceType::KING) {
                    ++kingWhite;
                    if (kingWhite > 1) return false;
                } else if (arr[i][j]->returnType() == PieceType::PAWN) {
                    if (arr[i][j]->getRow() == 0) return false;
                }
            } else if (arr[i][j]->returnPlayer() == Colour::BLACK) {
                if (arr[i][j]->returnType() == PieceType::KING) {
                    ++kingBlack;
                    if (kingBlack > 1) return false;
                } else if (arr[i][j]->returnType() == PieceType::PAWN) {
                    if (arr[i][j]->getRow() == 7) return false;
                }
            }
        }
    }
    if (kingBlack + kingWhite != 0) return false;
    return true;
}

bool Board::movePiece(Move m) { // mindlessly follows given Move m, if given move isn't possible (ignoring checks), return false
    if (m.isEmpty()) return false;
    // do the move
    for (auto deletedSq : m.getDeleted()) {
        deletePiece(deletedSq->getRow(), deletedSq->getCol());
    }
    for (auto addedSq : m.getAdded()) {
        arr[addedSq->getRow()][addedSq->getCol()] = addedSq;
    }
    movesMade.push_back(m);
    return true;
}

void Board::makePiece(int row, int col, char piece) {
    arr[row][col] = mPiece(row, col, piece);
}

void Board::deletePiece(int row, int col) {
    Colour player= Colour::BLUE;
    if ((row + col) % 2 == 0) {
        player = Colour::LIGHT_BLUE;
    }
    arr[row][col] = make_shared<EmptySquare>(row, col, player);
}

void Board::undoMove() {
    if (movesMade.size() == 0) return;
    Move latestMv = movesMade.back();
    //Move undoMv;
    for (auto addedSq : latestMv.getAdded()) {
        // remove added
        deletePiece(addedSq->getRow(), addedSq->getCol());
    }
    for (auto deletedSq : latestMv.getDeleted()) {
        // restore deleted
        arr[deletedSq->getRow()][deletedSq->getCol()] = deletedSq;
    }
    movesMade.pop_back();
}


void Board::standardBoard() {
    resetBoard();

    //pawns
    for (int i = 0; i < 8; ++ i) {
        makePiece(1, i, 'p');
        makePiece(6, i, 'P');
    }
    //rooks
    makePiece(0, 0, 'r');
    makePiece(0, 7, 'r');
    makePiece(7, 0, 'R');
    makePiece(7, 7, 'R');

    //knights
    makePiece(0, 1, 'n');
    makePiece(0, 6, 'n');
    makePiece(7, 1, 'N');
    makePiece(7, 6, 'N');

    // bishops
    makePiece(0, 2, 'b');
    makePiece(0, 5, 'b');
    makePiece(7, 2, 'B');
    makePiece(7, 5, 'B');

    // kings
    makePiece(0, 4, 'k');
    makePiece(7, 4, 'K');

    // queens
    makePiece(0, 3, 'q');
    makePiece(7, 3, 'Q');
}

void Board::resetBoard() {
    // empty squares
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                makePiece(i, j, ' ');
            } else {
                makePiece(i, j, '_');
            }
        }
    }
}

int Board::evaluate() {
    int whiteTotal = 0, blackTotal = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((arr[i][j]->returnPlayer()) == Colour::WHITE) whiteTotal += arr[i][j]->pointValue();
            else blackTotal += arr[i][j]->pointValue();
        }
    }
    return whiteTotal - blackTotal;
}

int Board::getNumMoves() {
    return movesMade.size();
}

Move Board::lastMove() {
    Move m;
    if (movesMade.size() == 0) return m;
    m = movesMade.back();
    return m;
}
