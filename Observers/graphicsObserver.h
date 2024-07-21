#include "observer.h"
#include "window.h"

using namespace std;

class Subject; // forward declaration

class GraphicsObserver : public Observer {
    Xwindow w;
    Subject *sub;
    public:
        GraphicsObserver(Subject *sub);
        void notify() override;
        ~GraphicsObserver() override;
};