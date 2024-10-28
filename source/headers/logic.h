#pragma once

#include "SDL2/SDL.h"

namespace logic {
    extern bool areRectsTouching(const SDL_Rect& rect1, const SDL_Rect& rect2);
}