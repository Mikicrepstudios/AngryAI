#include "SDL2/SDL.h"

#include "data.h"
#include "draw.h"
#include "settings.h"
#include "textures.h"

namespace logic {
    void enemyAttack(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], int AIOrder[3], int &turn, textures::DamageTextures damageTextures) {
        if(turn == 1) {
            SDL_Rect damageRect = {175, sdlSettings.height - 175, 500, 150};

            for(int x = 0; x < 3; x++) {
                player.health -= AIs[x].damage;
                if(player.health < 0) player.health = 0;

                if(AIOrder[x] == 1) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.gptAttack);
                else if(AIOrder[x] == 2) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.copilotAttack);
                else if(AIOrder[x] == 3) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.geminiAttack);

                SDL_RenderPresent(sdlSettings.renderer);
                SDL_Delay(1000);
            }
            turn = 0;
        }
    }
}