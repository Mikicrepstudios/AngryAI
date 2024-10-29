#include "data.h"
#include "logic.h"

namespace logic {
    void damageAI(data::AI AIs[3], int target, int minDamage, int maxDamage) {
        int damage = logic::generateRandomNumber(minDamage, maxDamage);

        if (AIs[target - 1].health > 0) AIs[target - 1].health -= damage;
        if(AIs[target - 1].health <= 0) AIs[target - 1].health = 0; // Make number not go negative
    }
}