#include "board.h"
using namespace std;

vector<string> Board::possibleMoves() {}

Square Board::checkSquare(int row, int col) {}

bool Board::verifyCheck(int player) {}

bool Board::verifyCheckmate(int player) {}

bool Board::verifyStalemate(int player) {}

bool Board::verifyMove(int player) {}

bool Board::movePiece(string move, int player) {}

BoardIterator Board::begin() {}

BoardIterator Board::end() {}

void Board::makePiece(Square piece, int row, int col) {}

void Board::deletePiece(Square piece) {}
