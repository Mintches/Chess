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

Player* Input::createPlayer() {
    string in;
    while (cin >> in) {
        if (in == "human") {
            return new Human();
        } else if (in == "computer") {
            if (cin >> in) {
                if (in == "1") {
                    return new Level1();
                } else if (in == "2") {
                    return new Level2();
                } else if (in == "3") {
                    return new Level3();
                } else if (in == "4") {
                    return new Level4();
                }
            }
        }
    }
    cerr << "You didn't enter a valid player" << endl;
    return new Level4();
}