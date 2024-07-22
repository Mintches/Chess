#include <iostream>

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

vector<string> Board::possibleMoves() {
    vector<string> s;
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

bool Board::verifyMove(Colour player) {
    if (verifyCheck(player)) {
        return false;
    } else {
        return true;
    }
}

bool Board::movePiece(string move, Colour player) { // do move yep
    return true;
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
