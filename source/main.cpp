#include <iostream>

#include "SDL2/SDL.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "mf/core.h"

#include "data.h"
#include "draw.h"
#include "game.h"
#include "player.h"
#include "logic.h"
#include "rects.h"
#include "settings.h"
#include "textures.h"

int main(int argc, char* argv[]) {
    bool running = true;
    std::cout << "-------Mikicrep Framework-------" << std::endl
              << "-------Ver: 1.2.0---------------" << std::endl
              << "Copyright Mikicrep Studios 2024" << std::endl;

    std::cout << "Angry AI - 2.0" << std::endl
              << "Copyright Mikicrep Studios 2024" << std::endl;

    // Main stuff
    std::string title = "Angry AI";
    core::MF_Window window = {};
    SDL_Event event = {};

    // Create window
    if(core::InitWindow(window, title, 1280, 800) == false) running = false;

    // Settings
    int level = 0;
    int turn = 0;
    int bulletSize = 50;
    int bulletTouching = 0;

    bool isAttackedAI = false;
    int attackedAI = 0;

    // Structs
    settings::Bullet bullet = {};

    data::Player player = {};
    data::AI AIs[3] = {};
    int AIOrder[3] = {};
    int shieldedAIOrder[3] = {};

    // Rects
    rects::EntityRects entityRects = rects::initEntity(window);
    rects::ShieldRects shieldRects = rects::initShield(window);

    // Textures
    textures::EntityTextures entityTextures = textures::initEntity(window.renderer);
    textures::AssetsTextures assetsTextures = textures::initAssets(window.renderer);
    textures::DamageTextures damageTextures = textures::initDamage(window.renderer);
    textures::SpecialsTextures specialsTextures = textures::initSpecials(window.renderer);

    // SDL Mixer
    Mix_Music *music = Mix_LoadMUS("assets/music.mp3");

    // Title Screen
    game::titleScreen(window);
    Mix_PlayMusic(music, -1);

    while(running) {
        if(player.health == 0) {
            level = 1;
            logic::generateLevel(player, AIs, AIOrder, shieldedAIOrder, level, window.timeM, window.timeS, window.frame);
        }
        if(logic::checkForNewLvl(AIs, level)) logic::generateLevel(player, AIs, AIOrder, shieldedAIOrder, level, window.timeM, window.timeS, window.frame);

        // Get mouse state
        SDL_GetMouseState(&window.mouseX, &window.mouseY);

        // Do events
        while(SDL_PollEvent(&event) != 0) {
            window.event = event;
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }

            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) player::Shoot(window, bullet);
            else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) logic::specialDamageAI(window, player, AIs, entityRects, isAttackedAI, attackedAI);
        }

        // Logic
        player::UpdateBullet(bullet);
        entityRects.bulletRect = {bullet.x - bulletSize / 2, bullet.y - bulletSize / 2, bulletSize, bulletSize};
        bulletTouching = logic::checkBulletTouching(entityRects, shieldRects);
        if(bulletTouching != 0 && bulletTouching < 4) bullet.y = 4000;

        if(bulletTouching != 0) logic::damageAI(player, AIs, bulletTouching, player.minDamage, player.maxDamage, bullet, shieldedAIOrder, turn);

        // Clear screen
        SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 0);
        SDL_RenderClear(window.renderer);

        // GUI
        draw::DrawGUI(window, level, window.timeM, window.timeS);

        // Draw stuff
        draw::DrawTextureRect(window.renderer, entityRects.bulletRect, assetsTextures.bulletTexture);
        draw::DrawHPBars(window, player, AIs, entityRects);
        draw::DrawSpecialBars(window, player, AIs, entityRects);
        draw::DrawEntities(window, AIs, AIOrder, entityTextures, entityRects);
        draw::DrawShields(window, shieldRects, specialsTextures, shieldedAIOrder);

        // Attack
        logic::enemyAttack(window, player, AIs, AIOrder, shieldedAIOrder, turn, damageTextures, specialsTextures);

        // Player special
        if(isAttackedAI) {
            SDL_Rect curRect = {};
            
            if(attackedAI == 0) curRect = entityRects.topEnemyRect;
            else if(attackedAI == 1) curRect = entityRects.middleEnemyRect;
            else if(attackedAI == 2) curRect = entityRects.bottomEnemyRect;

            draw::DrawTextureRect(window.renderer, curRect, specialsTextures.playerSpecial);

            attackedAI = 3;
            isAttackedAI = false;

            SDL_RenderPresent(window.renderer);
            SDL_Delay(750);
        }

        // Show stuff
        SDL_RenderPresent(window.renderer);
        SDL_Delay(1000 / window.fps);

        core::TimeCount(window);
    }

    return 0;
}