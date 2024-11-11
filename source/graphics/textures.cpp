#include <iostream>
#include "SDL2/SDL.h"
#include "SDL_image.h"

#include "mf/core.h"

#include "textures.h"

namespace textures {
    EntityTextures initEntity(SDL_Renderer* &renderer) {
        EntityTextures textures = {};

        textures.playerTexture = core::LoadImg(renderer, "assets/player.png");
        textures.gptTexture = core::LoadImg(renderer, "assets/gpt.png");
        textures.copilotTexture = core::LoadImg(renderer, "assets/copilot.png");
        textures.geminiTexture = core::LoadImg(renderer, "assets/gemini.png");

        return textures;
    }

    AssetsTextures initAssets(SDL_Renderer* &renderer) {
        AssetsTextures textures = {};

        textures.bulletTexture = core::LoadImg(renderer, "assets/bullet.png");

        return textures;
    }

    DamageTextures initDamage(SDL_Renderer* &renderer) {
        DamageTextures textures = {};


        textures.playerAttack = core::LoadImg(renderer, "assets/playerattack.png");
        textures.gptAttack = core::LoadImg(renderer, "assets/gptattack.png");
        textures.copilotAttack = core::LoadImg(renderer, "assets/copilotattack.png");
        textures.geminiAttack = core::LoadImg(renderer, "assets/geminiattack.png");
        textures.dodgedAttack = core::LoadImg(renderer, "assets/dodge.png");

        return textures;
    }

    SpecialsTextures initSpecials(SDL_Renderer* &renderer) {
        SpecialsTextures textures = {};

        textures.playerSpecial = core::LoadImg(renderer, "assets/playerspecial.png");
        textures.gptSpecial = core::LoadImg(renderer, "assets/gptspecial.png");
        textures.copilotSpecial = core::LoadImg(renderer, "assets/copilotspecial.png");
        textures.geminiSpecial = core::LoadImg(renderer, "assets/geminispecial.png");

        return textures;
    }
}