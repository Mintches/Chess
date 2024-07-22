#ifndef MOVE_H
#define MOVE_H

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
        Move();
        Move(Square *to, Square *from, Square *captured, bool check, bool stalemate);
        Square *getTo();
        Square *getFrom();
        Square *getCaptured();
        bool getCheck();
        bool getStalemate();
        void setCheck(bool t);
        void setStalemate(bool t);
};

#endif