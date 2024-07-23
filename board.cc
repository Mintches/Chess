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
#include "Pieces/emptysquare.h"
#include "colour.h"

using namespace std;

Board::Board() {
    Colour player;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                player = Colour::WHITE;
            } else {
                player = Colour::BLACK;
            }
            arr[i][j] = new EmptySquare(i, j, player);
        }
    }
}

vector<Move> Board::possibleMoves(Colour player) {
    vector<Move> s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            vector<pair<int, int>> v = arr[i][j]->possibleMoves(this);
        }
    }
    return s;
}

Square *Board::getSquare(int row, int col) {
    return arr[row][col]; // TODO: check the row and col are valid
}

bool Board::verifyCheck(Colour player) {
    int kingRow = 0; // placeholders
    int kingCol = 0;
    for (auto sq : possibleMoves())
            if (getSquare(i, j)->verifyMove(this, kingRow, kingCol)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::verifyCheckmate(Colour player) { // if no possible moves for other player
    return true;
}

bool Board::verifyStalemate(Colour player) { // if no possible moves for current player
    return true;
}

/*bool Board::verifyMove(Colour player, int row1, int col1, int row2, int col2) {
    if (verifyCheck(player)) {
        return false;
    } else {
        return true;
    }
}*/

bool Board::movePiece(Colour player, int row1, int col1, int row2, int col2) {
    if (arr[row1][col1]->verifyMove(this, row2, col2) == false) return false;
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
    }

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
    for (auto deletedSq : latestMv.getDeleted()) {
        // restore deleted
        makePiece(deletedSq->getRow(),deletedSq->getCol(), 'p'); // fix makePiece
    }
    for (auto addedSq : latestMv.getAdded()) {
        // remove added
        deletePiece(addedSq->getRow(),addedSq->getCol()); // fix makePiece
    }
    movesMade.pop_back();
}
