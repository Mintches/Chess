#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <memory>
using namespace std;

class Square; // forward declaration

class Move {
    vector<Square *> deleted;
    vector<Square *> added;
    bool check; 
    bool stalemate;
    public:
        Move();
        Move(vector<Square *> deleted, vector<Square *> added, bool check, bool stalemate);
        vector<Square *> getDeleted();
        vector<Square *> getAdded();
        void addDeleted(Square *s);
        void addAdded(Square *s);
        bool getCheck();
        bool getStalemate();
        void setCheck(bool t);
        void setStalemate(bool t);
        bool isEmpty();
};

#endif