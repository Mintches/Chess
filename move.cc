#include "move.h"
#include "square.h"

Move::Move(): to{nullptr}, from{nullptr}, captured{nullptr}, check{false}, stalemate{false} {}

Move::Move(Square *to, Square *from, Square *captured, bool check, bool stalemate): to{to}, from{from}, captured{captured}, check{check}, stalemate{stalemate} {}

Square *Move::getTo() { return to; }

Square *Move::getFrom() { return from; }

Square *Move::getCaptured() { return captured; }

bool Move::getCheck() { return check; }

bool Move::getStalemate() { return stalemate; }

void Move::setCheck(bool t) { check = t; }

void Move::setStalemate(bool t) { stalemate = t; }