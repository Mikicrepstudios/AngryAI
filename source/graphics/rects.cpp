#include "rects.h"

namespace rects {
    EntityRects initEntity(settings::SDL_Settings sdlSettings) {
        EntityRects rects = {};

        rects.playerRect = {25, sdlSettings.height - 150, 125, 125};

        rects.topEnemyRect = {sdlSettings.width - 175, 25, 150, 150};
        rects.middleEnemyRect = {sdlSettings.width - 175, sdlSettings.height / 2 - 75, 150, 150};
        rects.bottomEnemyRect = {sdlSettings.width - 175, sdlSettings.height - 175, 150, 150};

        return rects;
    }

    ShieldRects initShield(settings::SDL_Settings sdlSettings) {
        ShieldRects rects = {};

        rects.topShield = {sdlSettings.width - 270, -5, 90, 220};
        rects.middleShield = {sdlSettings.width - 270, sdlSettings.height / 2 - 105, 90, 220};
        rects.bottomShield = {sdlSettings.width - 270, sdlSettings.height - 205, 90, 220};

        return rects;
    }
}