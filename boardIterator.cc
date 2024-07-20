#include "boardIterator.h"

bool operator!=( const BoardIterator& ) const {
    return board != other.board || currRow != other.currRow || currCol != other.currCol;
}

bool operator==( const BoardIterator& ) const {
    return board == other.board && currRow == other.currRow && currCol == other.currCol;
}

Square* operator*() const {
    return board.grid[currCol][currRow];
}

BoardIterator& operator++() {
    if (currCol < BOARD_DIMENSION) {
        ++currCol;
    } else (currRow < BOARD_DIMENSION){ // move to next row
        ++currRow;
        currCol = 0;
    } // TODO: what happens once everything is looped through?
    return *this;
}

#endif
