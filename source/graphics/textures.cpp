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

    AssetsTextures initAssets(SDL_Renderer* &renderer) {
        AssetsTextures textures = {};

        SDL_Surface* assetsSurface = IMG_Load("assets/bullet.png");
        textures.bulletTexture = SDL_CreateTextureFromSurface(renderer, assetsSurface);
        SDL_FreeSurface(assetsSurface);

        return textures;
    }

    DamageTextures initDamage(SDL_Renderer* &renderer) {
        DamageTextures textures = {};


        SDL_Surface* playerSurface = IMG_Load("assets/playerattack.png");
        textures.playerAttack = SDL_CreateTextureFromSurface(renderer, playerSurface);
        SDL_FreeSurface(playerSurface);


        SDL_Surface* gptSurface = IMG_Load("assets/gptattack.png");
        textures.gptAttack = SDL_CreateTextureFromSurface(renderer, gptSurface);
        SDL_FreeSurface(gptSurface);
        
        SDL_Surface* copilotSurface = IMG_Load("assets/copilotattack.png");
        textures.copilotAttack = SDL_CreateTextureFromSurface(renderer, copilotSurface);
        SDL_FreeSurface(copilotSurface);

        SDL_Surface* geminiSurface = IMG_Load("assets/geminiattack.png");
        textures.geminiAttack = SDL_CreateTextureFromSurface(renderer, geminiSurface);
        SDL_FreeSurface(geminiSurface);


        SDL_Surface* dodgedSurface = IMG_Load("assets/dodge.png");
        textures.dodgedAttack = SDL_CreateTextureFromSurface(renderer, dodgedSurface);
        SDL_FreeSurface(dodgedSurface);

        return textures;
    }

    SpecialsTextures initSpecials(SDL_Renderer* &renderer) {
        SpecialsTextures textures = {};


        SDL_Surface* playerSurface = IMG_Load("assets/playerspecial.png");
        textures.playerSpecial = SDL_CreateTextureFromSurface(renderer, playerSurface);
        SDL_FreeSurface(playerSurface);


        SDL_Surface* gptSurface = IMG_Load("assets/gptspecial.png");
        textures.gptSpecial = SDL_CreateTextureFromSurface(renderer, gptSurface);
        SDL_FreeSurface(gptSurface);
        
        SDL_Surface* copilotSurface = IMG_Load("assets/copilotspecial.png");
        textures.copilotSpecial = SDL_CreateTextureFromSurface(renderer, copilotSurface);
        SDL_FreeSurface(copilotSurface);

        SDL_Surface* geminiSurface = IMG_Load("assets/geminispecial.png");
        textures.geminiSpecial = SDL_CreateTextureFromSurface(renderer, geminiSurface);
        SDL_FreeSurface(geminiSurface);

        return textures;
    }
}