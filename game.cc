#include <iostream>
#include "game.h"
#include "board.h"
#include "Players/player.h"

Game::Game(Player *player1, Player *player2) player1{player1}, player2{player2}, currPlayer{player1} {}

void Game::setupGame() {
    // chess board has letters left to right
    // chess board has numbers bottom up
    string op;
    int player = 1; // determine player later
    while (cin >> op) {
        if (op == "done") break;
        else if (op == "+") { // add piece to square
            char p;
            string sq;
            cin >> p >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = (int) sq[1] - '0'; // row 1 -> index 7, row 2 -> index 6, row 3 -> index 5
            int col = (int) - 97;
            makePiece(row, col, p, player);
        } else if (op == "-") { // delete piece on square
            string sq;
            cin >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = (int) sq[1] - '0';
            deletePiece(row, col);
        } else { // set player colour to go first
            string colour;
            cin >> colour;
            setPlayer(player);
        }
    }
}

void Game::playGame() {}

void Game::endGame() {}

void Game::printScore() {}

void Game::addScore(int player) {}

char Game::getState(int row, int col) override {
    return 'a';
}