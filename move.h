#include <vector>
using namespace std;

class Square; // forward declaration

class Move {
    Square *to;
    Square *from;
    Square *captured;
    bool check;
    bool checkmate;
    public:
        Square *getTo();
        Square *getFrom();
        Square *getCaptured();
        bool getCheck();
        bool getCheckMate();
}