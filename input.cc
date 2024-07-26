#include <iostream>
#include <utility>

#include "input.h"
using namespace std;

pair<int, int> Input::getCoords() {
    string s;
    cin >> s;
    char rank = s[0];
    int row = 8 - ((int) s[1] - '0'); 
    int col = (int) rank - 97;
    pair<int, int> p = {row, col};
    return p;
}

unique_ptr<Player> Input::createPlayer() {
    string in;
    cout << "Please input 'human' or 'computer [1-4]'" << endl;
    while (cin >> in) {
        if (in == "human") {
            return make_unique<Human>();
        } else if (in == "computer") {
            if (cin >> in) {
                if (in == "1") {
                    return make_unique<Level1>();
                } else if (in == "2") {
                    return make_unique<Level2>();
                } else if (in == "3") {
                    return make_unique<Level3>();
                } else if (in == "4") {
                    return make_unique<Level4>();
                }
            }
        }
    }
    cerr << "You didn't enter a valid player" << endl;
    return make_unique<Level4>();
}
