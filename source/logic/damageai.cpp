#include "data.h"
#include "logic.h"

namespace logic {
    void damageAI(data::AI AIs[3], int target, int minDamage, int maxDamage) {
        int damage = 0;
        if(minDamage == maxDamage) damage = maxDamage;
        else damage = logic::generateRandomNumber(minDamage, maxDamage);

        if (AIs[target - 1].health > 0) AIs[target - 1].health -= damage;
        if(AIs[target - 1].health <= 0) AIs[target - 1].health = 0; // Make number not go negative
    }
}