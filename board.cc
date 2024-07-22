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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = new EmptySquare(i, j, Colour::WHITE);
        }
    }
}

vector<Move> Board::possibleMoves(Colour player) {
    vector<Move> s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            vector<pair<int, int>> v = arr[i][j].possibleMoves();
        }
    }
    return s;
}

Square *Board::getSquare(int row, int col) {
    return arr[row][col]; // TODO: check the row and col are valid
}
 
bool Board::verifyCheck(Colour player) {
    int kingRow;
    int kingCol;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
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

bool Board::movePiece(Colour player, int row1, int col1, int row2, int col2) { // do move yep
    if (arr[row1][col1]->verifyMove(this, row2, col2) == false) return false;
    Move m{arr[row1][col1], nullptr, arr[row2][col2], false, false};
    arr[row2][col2] = arr[row1][col1];
    arr[row1][col1] = new EmptySquare(row1, row2, Colour::WHITE);
    if (verifyCheck(player)) {

    }
    else {
        if (player == Colour::WHITE) {
            if (verifyCheck(Colour::BLACK)) m.setCheck() = true;
            if (verifyStalemate(Colour::BLACK)) m.setStalemate() = true;
        }
        else {
            if (verifyCheck(Colour::WHITE)) m.setCheck() = true;
            if (verifyStalemate(Colour::WHITE)) m.setStalemate() = true;
        }
        movesMade.push_back(m);
        return true;
    }

}

void Board::makePiece(int row, int col, int piece) {
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
}

void Board::deletePiece(int row, int col) {
    arr[row][col] = new EmptySquare(row, col, Colour::WHITE);
}

void Board::undoMove() {
    if (movesMade.size() == 0) return;
    

}
