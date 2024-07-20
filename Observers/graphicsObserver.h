#include "window.h"
using namespace std;

class GraphicsObserver : public Observer{
    XWindow w;
    Subject *sub;
    public:
        GraphicsObserver(Subject *sub);
        void notify() override;
        ~GraphicsObserver() override;
}