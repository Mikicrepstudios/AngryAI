#pragma once

#include "SDL2/SDL.h"

namespace settings {
    struct SDL_Settings {
        int width = 1280;
        int height = 800;

        SDL_Window* window = {};
        SDL_Renderer* renderer = {};
        SDL_Event event = {};
    };
}