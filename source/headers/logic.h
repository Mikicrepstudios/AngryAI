#pragma once

#include "SDL2/SDL.h"

#include "rects.h"

namespace logic {
    extern bool areRectsTouching(const SDL_Rect& rect1, const SDL_Rect& rect2);

    extern int checkBulletTouching(rects::EntityRects entityRects);
}