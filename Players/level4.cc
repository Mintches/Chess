#include <string>
#include <algorithm>
#include "computer.h"
#include "level4.h"
using namespace std;

const int INF = 9999999;

// minimax heuristic = sums of the values of all pieces for each player
// maximizing player = white
// minimizing player = black
// eval: return weighted sum of pieces from white (mx player) - same thing from black (min player)
// maybe minimax should work on a copy of the board each turn instead of the actual board

int minimax(Board board, int depth, int alpha, int beta, bool mxPlayer) {
    // minimax has reached a leaf node
    if (verifyCheckmate(Colour::WHITE) || verifyCheckmate(Colour::BLACK) || 
    verifyStalemate(Colour::WHITE) || verifyStalemate(Colour::BLACK) || verifyDraw() || depth == 0) return board.evaluate();
    
    if (mxPlayer) { // maximizing player
        int mxEval = -INF;
        vector<Move> allMoves = board.possibleMoves(Colour::WHITE);
        for (auto m: allMoves) {
            board.makeMove(m); // test move and continue traversing the search tree
            int eval = minimax(board, depth - 1, alpha, beta, false); // call minimax with minimizing player on next depth
            board.undoMove(m); // undo the move to try other moves
            mxEval = max(mxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) break; // alpha-beta pruning to cut off paths that def won't be useful
        }
        return mxEval;
    } else { // minimizing player
        int minEval = INF;
        vector<Move> allMoves = board.possibleMoves(Colour::BLACK);
        for (auto m: allMoves) {
            board.makeMove(m); // change to board.movePiece
            int eval = minimax(board, depth - 1, alpha, beta, true); // call minimax with maximizing player on next depth
            board.undoMove(m);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

Move Level4::getMove(Board board, int depth) const {
    Move best;
    int mxEval = -INF;
    vector<Move> allMoves = board.possibleMoves(Colour::WHITE);
    for (auto m: allMoves) {
        board.makeMove(m); // change to  board.movePiece
        int eval = minimax(board, depth - 1, -INF, INF, false);
        board.undoMove(m);
        if (eval > mxEval) {
            mxEval = eval;
            best = m;
        }
    }
    return best;
}

/*string Level4::getMove(Board *board, int depth) const {
    return ""; // placeholder so it doesn't crash
}*/

/*
Move Level4::getMove(Board *board, Colour player) const {
    vector<Move> v = board->possibleMoves(player);
    return v.back(); // placeholder so it doesn't crash
}
*/