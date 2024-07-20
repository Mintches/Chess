#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include "../board.h"
#include "level1.h"
using namespace std;

class Level1: public Computer {
    virtual string getMove(Board board) const override;
};

#endif
