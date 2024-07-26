#ifndef SUBJECT_H
#define SUBJECT_H

#include "move.h"

#include <vector>
using namespace std;

class Observer; //forward declaration

class Subject {
    vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyObserversFull();
        void notifyObserversChange(Move m);
        virtual char getState(int row, int col) = 0;
        virtual ~Subject() = default;
};

#endif
