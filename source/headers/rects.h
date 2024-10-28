#pragma once

#include "SDL2/SDL.h"

#include "settings.h"

namespace rects {
    struct EntityRects {
        SDL_Rect playerRect = {};

        SDL_Rect topEnemyRect = {};
        SDL_Rect middleEnemyRect = {};
        SDL_Rect bottomEnemyRect = {};
    };

    EntityRects initEntity(settings::SDL_Settings sdlSettings);
}