#include "textObserver.h"
using namespace std;

TextObserver::TextObserver(Subject *sub): sub{sub} {}

void TextObserver::notify() {
    // add vertical border of numbers
    int vertBorder = 0;
    for (int i = 0; i < 8; ++i) {
        ++vertBorder;
        cout << vertBorder;
        for (int j = 0; j < 8; ++j) {
            cout << sub->getState(i, j);
        }
        cout << endl;
    }
    // add horizontal border of letters
    for (int i = 'a'; i <= 'h'; ++i) {
        char horBorder = i;
        cout << horBorder;
    }
    cout << endl;
}
