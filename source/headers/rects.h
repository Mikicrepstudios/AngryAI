#pragma once

#include "SDL2/SDL.h"

#include "settings.h"

namespace rects {
    struct EntityRects {
        SDL_Rect playerRect = {};

        SDL_Rect topEnemyRect = {};
        SDL_Rect middleEnemyRect = {};
        SDL_Rect bottomEnemyRect = {};

        SDL_Rect bulletRect = {};
    };

    struct ShieldRects {
        SDL_Rect topShield = {};
        SDL_Rect middleShield = {};
        SDL_Rect bottomShield = {};
    };

    EntityRects initEntity(settings::SDL_Settings sdlSettings);
    ShieldRects initShield(settings::SDL_Settings sdlSettings);
}