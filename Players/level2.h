#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include "../board.h"
using namespace std;

class Level2: public Computer {
    virtual string getMove(Board board) const override;
};

#endif