#include ".../subject.h"
using namespace std;

class Observer {
    virtual Subject *sub;
    public:
        virtual void notify();
        virtual ~Observer();
};