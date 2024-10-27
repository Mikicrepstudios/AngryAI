#include <iostream>
#include "SDL2/SDL.h"
#include "SDL_image.h"

#include "textures.h"

namespace textures {
    EntityTextures initEntity(SDL_Renderer* &renderer) {
        EntityTextures textures = {};

        SDL_Surface* playerSurface = IMG_Load("assets/player.png");
        textures.playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
        SDL_FreeSurface(playerSurface);

        return textures;
    }
}