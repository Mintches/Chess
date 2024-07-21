#include "graphicsObserver.h"
using namespace std;

GraphicsObserver::GraphicsObserver(Subject *sub): w{Xwindow(1000, 1000)}, sub{sub} {}

void GraphicsObserver::notify() {}

GraphicsObserver::~GraphicsObserver() {}