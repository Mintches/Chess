#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <memory>

#include "colour.h"
#include "boardIterator.h"
#include "square.h"
#include "move.h"

using namespace std;

class Board {
    vector<Move> movesMade;
    shared_ptr<Square> arr[8][8];
    int numMoves = 0;
    public:
        Board();
        Board(const Board& b);
        vector<Move> legalMoves(Colour player);
        bool checkLegal(Move m, Colour player);
        shared_ptr<Square> getSquare(int row, int col);
        bool verifyCheck(Colour player);
        bool verifyCheckmate(Colour player);
        bool verifyStalemate(Colour player);
        bool verifySetup();
        bool movePiece(Move m);
        BoardIterator begin();
        BoardIterator end();
        void makePiece(int row, int col, char piece);
        void deletePiece(int row, int col);
        void undoMove();
        void standardBoard();
        void resetBoard();
        int evaluate();
        int getNumMoves();
        void incNumMoves();
        Move lastMove();
};

#endif
