#include <vector>

#include "Observers/observer.h"

using namespace std;

class Subject {
    vector<Observer*> observer;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyObservers();
        virtual char getState(int row, int col) = 0;
};