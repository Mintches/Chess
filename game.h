#include "board.h"
#include "subject.h"
using namespace std;

class Player; // forward declaration

class Game : public Subject {
    vector<Board> gameHistory;
    int state = 0;
    int player1Score = 0;
    int player2Score = 0;
    Player *player1;
    Player *player2;
    Player *currPlayer;
    Board currentBoard;
public:
    Game();
    void setPlayerTypes(Player *player1, Player *player2);
    void setupGame();
    void playGame();
    void printScore();
    void addScore(Colour player);
    void setPlayer(Colour player);
    char getState(int row, int col) override;
    void printBoard();
    Board standardBoard();
};