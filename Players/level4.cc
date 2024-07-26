#include <string>
#include <algorithm>
#include "computer.h"
#include "level4.h"
using namespace std;

// left to fix: minimax should work on a copy of the board each turn instead of the actual board, otherwise not const

const int INF = 9999999;

// minimax heuristic = sums of the values of all pieces for each player
// maximizing player = white
// minimizing player = black
// evaluate: return weighted sum of pieces from white (mx player) - same thing from black (min player)

void printBoard(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board->getSquare(i, j)->pointValue() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int minimax(Board *board, int depth, int alpha, int beta, bool mxPlayer) {
    // minimax has reached a leaf node
    if (depth == 0 || board->verifyCheckmate(Colour::WHITE) || board->verifyCheckmate(Colour::BLACK) || 
    board->verifyStalemate(Colour::WHITE) || board->verifyStalemate(Colour::BLACK)) return board->evaluate();
    
    if (mxPlayer) { // maximizing player (white)
        int mxEval = -INF;
        for (auto m: board->legalMoves(Colour::WHITE)) {
            board->movePiece(m); // test move and continue traversing the search tree
            int eval = minimax(board, depth - 1, alpha, beta, false); // call minimax with minimizing player on next depth
            board->undoMove(); // undo the move to try other moves
            //printBoard(board);
            mxEval = max(mxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) break; // alpha-beta pruning to cut off paths that def won't be useful
        }
        return mxEval;
    } else { // minimizing player (black)
        int minEval = INF;
        for (auto m: board->legalMoves(Colour::BLACK)) {
            board->movePiece(m); 
            int eval = minimax(board, depth - 1, alpha, beta, true); // call minimax with maximizing player on next depth
            board->undoMove();
            //printBoard(board);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

Move Level4::getMove(Board *board, Colour player) const {
    Move bestMv;
    if (player == Colour::WHITE) {
        int mxEval = -INF;
        for (auto m: board->legalMoves(player)) {
            board->movePiece(m);
            int eval = minimax(board, 1, -INF, INF, false);
            board->undoMove();
            if (eval > mxEval) {
                mxEval = eval;
                bestMv = m;
            }
        }
    } else {
        int minEval = INF;
        for (auto m: board->legalMoves(player)) {
            board->movePiece(m);
            int eval = minimax(board, 1, -INF, INF, true);
            board->undoMove();
            if (eval < minEval) {
                minEval = eval;
                bestMv = m;
            }
        }
    }
    return bestMv;
}


/*string Level4::getMove(Board *board, int depth) const {
    return ""; // placeholder so it doesn't crash
}*/

/*
Move Level4::getMove(Board *board, Colour player) const {
    vector<Move> v = board->legalMoves();
    return v.back(); // placeholder so it doesn't crash
}
*/