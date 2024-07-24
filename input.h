#include <utility>

#include "Players/player.h"
#include "Players/human.h"
#include "Players/level1.h"
#include "Players/level2.h"
#include "Players/level3.h"
#include "Players/level4.h"

using namespace std;

class Input {
public:
    pair<int, int> getCoords();
    Player* createPlayer();
};
