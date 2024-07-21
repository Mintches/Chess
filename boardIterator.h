#ifndef BOARD_ITERATOR_H
#define BOARD_ITERATOR_H

#include "square.h"

class Board; // forward declaration

class BoardIterator {
    Board *board;
    int currRow;
    int currCol;

    public:
        BoardIterator(Board *board);
        bool operator!=( const BoardIterator& ) const;
        bool operator==( const BoardIterator& ) const;
        Square *operator*() const;
        BoardIterator& operator++();
};

#endif
