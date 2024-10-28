#include "data.h"

namespace logic {
    void damageAI(data::AI AIs[3], int target, int damage) {
        if (AIs[target - 1].health > 0) AIs[target - 1].health -= damage;

        if(AIs[target - 1].health <= 0) AIs[target - 1].health = 0;
    }
}