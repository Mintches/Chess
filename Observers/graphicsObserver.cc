#include "graphicsObserver.h"
using namespace std;

GraphicsObserver::GraphicsObserver(Subject *sub): w{Xwindow(1000, 1000)}, sub{sub} {}

void GraphicsObserver::notify() {
    w.fillRectangle(0, 0, 100, 100, Xwindow::Red);
}

GraphicsObserver::~GraphicsObserver() {}