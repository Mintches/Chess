#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

#include "colour.h"
#include "boardIterator.h"
#include "square.h"

using namespace std;

class Board {
    vector<string> movesMade;
    Square *arr[8][8];
    public:
        Board();
        vector<string> possibleMoves();
        Square *getSquare(int row, int col);
        bool verifyCheck(Colour player);
        bool verifyCheckmate(Colour player);
        bool verifyStalemate(Colour player);
        bool verifyDraw();
        bool verifyMove(Colour player);
        bool movePiece(string move, Colour player);
        BoardIterator begin();
        BoardIterator end();
        void makePiece(int row, int col, int piece);
        void deletePiece(int row, int col);
};

#endif