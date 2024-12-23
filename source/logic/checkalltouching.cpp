#include "SDL2/SDL.h"

#include "mf/logic.h"

#include "rects.h"

namespace logic {
    int checkBulletTouching(rects::EntityRects entityRects, rects::ShieldRects shieldRects) {
        // Bullet touching 1. top 2. middle 3. bottom enemy
        if(logic::AreRectsTouching(entityRects.bulletRect, entityRects.topEnemyRect)) return 1;
        else if(logic::AreRectsTouching(entityRects.bulletRect, entityRects.middleEnemyRect)) return 2;
        else if(logic::AreRectsTouching(entityRects.bulletRect, entityRects.bottomEnemyRect)) return 3;

        else if(logic::AreRectsTouching(entityRects.bulletRect, shieldRects.topShield)) return 4;
        else if(logic::AreRectsTouching(entityRects.bulletRect, shieldRects.middleShield)) return 5;
        else if(logic::AreRectsTouching(entityRects.bulletRect, shieldRects.bottomShield)) return 6;

        return 0;
    }
}