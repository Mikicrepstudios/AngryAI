#pragma once

#include "SDL2/SDL.h"

namespace textures {
    struct EntityTextures {
        SDL_Texture* playerTexture = {};
    };

    EntityTextures initEntity(SDL_Renderer* &renderer);
}