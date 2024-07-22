#include "move.h"
#include "square.h"

Square *Move::getTo() { return to; }

Square *Move::getFrom() { return from; }

Square *Move::getToFrom() { return toFrom; }

Square *Move::getCaptured() { return captured; }