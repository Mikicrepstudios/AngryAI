#pragma once

#include "SDL2/SDL.h"

namespace settings {
    struct SDL_Settings {
        int width = 1280;
        int height = 800;

        int mouseX = 0;
        int mouseY = 0;

        SDL_Window* window = {};
        SDL_Renderer* renderer = {};
        SDL_Event event = {};
    };

    struct Bullet {
        int x = 0;
        int y = 4000;

        float velX = 0;
        float velY = 0;

        float gravity = 0.92f;
    };
}