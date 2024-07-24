#include <iostream>
#include "game.h"
#include "board.h"
#include "pieceType.h"
#include "Players/player.h"
#include "move.h"
#include "input.h"
#include "Observers/textObserver.h"

Game::Game(): gameHistory{}, state{0}, player1Score{0}, player2Score{0}, player1{nullptr}, player2{nullptr}, currPlayer{nullptr}, currentBoard{Board()} {}

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
        printBoard();
    }
}

void Game::playGame() {
    if (gameHistory.empty()) {
        Board b = standardBoard();
        gameHistory.push_back(b);
        currentBoard = b;
        printBoard();
    }
    string in;
    while (cin >> in) {
        if (in == "resign") {
            gameHistory.push_back(currentBoard);
            swapPlayer();
            cout << getColourString() << " wins!" << endl;
            addScore(getColour(), 0.5);
            break;
        } 
        else if (in == "move") {
            // receive move
            Move mv = currPlayer->getMove(&currentBoard, getColour()); // can this be done if currPlayer is human and doesn't take in the board

            // do move, if possible
            if (currentBoard.movePiece(mv)) {//getColour(), 1, 1, 2, 2)) { //placeholder, ideally dont be switching between mv and coordinates
                gameHistory.push_back(currentBoard);
                swapPlayer();
                currentBoard.movePiece(mv);

                // in case of checkmate, stalemate, or check
                if (currentBoard.verifyCheckmate(getColour())) {
                    cout << "Checkmate! " << getColourString() << " wins!" << endl;
                    addScore(getColour(), 1);
                    break;
                } else if (currentBoard.verifyStalemate(getColour())) {
                    cout << "Stalemate!" << endl;
                    addScore(getColour(), 1);
                    break;
                } else if (currentBoard.verifyCheck(getColour())) {
                    cout << getColourString() << " is in check." << endl;
                }
            } else {
                cout << "invalid move" << endl;
            }
        }
        printBoard();
    }
   return;
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
    if (&currPlayer == &player1) currPlayer = player2;
    else currPlayer = player1;
}

Colour Game::getColour() {
    if (&currPlayer == &player1) return Colour::WHITE;
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
    else if (curPiece == PieceType::EMPTY && player == Colour::BLACK) return '_';
    else return ' ';
}

void Game::printBoard() {
    notifyObservers();
}

Board Game::standardBoard() {
    // white plays first
    setCurrPlayer(Colour::WHITE);
    Board b;
    // setup 
    
    // empty squares
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                b.makePiece(i, j, ' ');
            } else {
                b.makePiece(i, j, '_');
            }
        }
    }

    for (int i = 0; i < 8; ++ i) {
        b.makePiece(1, i, 'p');
        b.makePiece(6, i, 'P');
    }
    //rooks
    b.makePiece(0, 0, 'r');
    b.makePiece(0, 7, 'r');
    b.makePiece(7, 0, 'R');
    b.makePiece(7, 7, 'R');

    //knights
    b.makePiece(0, 1, 'n');
    b.makePiece(0, 6, 'n');
    b.makePiece(7, 1, 'N');
    b.makePiece(7, 6, 'N');

    // bishops
    b.makePiece(0, 2, 'b');
    b.makePiece(0, 5, 'b');
    b.makePiece(7, 2, 'B');
    b.makePiece(7, 5, 'B');

    // kings
    b.makePiece(0, 3, 'k');
    b.makePiece(7, 3, 'K');

    // queens
    b.makePiece(0, 4, 'q');
    b.makePiece(7, 4, 'Q');

    return b;
    
} // there's gotta be a better way 

string Game::getColourString() {
    if (getColour() == Colour::WHITE) {
        return "White";
    } else {
        return "Black";
    }
}
