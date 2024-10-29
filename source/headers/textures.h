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
    struct AssetsTextures {
        SDL_Texture* bulletTexture = {};
    };
    struct DamageTextures {
        SDL_Texture* playerAttack = {};

        SDL_Texture* gptAttack = {};
        SDL_Texture* copilotAttack = {};
        SDL_Texture* geminiAttack = {};

        SDL_Texture* dodgedAttack = {};
    };

    EntityTextures initEntity(SDL_Renderer* &renderer);
    AssetsTextures initAssets(SDL_Renderer* &renderer);
    DamageTextures initDamage(SDL_Renderer* &renderer);
}