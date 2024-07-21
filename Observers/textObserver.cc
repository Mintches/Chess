#include "textObserver.h"
using namespace std;

TextObserver::TextObserver(Subject *sub): sub{sub} {}

void TextObserver::notify() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << sub->getState(i, j);
        }
        cout << endl;
    }
}
