#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
    public:
        virtual string getMove() const = 0;
        virtual ~Player() = default;
};

#endif
