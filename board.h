#include <string>

#include "square.h"

using namespace std;

public Board {
    vector<string> movesMade;
    Square arr[8][8];
    public:
        vector<string> possibleMoves();
        Square checkSquare(int row, int col);
        bool verifyCheck(int player);
        bool verifyCheckmate(int player);
        bool verifyStalemate(int player);
        bool verifyMove(int player);
        bool movePiece(string move, int player);
        BoardIterator begin();
        BoardIterator end();
        void makePiece(Square piece, int row, int col);
        void deletePiece(Square piece)
}