#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <memory>
using namespace std;

class Square; // forward declaration

class Move {
    vector<shared_ptr<Square>> deleted;
    vector<shared_ptr<Square>> added;
    bool check; 
    bool stalemate;
    public:
        Move();
        Move(vector<shared_ptr<Square>> deleted, vector<shared_ptr<Square>> added, bool check, bool stalemate);
        vector<shared_ptr<Square>> getDeleted();
        vector<shared_ptr<Square>> getAdded();
        void addDeleted(shared_ptr<Square> s);
        void addAdded(shared_ptr<Square> s);
        bool getCheck();
        bool getStalemate();
        void setCheck(bool t);
        void setStalemate(bool t);
        bool isEmpty();
};

#endif