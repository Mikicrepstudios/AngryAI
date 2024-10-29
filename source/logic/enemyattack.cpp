#include "SDL2/SDL.h"

#include "data.h"
#include "draw.h"
#include "logic.h"
#include "settings.h"
#include "textures.h"

namespace logic {
    void enemyAttack(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], int AIOrder[3], int &turn, textures::DamageTextures damageTextures, textures::SpecialsTextures specialsTextures) {
        if(turn == 1) {
            SDL_Rect damageRect = {175, sdlSettings.height - 175, 500, 150};
            SDL_Rect dodgeRect = {25, sdlSettings.height - 325, 500, 150};

            for(int x = 0; x < 3; x++) {
                // Is AI breathing?
                if(AIs[x].health != 0) {
                    // First if is dodging, second if is attacking
                    if(logic::generateRandomNumber(1, AIs[x].missChance) != 1 && AIs[x].curCharge != AIs[x].maxCharge) {
                        player.health -= AIs[x].damage;
                        AIs[x].curCharge++;
                        if(player.health < 0) player.health = 0;

                        draw::DrawRect(sdlSettings.renderer, dodgeRect, 0, 0, 0); // Clear dodged img
                        if(AIOrder[x] == 1) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.gptAttack);
                        else if(AIOrder[x] == 2) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.copilotAttack);
                        else if(AIOrder[x] == 3) draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.geminiAttack);

                        SDL_RenderPresent(sdlSettings.renderer);
                        SDL_Delay(750);
                    }
                    else if(AIs[x].curCharge == AIs[x].maxCharge) {
                        // GPT
                        if(AIOrder[x] == 1) {

                        }

                        // Copilot
                        else if(AIOrder[x] == 2) {
                            player.health -= 100;
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, specialsTextures.copilotSpecial);
                        }

                        // Gemini
                        else if(AIOrder[x] == 3) {
                            player.health -= logic::generateRandomNumber(0, 200);
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, specialsTextures.geminiSpecial);
                        }

                        AIs[x].curCharge = 0;

                        SDL_RenderPresent(sdlSettings.renderer);
                        SDL_Delay(500);
                    }
                    // Draw dodged text if player dodged attack
                    else {
                        draw::DrawRect(sdlSettings.renderer, damageRect, 0, 0, 0); // Clear dmg img
                        draw::DrawTextureRect(sdlSettings.renderer, dodgeRect, damageTextures.dodgedAttack);

                        SDL_RenderPresent(sdlSettings.renderer);
                        SDL_Delay(250);
                    }
                }
            }
            turn = 0;
        }
    }
}