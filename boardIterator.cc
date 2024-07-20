#include "boardIterator.h"
#include "board.h"

BoardIterator::BoardIterator( Board board): Board{Board}, currCol{0}, currRow{0} {}

BoardIterator::~BoardIterator() {
    delete Board;
}

bool BoardIterator::operator!=( const BoardIterator& other ) const {
    return board != other.board || currRow != other.currRow || currCol != other.currCol;
}

bool BoardIterator::operator==( const BoardIterator& other ) const {
    return board == other.board && currRow == other.currRow && currCol == other.currCol;
}

Square* BoardIterator::operator*() const {
    return board.grid[currCol][currRow];
}

BoardIterator& BoardIterator::operator++() {
    if (currCol < BOARD_DIMENSION) {
        ++currCol;
    } else (currRow < BOARD_DIMENSION) { // move to next row
        ++currRow;
        currCol = 0;
    } // TODO: what happens once everything is looped through?
    return *this;
}
