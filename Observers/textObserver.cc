#include "textObserver.h"
using namespace std;

TextObserver::TextObserver(Subject *sub): sub{sub} {}

void TextObserver::notifyFull() {
    // add vertical border of numbers
    int vertBorder = 8;
    for (int i = 0; i < 8; ++i) {
        cout << vertBorder << " ";
        --vertBorder;
        for (int j = 0; j < 8; ++j) {
            cout << sub->getState(i, j) << " ";
        }
        cout << endl;
    }
    // add horizontal border of letters
    cout << "  ";
    for (int i = 'a'; i <= 'h'; ++i) {
        char horBorder = i;
        cout << horBorder << " ";
    }
    cout << endl;
}

void TextObserver::notifyChange(Move m) {
    notifyFull();
}