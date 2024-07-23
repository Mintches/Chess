#include "subject.h"
using namespace std;

void Subject::attach(Observer *o) { observer.push_back(o); }

void Subject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();) {
      if (*it == o) it = observers.erase(it);
      else ++it;
    }
}

void Subject::notifyObservers() { for (auto o : observer) o->notify(); }
