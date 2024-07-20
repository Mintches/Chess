#include "subject.h"
using namespace std;

void Subject::attach(Observer *o);

void Subject::detach(Observer *o);

void Subject::notifyObservers();
