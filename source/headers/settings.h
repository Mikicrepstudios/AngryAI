#pragma once

#include "SDL2/SDL.h"

namespace settings {
    struct SDL_Settings {
        SDL_Window* window = {};
        SDL_Renderer* renderer = {};
        SDL_Event event = {};
    };
}