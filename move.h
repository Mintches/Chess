#ifndef MOVE_H
#define MOVE_H

#include <vector>
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
        bool getCheck();
        bool getStalemate();
        void setCheck(bool t);
        void setStalemate(bool t);
};

#endif