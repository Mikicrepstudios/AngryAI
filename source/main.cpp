#include <iostream>

#include "SDL2/SDL.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "data.h"
#include "draw.h"
#include "player.h"
#include "logic.h"
#include "rects.h"
#include "settings.h"
#include "textures.h"

int main(int argc, char* argv[]) {
    std::cout << "Angry AI - 1.0" << std::endl;
    std::cout << "Copyright Mikicrep Studios 2024" << std::endl;

    // Important vars
    bool running = true;
    int fps = 60;
    int frame = 0;
    int timeS = 0;
    int timeM = 0;

    // Settings
    int level = 0;
    int turn = 0;
    int bulletSize = 50;
    int bulletTouching = 0;

    bool isAttackedAI = false;
    int attackedAI = 0;

    // Structs
    settings::SDL_Settings sdlSettings = {};
    settings::Bullet bullet = {};

    data::Player player = {};
    data::AI AIs[3] = {};
    int AIOrder[3] = {};
    int shieldedAIOrder[3] = {};

    // Rects
    rects::EntityRects entityRects = rects::initEntity(sdlSettings);
    rects::ShieldRects shieldRects = rects::initShield(sdlSettings);

    // SDL stuff
    sdlSettings.window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sdlSettings.width, sdlSettings.height, 0);
    sdlSettings.renderer = SDL_CreateRenderer(sdlSettings.window, -1, 0);
    SDL_Event event = {};

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    sdlSettings.font = TTF_OpenFont("assets/font.ttf", 96);
    IMG_Init(IMG_INIT_PNG);

    // Textures
    textures::EntityTextures entityTextures = textures::initEntity(sdlSettings.renderer);
    textures::AssetsTextures assetsTextures = textures::initAssets(sdlSettings.renderer);
    textures::DamageTextures damageTextures = textures::initDamage(sdlSettings.renderer);
    textures::SpecialsTextures specialsTextures = textures::initSpecials(sdlSettings.renderer);

    while(running) {
        if(player.health == 0) {
            level = 1;
            logic::generateLevel(player, AIs, AIOrder, shieldedAIOrder, level, timeM, timeS, frame);
        }
        if(logic::checkForNewLvl(AIs, level)) logic::generateLevel(player, AIs, AIOrder, shieldedAIOrder, level, timeM, timeS, frame);

        // Get mouse state
        SDL_GetMouseState(&sdlSettings.mouseX, &sdlSettings.mouseY);

        // Do events
        while(SDL_PollEvent(&event) != 0) {
            sdlSettings.event = event;
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }

            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) player::Shoot(sdlSettings, bullet);
            else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) logic::specialDamageAI(sdlSettings, player, AIs, entityRects, isAttackedAI, attackedAI);
        }

        // Logic
        player::UpdateBullet(bullet);
        entityRects.bulletRect = {bullet.x - bulletSize / 2, bullet.y - bulletSize / 2, bulletSize, bulletSize};
        bulletTouching = logic::checkBulletTouching(entityRects, shieldRects);
        if(bulletTouching != 0 && bulletTouching < 4) bullet.y = 4000;

        if(bulletTouching != 0) logic::damageAI(player, AIs, bulletTouching, player.minDamage, player.maxDamage, bullet, shieldedAIOrder, turn);

        // Clear screen
        SDL_SetRenderDrawColor(sdlSettings.renderer, 0, 0, 0, 0);
        SDL_RenderClear(sdlSettings.renderer);

        // Draw stuff
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.bulletRect, assetsTextures.bulletTexture);
        draw::DrawHPBars(sdlSettings, player, AIs, entityRects);
        draw::DrawSpecialBars(sdlSettings, player, AIs, entityRects);
        draw::DrawEntities(sdlSettings, AIs, AIOrder, entityTextures, entityRects);
        draw::DrawShields(sdlSettings, shieldRects, specialsTextures, shieldedAIOrder);

        draw::DrawGUI(sdlSettings, level, timeM, timeS);

        // Attack
        logic::enemyAttack(sdlSettings, player, AIs, AIOrder, shieldedAIOrder, turn, damageTextures, specialsTextures);

        // Player special
        if(isAttackedAI) {
            SDL_Rect curRect = {};
            
            if(attackedAI == 0) curRect = entityRects.topEnemyRect;
            else if(attackedAI == 1) curRect = entityRects.middleEnemyRect;
            else if(attackedAI == 2) curRect = entityRects.bottomEnemyRect;

            draw::DrawTextureRect(sdlSettings.renderer, curRect, specialsTextures.playerSpecial);

            attackedAI = 3;
            isAttackedAI = false;

            SDL_RenderPresent(sdlSettings.renderer);
            SDL_Delay(750);
        }

        // Show stuff
        SDL_RenderPresent(sdlSettings.renderer);
        SDL_Delay(1000 / fps);

        frame++;
        if(frame == fps) {
            frame = 0;
            timeS++;

            if(timeS == 60) {
                timeS = 0;
                timeM++;
            }
        }
    }

    return 0;
}