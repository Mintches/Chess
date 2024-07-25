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

using namespace std;

Board::Board() {
    passantable = {-1,-1};
}

vector<Move> Board::possibleMoves(Colour player) {
    vector<Move> moves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i][j]->returnPlayer() == player) {
                //vector<pair<int,int>> coords = arr[i][j]->possibleCoords(this);
                //for (auto coord : coords) {
                    Move m = getSquare(i, j)->verifyMove(this, i, j);
                    if (m.getAdded().size() != 0) {
                        moves.push_back(m);
                    }
                //}
            }
        }
    }
    return moves;
}

Square *Board::getSquare(int row, int col) {
    return arr[row][col]; // TODO: check the row and col are valid
}

bool Board::verifyCheck(Colour player) { // is player being checked
    // find king
    int kingRow = -1;
    int kingCol = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (arr[i][j]->returnType() == PieceType::KING && arr[i][j]->returnPlayer() != player) {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
    }
    // see if any pieces could capture king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (arr[i][j]->returnPlayer() != player && (arr[i][j]->verifyMove(this, kingRow, kingCol)).getAdded().size() != 0) {
                return true;
            }
        }
    }
    return false;
}

bool Board::verifyCheckmate(Colour player) { // is player checkmated
    return possibleMoves(player).empty() && verifyCheck(player);
}

bool Board::verifyStalemate(Colour player) { // is player stuck
    return possibleMoves(player).empty();
}

/*bool Board::verifyMove(Colour player, int row1, int col1, int row2, int col2) {
    if (verifyCheck(player)) {
        return false;
    } else {
        return true;
    }
}*/

void Board::movePiece(Move m) {//(Colour player, int row1, int col1, int row2, int col2) {
    for (auto deletedSq : m.getDeleted()) {
        deletePiece(deletedSq->getRow(), deletedSq->getCol());
    }
    for (auto addedSq : m.getAdded()) {
        arr[addedSq->getRow()][addedSq->getCol()] = addedSq;
    }
    movesMade.push_back(m);
    /*if (arr[row1][col1]->verifyMove(this, row2, col2) == false) return false;
    vector<Square *> emptyDeleted;
    vector<Square *> emptyAdded;
    Move m {emptyDeleted, emptyAdded, false, false};
    arr[row2][col2] = arr[row1][col1];
    arr[row1][col1] = new EmptySquare(row1, row2, Colour::WHITE);
    if (verifyCheck(player)) {
        undoMove();
        return false;
    }
    else {
        if (player == Colour::WHITE) {
            if (verifyCheck(Colour::BLACK)) m.setCheck(true);
            if (verifyStalemate(Colour::BLACK)) m.setStalemate(true);
        }
        else {
            if (verifyCheck(Colour::WHITE)) m.setCheck(true);
            if (verifyStalemate(Colour::WHITE)) m.setStalemate(true);
        }
        movesMade.push_back(m);
        return true;
    }*/

}

void Board::makePiece(int row, int col, char piece) {
    if (piece == 'p') arr[row][col] = new Pawn(row, col, Colour::BLACK);
    else if (piece == 'n') arr[row][col] = new Knight(row, col, Colour::BLACK);
    else if (piece == 'b') arr[row][col] = new Bishop(row, col, Colour::BLACK);
    else if (piece == 'k') arr[row][col] = new King(row, col, Colour::BLACK);
    else if (piece == 'q') arr[row][col] = new Queen(row, col, Colour::BLACK);
    else if (piece == 'r') arr[row][col] = new Rook(row, col, Colour::BLACK);
    else if (piece == 'P') arr[row][col] = new Pawn(row, col, Colour::WHITE);
    else if (piece == 'N') arr[row][col] = new Knight(row, col, Colour::WHITE);
    else if (piece == 'B') arr[row][col] = new Bishop(row, col, Colour::WHITE);
    else if (piece == 'K') arr[row][col] = new King(row, col, Colour::WHITE);
    else if (piece == 'Q') arr[row][col] = new Queen(row, col, Colour::WHITE);
    else if (piece == 'R') arr[row][col] = new Rook(row, col, Colour::WHITE);
    else if (piece == '_') arr[row][col] = new EmptySquare(row, col, Colour::BLACK);
    else if (piece == ' ') arr[row][col] = new EmptySquare(row, col, Colour::WHITE);
}

void Board::deletePiece(int row, int col) {
    Colour player= Colour::BLACK;
    if ((row + col) % 2 == 0) {
        player = Colour::WHITE;
    }
    arr[row][col] = new EmptySquare(row, col, player);
}

void Board::undoMove() {
    if (movesMade.size() == 0) return;
    Move latestMv = movesMade.back();
    for (auto addedSq : latestMv.getAdded()) {
        // remove added
        deletePiece(addedSq->getRow(), addedSq->getCol());
    }
    for (auto deletedSq : latestMv.getDeleted()) {
        // restore deleted
        makePiece(deletedSq->getRow(),deletedSq->getCol(), 'p'); // fix makePiece
    }
    movesMade.pop_back();
}

pair<int,int> Board::returnPassantable() {
    return passantable;
}

void Board::removePassantable() {
    passantable = {-1, -1};
}
