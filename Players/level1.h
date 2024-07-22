#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <random>

#include "../board.h"
#include "level1.h"
using namespace std;

class Level1: public Computer {
    static uniform_int_distribution<int> random(1, 1e9);
    static mt19937 gen(998244353);
    string getMove(Board board) const override;
};

#endif
