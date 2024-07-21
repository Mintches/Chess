#include <iostream>
#include "game.h"
#include "Players/player.h"

Game::Game(Player *player1, Player *player2) player1{player1}, player2{player2}, currPlayer{player1} {}

void Game::setupGame() {
    string op;
    while (cin >> op) {
        if (op == "done") break;
        else if (op == "+") { // add piece to square
            char p;
            string sq;
            cin >> p >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = (int) sq[1] - '0'
        } else if (op == "-") { // delete piece on square
            string sq;
            cin >> sq;
            // parse input into rank and row
            char rank = sq[0];
            int row = (int) sq[1] - '0'
        } else { // set player colour to go first
            string colour;
            cin >> colour;
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