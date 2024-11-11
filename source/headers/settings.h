#pragma once

#include "SDL2/SDL.h"
#include <SDL_ttf.h>

namespace settings {
    struct Bullet {
        int x = 0;
        int y = 4000;

        float velX = 0;
        float velY = 0;

        float gravity = 0.5f;
    };
}