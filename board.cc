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

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = new EmptySquare(i, j, 0);
        }
    }
}

vector<string> Board::possibleMoves() {
    vector<string> s;
    return s;
}

Square *Board::checkSquare(int row, int col) {
    return arr[row][col];
}

bool Board::verifyCheck(int player) {
    return true;
}

bool Board::verifyCheckmate(int player) {
    return true;
}

bool Board::verifyStalemate(int player) {
    return true;
}

bool Board::verifyMove(int player) {
    return true;
}

bool Board::movePiece(string move, int player) {
    return true;
}

void Board::makePiece(int row, int col, int piece) {
    if (piece == 'p') arr[row][col] = new Pawn(row, col, 2);
    else if (piece == 'n') arr[row][col] = new Knight(row, col, 2);
    else if (piece == 'b') arr[row][col] = new Bishop(row, col, 2);
    else if (piece == 'k') arr[row][col] = new King(row, col, 2);
    else if (piece == 'q') arr[row][col] = new Queen(row, col, 2);
    else if (piece == 'r') arr[row][col] = new Rook(row, col, 2);
    else if (piece == 'P') arr[row][col] = new Pawn(row, col, 1);
    else if (piece == 'N') arr[row][col] = new Knight(row, col, 1);
    else if (piece == 'B') arr[row][col] = new Bishop(row, col, 1);
    else if (piece == 'K') arr[row][col] = new King(row, col, 1);
    else if (piece == 'Q') arr[row][col] = new Queen(row, col, 1);
    else if (piece == 'R') arr[row][col] = new Rook(row, col, 1);
}

void Board::deletePiece(int row, int col) {
    arr[row][col] = new EmptySquare(row, col, 0);
}
