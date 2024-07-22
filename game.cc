#include <iostream>
#include "game.h"
#include "board.h"
#include "pieceType.h"
#include "Players/player.h"

Game::Game(Player *player1, Player *player2): gameHistory{}, state{0}, player1Score{0}, player2Score{0}, player1{player1}, player2{player2}, currPlayer{player1}, currentBoard{Board()} {}

void Game::setupGame() {
    // chess board has letters left to right (a, b, c, d, e, f, g, h)
    // chess board has numbers bottom up (1, 2, 3, 4, 5, 6, 7, 8)
    cout << "hi" << endl;
    // lowercase = black
    // uppercase = white
    string op;
    //Board b = Board();
    //currentBoard = b;
    while (cin >> op) {
        if (op == "done") break;
        else if (op == "+") { // add piece to square
            char p;
            string sq;
            cin >> p >> sq;
            // parse input into row and col
            char rank = sq[0];
            int row = 8 - ((int) sq[1] - '0'); 
            int col = (int) rank  - 97;
            currentBoard.makePiece(row, col, p);
            if (currentBoard.getSquare(row, col)->returnType() == PieceType::EMPTY) cout << "why\n";
            else cout << "ok\n";
        } else if (op == "-") { // delete piece on square
            string sq;
            cin >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = 8 - ((int) sq[1] - '0'); 
            int col = (int) rank  - 97;
            currentBoard.deletePiece(row, col);
        } else { // set player colour to go first
            string colour;
            cin >> colour;
            if (colour == "white") setPlayer(1);
            else setPlayer(2);
        }
        printBoard();
    }
}

void Game::playGame() {}

void Game::endGame() {}

void Game::printScore() {}

void Game::addScore(int player) {}

void Game::setPlayer(int player) {
    if (player == 1) currPlayer = player1;
    else currPlayer = player2;
}

char Game::getState(int row, int col) {
    return 'a';
}

void Game::printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            PieceType curPiece = currentBoard.getSquare(i, j)->returnType();
            if (curPiece == PieceType::KING) cout << "k";
            else if (curPiece == PieceType::QUEEN) cout << "q";
            else if (curPiece == PieceType::PAWN) cout << "p";
            else if (curPiece == PieceType::BISHOP) cout << "b";
            else if (curPiece == PieceType::ROOK) cout << "r";
            else if (curPiece == PieceType::KNIGHT) cout << "n";
            else cout << ".";
        }
        cout << "\n";
    }
}