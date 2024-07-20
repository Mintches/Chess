#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include "../board.h"
using namespace std;

class Level3: public Computer {
    virtual string getMove(Board board) const override;
};

#endif
