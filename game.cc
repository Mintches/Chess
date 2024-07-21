#include <iostream>
#include "game.h"
#include "board.h"
#include "Players/player.h"

Game::Game(Player *player1, Player *player2) player1{player1}, player2{player2}, currPlayer{player1} {}

void Game::setupGame() {
    // chess board has letters left to right (a, b, c, d, e, f, g, h)
    // chess board has numbers bottom up (1, 2, 3, 4, 5, 6, 7, 8)
    // lowercase = black
    // uppercase = white
    string op;
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
            makePiece(row, col, p, player);
        } else if (op == "-") { // delete piece on square
            string sq;
            cin >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = 8 - ((int) sq[1] - '0'); 
            int col = (int) rank  - 97;
            deletePiece(row, col);
        } else { // set player colour to go first
            string colour;
            cin >> colour;
            if (colour == "white") setPlayer(1);
            else setPlayer(2);
        }
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

char Game::getState(int row, int col) override {
    return 'a';
}