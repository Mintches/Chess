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
            arr[i][j] = Blank();
        }
    }
}

vector<string> Board::possibleMoves() {}

Square Board::checkSquare(int row, int col) {}

bool Board::verifyCheck(int player) {}

bool Board::verifyCheckmate(int player) {}

bool Board::verifyStalemate(int player) {}

bool Board::verifyMove(int player) {}

bool Board::movePiece(string move, int player) {}

void Board::makePiece(int row, int col, int piece) {
    if (piece == 'p') arr[row][col] = Pawn(row, col, 2);
    else if (piece == 'n') arr[row][col] = Knight(row, col, 2);
    else if (piece == 'b') arr[row][col] = Bishop(row, col, 2);
    else if (piece == 'k') arr[row][col] = King(row, col, 2);
    else if (piece == 'q') arr[row][col] = Queen(row, col, 2);
    else if (piece == 'r') arr[row][col] = Rook(row, col, 2);
    else if (piece == 'P') arr[row][col] = Pawn(row, col, 1);
    else if (piece == 'N') arr[row][col] = Knight(row, col, 1);
    else if (piece == 'B') arr[row][col] = Bishop(row, col, 1);
    else if (piece == 'K') arr[row][col] = King(row, col, 1);
    else if (piece == 'Q') arr[row][col] = Queen(row, col, 1);
    else if (piece == 'R') arr[row][col] = Rook(row, col, 1);
}

void Board::deletePiece(int row, int col) {
    arr[row][col] = EmptySquare();
}
