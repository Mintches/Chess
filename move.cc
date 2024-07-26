#include "move.h"
#include "square.h"

Move::Move() {}

Move::Move(vector<shared_ptr<Square>> deleted, vector<shared_ptr<Square>> added, bool check, bool stalemate): deleted{deleted}, added{added}, check{check}, stalemate{stalemate} {}

vector<shared_ptr<Square>> Move::getDeleted() { return deleted; }

vector<shared_ptr<Square>> Move::getAdded() { return added; }

void Move::addDeleted(shared_ptr<Square> s) { deleted.push_back(s); }

void Move::addAdded(shared_ptr<Square> s) { added.push_back(s); }

bool Move::getCheck() { return check; }

bool Move::getStalemate() { return stalemate; }

void Move::setCheck(bool t) { check = t; }

void Move::setStalemate(bool t) { stalemate = t; }

bool Move::isEmpty() {
    if (deleted.size() == 0 && added.size() == 0) return true;
    return false;
}