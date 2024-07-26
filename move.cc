#include "move.h"
#include "square.h"

Move::Move() {
    check = false;
    passantable = {-1, -1};
}

/*Move::Move(vector<shared_ptr<Square>> deleted, vector<shared_ptr<Square>> added, bool check, bool stalemate): deleted{deleted}, added{added}, check{check}, stalemate{stalemate} passantable{make_pair{-1, -1}} {}*/

vector<shared_ptr<Square>> Move::getDeleted() { return deleted; }

vector<shared_ptr<Square>> Move::getAdded() { return added; }

void Move::addDeleted(shared_ptr<Square> s) { deleted.push_back(s); }

void Move::addAdded(shared_ptr<Square> s) { added.push_back(s); }

bool Move::getCheck() { return check; }

void Move::setCheck(bool t) { check = t; }

bool Move::isEmpty() {
    if (deleted.size() == 0 && added.size() == 0) return true;
    return false;
}

pair<int,int> Move::getPassantable() { return passantable; }
void Move::setPassantable(int row, int col) {
    passantable = {row, col};
};
//void Move::removePassantable()
