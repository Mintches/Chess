#include "move.h"
#include "square.h"

Move::Move() {}

Move::Move(vector<Square *> deleted, vector<Square *> added, bool check, bool stalemate): deleted{deleted}, added{added}, check{check}, stalemate{stalemate} {}

vector<Square *> Move::getDeleted() { return deleted; }

vector<Square *> Move::getAdded() { return added; }

void Move::addDeleted(Square *s) { deleted.push_back(s); }

void Move::addAdded(Square *s) { added.push_back(s); }

bool Move::getCheck() { return check; }

bool Move::getStalemate() { return stalemate; }

void Move::setCheck(bool t) { check = t; }

void Move::setStalemate(bool t) { stalemate = t; }

bool Move::isEmpty() {
    if (deleted.size() == 0 && added.size() == 0) return true;
    return false;
}