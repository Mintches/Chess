#include "boardIterator.h"
#include "board.h"

BoardIterator::BoardIterator( Board board): Board{board}, currCol{0}, currRow{0} {}

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
    if (currCol < 8) {
        ++currCol;
    } else (currRow < 8) { // move to next row
        ++currRow;
        currCol = 0;
    } // TODO: what happens once everything is looped through?
    return *this;
} // remove 8?
