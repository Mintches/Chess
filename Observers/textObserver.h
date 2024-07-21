#include "observer.h"
using namespace std;

class Subject; // forward declaration

class TextObserver : public Observer {
    Subject *sub;
    public:
        TextObserver(Subject *sub);
        void notify() override;
        ~TextObserver() override;
};