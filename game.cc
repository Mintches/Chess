#include "game.h"
#include "Players/player.h"

Game::Game(Player *player1, Player *player2) player1{player1}, player2{player2}, currPlayer{player1} {}

void Game::setupGame() {}

void Game::playGame() {}

void Game::endGame() {}

void Game::printScore() {}

void Game::addScore(int player) {}

char Game::getState(int row, int col) override {
    return 'a';
}