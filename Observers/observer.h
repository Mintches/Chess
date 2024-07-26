#ifndef OBSERVER_H
#define OBSERVER_H

#include "../move.h"

using namespace std;

class Observer {
    public:
        virtual void notifyFull() = 0;
        virtual void notifyChange(Move m) = 0;
        virtual ~Observer() = default;
};

#endif
