#include "observer.h"
using namespace std;

Observer::Observer(Subject *sub): sub{sub} {}

void Observer::notify() override {}