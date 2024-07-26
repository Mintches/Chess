#include "subject.h"
#include "Observers/observer.h"
using namespace std;

void Subject::attach(Observer *o) { observers.push_back(o); }

void Subject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();) {
      if (*it == o) it = observers.erase(it);
      else ++it;
    }
}

void Subject::notifyObserversFull() { for (auto o : observers) o->notifyFull(); }

void Subject::notifyObserversChange(Move m) { for (auto o : observers) o->notifyChange(m); }
