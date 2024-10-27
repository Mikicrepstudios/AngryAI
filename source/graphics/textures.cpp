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


        SDL_Surface* gptSurface = IMG_Load("assets/gpt.png");
        textures.gptTexture = SDL_CreateTextureFromSurface(renderer, gptSurface);
        SDL_FreeSurface(gptSurface);

        SDL_Surface* copilotSurface = IMG_Load("assets/copilot.png");
        textures.copilotTexture = SDL_CreateTextureFromSurface(renderer, copilotSurface);
        SDL_FreeSurface(copilotSurface);

        SDL_Surface* geminiSurface = IMG_Load("assets/gemini.png");
        textures.geminiTexture = SDL_CreateTextureFromSurface(renderer, geminiSurface);
        SDL_FreeSurface(geminiSurface);

        return textures;
    }
}