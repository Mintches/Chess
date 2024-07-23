#include "move.h"
#include "square.h"

Move::Move() {}

Move::Move(vector<Square *> deleted, vector<Square *> added, bool check, bool stalemate): deleted{deleted}, added{added}, check{check}, stalemate{stalemate} {}

vector<Square *> Move::getDeleted() { return deleted; }

vector<Square *> Move::getAdded() { return added; }

bool Move::getCheck() { return check; }

bool Move::getStalemate() { return stalemate; }

void Move::setCheck(bool t) { check = t; }

void Move::setStalemate(bool t) { stalemate = t; }