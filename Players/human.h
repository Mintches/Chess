#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "player.h"
using namespace std;

class Human: public Player {
    public:
        virtual string getMove() const override;
};

#endif
