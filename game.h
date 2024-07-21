#include "board.h"
#include "Players/player.h"
using namespace std;

class Game : public Subject {
    vector<Board> gameHistory;
    int state;
    int player1Score = 0;
    int player2Score = 0;
    Player *player1;
    Player *player2;
    Player *currPlayer;
    Board currentBoard;
    public:
        Game(Player player1, Player player2);
        void setupGame();
        void playGame();
        void endGame();
        void printScore();
        void addScore(int player);
        void setPlayer(int player);
        char getState(int row, int col) override;
        void printBoard();
}