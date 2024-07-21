#include "observer.h"
#include "../subject.h"
#include <iostream>
using namespace std;

class TextObserver : public Observer {
    Subject *sub;
    public:
        TextObserver(Subject *sub);
        void notify() override;
};
