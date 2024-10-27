#pragma once

#include "SDL2/SDL.h"

namespace textures {
    struct EntityTextures {
        SDL_Texture* playerTexture = {};

        // Enemies
        SDL_Texture* gptTexture = {};
        SDL_Texture* copilotTexture = {};
        SDL_Texture* geminiTexture = {};
    };

    EntityTextures initEntity(SDL_Renderer* &renderer);
}