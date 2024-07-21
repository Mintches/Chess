#include "textObserver.h"
using namespace std;

TextObserver::TextObserver(Subject *sub): sub{sub} {}

void TextObserver::notify() {}

TextObserver::~TextObserver() {}