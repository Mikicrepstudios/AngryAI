#pragma once

#include "SDL2/SDL.h"

#include "mf/core.h"

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

    EntityRects initEntity(core::MF_Window window);
    ShieldRects initShield(core::MF_Window window);
}