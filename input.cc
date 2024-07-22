#include <iostream>
#include <utility>

#include "input.h"
using namespace std;

pair<int, int> Input::getSquare() {
    string s;
    cin >> s;
    char rank = s[0];
    int row = 8 - ((int) s[1] - '0'); 
    int col = (int) rank  - 97;
    pair<int, int> p = {row, col};
    return p;
}