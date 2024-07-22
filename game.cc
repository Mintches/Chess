#include <iostream>
#include "game.h"
#include "board.h"
#include "pieceType.h"
#include "Players/player.h"
#include "move.h"
#include "input.h"
#include "Observers/textObserver.h"

Game::Game(Player *player1, Player *player2): gameHistory{}, state{0}, player1Score{0}, player2Score{0}, player1{player1}, player2{player2}, currPlayer{player1}, currentBoard{Board()} {}

void Game::setupGame() {
    // chess board has letters left to right (a, b, c, d, e, f, g, h)
    // chess board has numbers bottom up (1, 2, 3, 4, 5, 6, 7, 8)
    // lowercase = black
    // uppercase = white
    string op;
    //Board b = Board();
    //currentBoard = b;
    Input inp;
    while (cin >> op) {
        if (op == "done") break;
        else if (op == "+") { // add piece to square
            char p;
            string sq;
            cin >> p;
            // parse input into row and col
            pair<int, int> in = inp.getSquare();
            currentBoard.makePiece(in.first, in.second, p);
        } else if (op == "-") { // delete piece on square
            pair<int, int> in = inp.getSquare();
            currentBoard.deletePiece(in.first, in.second);
        } else { // set player colour to go first
            string colour;
            cin >> colour;
            if (colour == "white") setPlayer(Colour::WHITE);
            else setPlayer(Colour::BLACK);
        }
        printBoard();
    }
}

void Game::playGame() {
    /*if (currentBoard.verifyMove(mv)) {
        currentBoard.movePiece(mv);
    }*/
   return;
    
}

void Game::endGame() {}

void Game::printScore() {
    cout << "Final score:" << endl;
    cout << "White: " << player1Score << endl;
    cout << "Black: " << player2Score << endl;
}

void Game::addScore(Colour player) {}

void Game::setPlayer(Colour player) {
    if (player == Colour::WHITE) currPlayer = player1;
    else currPlayer = player2;
}

char Game::getState(int row, int col) {
    PieceType curPiece = currentBoard.getSquare(row, col)->returnType();
    if (curPiece == PieceType::KING) return 'k';
    else if (curPiece == PieceType::QUEEN) return 'q';
    else if (curPiece == PieceType::PAWN) return 'p';
    else if (curPiece == PieceType::BISHOP) return 'b';
    else if (curPiece == PieceType::ROOK) return 'r';
    else if (curPiece == PieceType::KNIGHT) return 'n';
    else return '.';
}

void Game::printBoard() {
    TextObserver *to = new TextObserver{this};
    to->notify();
}