#include <vector>
using namespace std;

class Square; // forward declaration

class Move {
    Square *to;
    Square *from;
    Square *captured;
    bool check; 
    bool stalemate;
    public:
        Square *getTo();
        Square *getFrom();
        Square *getCaptured();
        bool getCheck();
        bool getStalemate();
        void setCheck(bool t);
        void setStalemate(bool t);
}