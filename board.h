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
        Board(const Board& b);
        vector<Move> legalMoves(Colour player);
        Square *getSquare(int row, int col);
        bool verifyCheck(Colour player);
        bool verifyCheckmate(Colour player);
        bool verifyStalemate(Colour player);
        bool movePiece(Move m);
        BoardIterator begin();
        BoardIterator end();
        void makePiece(int row, int col, char piece);
        void deletePiece(int row, int col);
        void undoMove();
        pair<int,int> getPassantable();
        void setPassantable(int row, int col);
        void removePassantable();
        void standardBoard();
        void resetBoard();
        int evaluate();
};

#endif
