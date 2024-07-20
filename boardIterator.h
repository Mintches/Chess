#ifndef BOARD_ITERATOR_H
#define BOARD_ITERATOR_H

#include "board.h"
#include "square.h"

class BoardIterator {
    Board board;
    int currRow;
    int currCol;

    public:
        bool operator!=( const BoardIterator& ) const;
        bool operator==( const BoardIterator& ) const;
        Square* operator*() const;
        BoardIterator& operator++();
}

#endif
