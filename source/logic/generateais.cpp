

#include "data.h"

namespace logic {
    void generateAIs(data::AI AIs[3], int AIOrder[3], int level) {
        for (int x = 0; x <= 2; x++) {
            if(AIOrder[x] == 1) {
                AIs[x].type = 1;
                AIs[x].health = 150 * (1.2 * level);
                AIs[x].missChance = 25;
            }
            else if(AIOrder[x] == 2) {
                AIs[x].type = 2;
                AIs[x].health = 250 * (1.1 * level);
                AIs[x].missChance = 50;
            }
            else if(AIOrder[x] == 3) {
                AIs[x].type = 3;
                AIs[x].health = 250 * (1.1 * level);
                AIs[x].missChance = 50;
            }

            AIs[x].damage = 50 * (1.05 * level);
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