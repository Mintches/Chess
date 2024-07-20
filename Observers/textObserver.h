#include "observer.h"
using namespace std;

class TextObserver : public Observer {
    public:
        TextObserver(Subject *sub);
        void notify() override;
        ~TextObserver() override;
}