#include <string>
#include "SDL2/SDL.h"

#include "data.h"
#include "draw.h"
#include "logic.h"
#include "settings.h"
#include "textures.h"

SDL_Rect attackTextRect = {25, 225, 400, 100};

namespace logic {
    void enemyAttack(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int &turn, textures::DamageTextures damageTextures, textures::SpecialsTextures specialsTextures) {
        if(turn == 1) {
            std::string attackText = "";

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

                        // GPT Attack
                        if(AIOrder[x] == 1) {
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.gptAttack);

                            // Text stuff
                            attackText = "GPT dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        // Copilot Attack
                        else if(AIOrder[x] == 2) {
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.copilotAttack);

                            // Text stuff
                            attackText = "Copilot dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        // Gemini Attack
                        else if(AIOrder[x] == 3) {
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, damageTextures.geminiAttack);

                            // Text stuff
                            attackText = "Gemini dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        SDL_RenderPresent(sdlSettings.renderer);
                        SDL_Delay(750);
                    }
                    else if(AIs[x].curCharge == AIs[x].maxCharge) {
                        // GPT
                        if(AIOrder[x] == 1) {
                            int firstShield = logic::generateRandomNumber(0, 2);
                            int secondShield = logic::generateRandomNumber(0, 2);

                            shieldedAIOrder[firstShield] = 1;
                            shieldedAIOrder[secondShield] = 1;

                            // Text stuff
                            attackText = "GPT spawned shields!"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        // Copilot
                        else if(AIOrder[x] == 2) {
                            player.health -= 100;
                            if(player.health < 0) player.health = 0;
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, specialsTextures.copilotSpecial);

                            // Text stuff
                            attackText = "Copilot dealt 100 dmg"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        // Gemini
                        else if(AIOrder[x] == 3) {
                            int dmg = logic::generateRandomNumber(0, 200);

                            player.health -= dmg;
                            if(player.health < 0) player.health = 0;
                            draw::DrawTextureRect(sdlSettings.renderer, damageRect, specialsTextures.geminiSpecial);

                            // Text stuff
                            attackText = "Gemini dealt " + std::to_string(dmg) + " dmg"; 
                            draw::DrawRect(sdlSettings.renderer, attackTextRect, 100, 100, 100);
                            draw::DrawText(sdlSettings.renderer, sdlSettings.font, attackTextRect, attackText.c_str(), sdlSettings.textColor);
                        }

                        AIs[x].curCharge = 0;

                        if(AIOrder[x] != 1) {
                            SDL_RenderPresent(sdlSettings.renderer);
                            SDL_Delay(500);
                        }
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