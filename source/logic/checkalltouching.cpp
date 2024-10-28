#include "SDL2/SDL.h"

#include "logic.h"
#include "rects.h"

namespace logic {
    int checkBulletTouching(rects::EntityRects entityRects) {
        // Bullet touching 1. top 2. middle 3. bottom enemy
        if(logic::areRectsTouching(entityRects.bulletRect, entityRects.topEnemyRect)) return 1;
        else if(logic::areRectsTouching(entityRects.bulletRect, entityRects.middleEnemyRect)) return 2;
        else if(logic::areRectsTouching(entityRects.bulletRect, entityRects.bottomEnemyRect)) return 3;

        return 0;
    }
}