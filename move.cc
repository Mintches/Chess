#include "move.h"
#include "square.h"

Square *Move::getTo() { return to; }

Square *Move::getFrom() { return from; }

Square *Move::getCaptured() { return captured; }

bool Move::getCheck() { return check; }

bool Move::getStalemate() { return stalemate; }

void Move::setCheck(bool t) { check = t; }

void Move::setStalemate() { stalemate = t; }