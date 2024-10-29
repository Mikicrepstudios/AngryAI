#include "data.h"

namespace logic {
    int checkForNewLvl(data::AI AIs[3], int &level) {
        if(AIs[0].health == 0 && AIs[1].health == 0 && AIs[2].health == 0) {
            level++;
            return 1;
        }
        return 0;
    }
}