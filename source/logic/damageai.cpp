#include "data.h"
#include "logic.h"
#include "rects.h"
#include "settings.h"

namespace logic {
    void damageAI(data::Player &player, data::AI AIs[3], int target, int minDamage, int maxDamage, settings::Bullet &bullet, int shieldedAIOrder[3], int &turn) {
        if(target < 4) {
            bullet.y = 4000;
            int damage = logic::generateRandomNumber(minDamage, maxDamage);

            AIs[target - 1].health -= damage;
            if(AIs[target - 1].health <= 0) AIs[target - 1].health = 0; // Make number not go negative

            if(player.curCharge != player.maxCharge) player.curCharge++;

            turn = 1;
        }
        else {
            if(target == 4 && shieldedAIOrder[0] == 1) {bullet.y = 4000; turn = 1; shieldedAIOrder[0] = 0;}
            else if(target == 5 && shieldedAIOrder[1] == 1) {bullet.y = 4000; turn = 1; shieldedAIOrder[1] = 0;}
            else if(target == 6 && shieldedAIOrder[2] == 1) {bullet.y = 4000; turn = 1; shieldedAIOrder[2] = 0;}
        }
    }

    void specialDamageAI(settings::SDL_Settings sdlSettings, data::Player &player, data::AI AIs[3], rects::EntityRects entityRects) {
        if(player.curCharge == player.maxCharge) {
            SDL_Rect mouseRect = {sdlSettings.mouseX, sdlSettings.mouseY, 1, 1};
            int target = 0;

            if(logic::areRectsTouching(mouseRect, entityRects.topEnemyRect)) target = 1;
            else if(logic::areRectsTouching(mouseRect, entityRects.middleEnemyRect)) target = 2;
            else if(logic::areRectsTouching(mouseRect, entityRects.bottomEnemyRect)) target = 3;

            
        }
    }
}