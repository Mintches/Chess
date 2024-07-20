#include "board.h"
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

void Board::makePiece(Square piece, int row, int col) {
    arr[row][col] = piece;
}

void Board::deletePiece(int row, int col) {
    arr[row][col] = Blank();
}
