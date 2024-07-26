#include <iostream>
#include "game.h"
#include "board.h"
#include "pieceType.h"
#include "Players/player.h"
#include "move.h"
#include "input.h"
#include "Observers/textObserver.h"

Game::Game(): gameHistory{}, state{0}, player1Score{0}, player2Score{0}, player1{nullptr}, player2{nullptr}, currPlayer{player1}, currentBoard{Board()} {
    currentBoard.standardBoard();
}

void Game::setPlayerTypes(Player *player1, Player *player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->currPlayer = player1;
}

void Game::setupGame() {
    // chess board has letters left to right (a, b, c, d, e, f, g, h)
    // chess board has numbers bottom up (1, 2, 3, 4, 5, 6, 7, 8)
    // lowercase = black
    // uppercase = white
    string op;
    //Board b = Board();
    //currentBoard = b;
    //setCurrPlayer(Colour::WHITE);
    currPlayer = player1;
    Input inp;
    printBoard();
    while (cin >> op) {
        if (op == "done") {
            gameHistory.push_back(currentBoard);
            break;
        }
        else if (op == "+") { // add piece to square
            char p;
            cin >> p;
            // parse input into row and col
            pair<int, int> in = inp.getCoords();
            currentBoard.makePiece(in.first, in.second, p);
        } else if (op == "-") { // delete piece on square
            pair<int, int> in = inp.getCoords();
            currentBoard.deletePiece(in.first, in.second);
        } else if (op == "=") { // set player colour to go first
            string colour;
            cin >> colour;
            if (colour == "white") currPlayer = player1;
            else if (colour == "black") currPlayer = player2;
        }
        else if (op == "reset") currentBoard.resetBoard(); 
        else if (op == "standard") currentBoard.standardBoard();
        else cout << "Invalid Move\n";
        printBoard();
    }
}

void Game::playGame() {
    printBoard();
    string in;
    cout << "Please output 'move' or 'resign':" << endl;
    while (cin >> in) {
        if (in == "resign") {
            swapPlayer();
            cout << getColourString() << " wins!" << endl;
            addScore(getColour(), 1);
            break;
        }
        else if (in == "move") {
            // receive move
            Move mv = currPlayer->getMove(&currentBoard, getColour()); // can this be done if currPlayer is human and doesn't take in the board

            // do move, if possible
            //if (currentBoard.movePiece(mv)) {//getColour(), 1, 1, 2, 2)) { //placeholder, ideally dont be switching between mv and coordinates
                //gameHistory.push_back(currentBoard);
            currentBoard.movePiece(mv);
            if (currentBoard.verifyCheck(getColour())) { // move piece and no self check
                currentBoard = gameHistory.back();
                cout << "Invalid move" << endl;
            } else {
                swapPlayer();
                // going from most requirments to least checkmate > stalemate > check
                if (currentBoard.verifyCheckmate(getColour())) {
                    swapPlayer();
                    cout << "Checkmate! " << getColourString() << " wins!" << endl;
                    addScore(getColour(), 1);
                    break;
                } else if (currentBoard.verifyStalemate(getColour())) {
                    cout << "Stalemate!" << endl;
                    addScore(getColour(), 0.5);
                    swapPlayer();
                    addScore(getColour(), 0.5);
                    break;
                } else if (currentBoard.verifyCheck(getColour())) {
                        cout << getColourString() << " is in check." << endl;
                }
                printBoard();
            }
        }
        cout << "Please output 'move' or 'resign':" << endl;
    }
}

void Game::printScore() {
    cout << "Final score:" << endl;
    cout << "White: " << player1Score << endl;
    cout << "Black: " << player2Score << endl;
}

void Game::addScore(Colour player, float val) {
    if (player == Colour::WHITE) {
        player1Score += val;
    } else {
        player2Score += val;
    }
}

void Game::setCurrPlayer(Colour player) {
    if (player == Colour::WHITE) currPlayer = player1;
    else currPlayer = player2;
}

void Game::swapPlayer() {
    if (currPlayer == player1) currPlayer = player2;
    else currPlayer = player1;
}

Colour Game::getColour() {
    if (currPlayer == player1) return Colour::WHITE;
    else return Colour::BLACK;
}

char Game::getState(int row, int col) {
    PieceType curPiece = currentBoard.getSquare(row, col)->returnType();
    Colour player = currentBoard.getSquare(row, col)->returnPlayer();
    char cap = 0;
    if (player == Colour::WHITE) { // turn it to capital letter if it's white
        cap = 'A' - 'a';
    }
    if (curPiece == PieceType::KING) return 'k' + cap;
    else if (curPiece == PieceType::QUEEN) return 'q' + cap;
    else if (curPiece == PieceType::PAWN) return 'p' + cap;
    else if (curPiece == PieceType::BISHOP) return 'b' + cap;
    else if (curPiece == PieceType::ROOK) return 'r' + cap;
    else if (curPiece == PieceType::KNIGHT) return 'n' + cap;
    else if (curPiece == PieceType::EMPTY && player == Colour::BLUE) return '_';
    else return ' ';
}

void Game::printBoard() {
    notifyObservers();
}

string Game::getColourString() {
    if (getColour() == Colour::WHITE) {
        return "White";
    } else {
        return "Black";
    }
}
