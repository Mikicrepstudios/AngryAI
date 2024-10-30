#include "data.h"
#include "logic.h"

namespace logic {
    void generateLevel(data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int level, int &timeM, int &timeS, int &frame) {
        player.health = player.maxHealth;
        AIOrder[0] = logic::generateRandomNumber(1, 3);
        AIOrder[1] = logic::generateRandomNumber(1, 3);
        AIOrder[2] = logic::generateRandomNumber(1, 3);
        
        shieldedAIOrder[0] = 0;
        shieldedAIOrder[1] = 0;
        shieldedAIOrder[2] = 0;

        for (int x = 0; x <= 2; x++) {
            if(AIOrder[x] == 1) {
                AIs[x].type = 1;
                AIs[x].maxHealth = 150 * (1 + (.2 * level));
                AIs[x].missChance = 4; // 1 in 4 aka 25%
                AIs[x].maxCharge = 4;
            }
            else if(AIOrder[x] == 2) {
                AIs[x].type = 2;
                AIs[x].maxHealth = 250 * (1 + (.1 * level));
                AIs[x].missChance = 2; // 1 in 2 aka 50%
                AIs[x].maxCharge = 3;
            }
            else if(AIOrder[x] == 3) {
                AIs[x].type = 3;
                AIs[x].maxHealth = 250 * (1 + (.1 * level));
                AIs[x].missChance = 2; // 1 in 2 aka 50%
                AIs[x].maxCharge = 4;
            }

            AIs[x].curCharge = 0;
            AIs[x].health = AIs[x].maxHealth;
            AIs[x].damage = 50 * (1 + (.05 * level));
        }
    }
}

/*
    struct AI {
        int health = 0;

        int damage = 0;
        int missChance = 0;

        int maxCharge = 0;
        int curCharge = 0;
    };
}
*/