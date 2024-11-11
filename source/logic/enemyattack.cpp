#include <string>
#include "SDL2/SDL.h"

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"
#include "mf/logic.h"

#include "data.h"
#include "textures.h"

SDL_Rect attackTextRect = {25, 225, 400, 100};

namespace logic {
    void enemyAttack(core::MF_Window &window, data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int &turn, textures::DamageTextures damageTextures, textures::SpecialsTextures specialsTextures) {
        if(turn == 1) {
            std::string attackText = "";

            SDL_Rect damageRect = {175, window.height - 175, 500, 150};
            SDL_Rect dodgeRect = {25, window.height - 325, 500, 150};

            for(int x = 0; x < 3; x++) {
                // Is AI breathing?
                if(AIs[x].health != 0) {
                    // First if is dodging, second if is attacking
                    if(logic::GenRanNum(1, AIs[x].missChance) != 1 && AIs[x].curCharge != AIs[x].maxCharge) {
                        player.health -= AIs[x].damage;
                        AIs[x].curCharge++;
                        if(player.health < 0) player.health = 0;

                        draw::DrawRect(window.renderer, dodgeRect, colors::general::black); // Clear dodged img

                        // GPT Attack
                        if(AIOrder[x] == 1) {
                            draw::DrawTextureRect(window.renderer, damageRect, damageTextures.gptAttack);

                            // Text stuff
                            attackText = "GPT dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        // Copilot Attack
                        else if(AIOrder[x] == 2) {
                            draw::DrawTextureRect(window.renderer, damageRect, damageTextures.copilotAttack);

                            // Text stuff
                            attackText = "Copilot dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        // Gemini Attack
                        else if(AIOrder[x] == 3) {
                            draw::DrawTextureRect(window.renderer, damageRect, damageTextures.geminiAttack);

                            // Text stuff
                            attackText = "Gemini dealt " + std::to_string(AIs[x].damage) + " dmg"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        SDL_RenderPresent(window.renderer);
                        SDL_Delay(750);
                    }
                    else if(AIs[x].curCharge == AIs[x].maxCharge) {
                        // GPT
                        if(AIOrder[x] == 1) {
                            int firstShield = logic::GenRanNum(0, 2);
                            int secondShield = logic::GenRanNum(0, 2);

                            shieldedAIOrder[firstShield] = 1;
                            shieldedAIOrder[secondShield] = 1;

                            // Text stuff
                            attackText = "GPT spawned shields!"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        // Copilot
                        else if(AIOrder[x] == 2) {
                            player.health -= 100;
                            if(player.health < 0) player.health = 0;
                            draw::DrawTextureRect(window.renderer, damageRect, specialsTextures.copilotSpecial);

                            // Text stuff
                            attackText = "Copilot dealt 100 dmg"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        // Gemini
                        else if(AIOrder[x] == 3) {
                            int dmg = logic::GenRanNum(0, 200);

                            player.health -= dmg;
                            if(player.health < 0) player.health = 0;
                            draw::DrawTextureRect(window.renderer, damageRect, specialsTextures.geminiSpecial);

                            // Text stuff
                            attackText = "Gemini dealt " + std::to_string(dmg) + " dmg"; 
                            draw::DrawRect(window.renderer, attackTextRect, colors::general::gray);
                            draw::DrawText(window.renderer, window.font, attackTextRect, attackText.c_str(), colors::text::whiteTextColor);
                        }

                        AIs[x].curCharge = 0;

                        if(AIOrder[x] != 1) {
                            SDL_RenderPresent(window.renderer);
                            SDL_Delay(500);
                        }
                    }
                    // Draw dodged text if player dodged attack
                    else {
                        draw::DrawRect(window.renderer, damageRect, colors::general::black); // Clear dmg img
                        draw::DrawTextureRect(window.renderer, dodgeRect, damageTextures.dodgedAttack);

                        SDL_RenderPresent(window.renderer);
                        SDL_Delay(250);
                    }
                }
            }
            turn = 0;
        }
    }
}