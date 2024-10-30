#pragma once

#include "SDL2/SDL.h"
#include <SDL_ttf.h>

namespace settings {
    struct SDL_Settings {
        int width = 1280;
        int height = 800;

        int mouseX = 0;
        int mouseY = 0;

        SDL_Window* window = {};
        SDL_Renderer* renderer = {};
        SDL_Event event = {};
        TTF_Font* font = {};
        
        SDL_Color textColor = {255, 255, 255};
    };

    struct Bullet {
        int x = 0;
        int y = 4000;

        float velX = 0;
        float velY = 0;

        float gravity = 0.5f;
    };
}