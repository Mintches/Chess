#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

#include "colour.h"
#include "boardIterator.h"
#include "square.h"
#include "move.h"

using namespace std;

class Board {
    vector<Move> movesMade;
    Square *arr[8][8];
    pair<int,int> passantable;
    public:
        Board();
        vector<Move> possibleMoves(Colour player);
        Square *getSquare(int row, int col);
        bool verifyCheck(Colour player);
        bool verifyCheckmate(Colour player);
        bool verifyStalemate(Colour player);
        bool verifyDraw();
        //bool verifyMove(Colour player, int row1, int col1, int row2, int col2);
        void movePiece(Move m);
        BoardIterator begin();
        BoardIterator end();
        void makePiece(int row, int col, char piece);
        void deletePiece(int row, int col);
        void undoMove();
        pair<int,int> returnPassantable();
        void removePassantable();
        void standardBoard();
        void resetBoard();
};

#endif
