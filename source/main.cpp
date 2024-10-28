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
    // Important vars
    bool running = true;
    int fps = 60;

    // Settings
    int level = 1;
    int bulletSize = 50;
    int bulletTouching = 0;

    // Structs
    settings::SDL_Settings sdlSettings = {};
    settings::Bullet bullet = {};

    data::Player player = {};
    data::AI AIs[3] = {};
    int AIOrder[3] = {};
    AIOrder[0] = 1;
    AIOrder[1] = 2;
    AIOrder[2] = 3;

    // Rects
    rects::EntityRects entityRects = rects::initEntity(sdlSettings);

    // SDL stuff
    sdlSettings.window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sdlSettings.width, sdlSettings.height, 0);
    sdlSettings.renderer = SDL_CreateRenderer(sdlSettings.window, -1, 0);
    SDL_Event event = {};

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    IMG_Init(IMG_INIT_PNG);

    // Textures
    textures::EntityTextures entityTextures = textures::initEntity(sdlSettings.renderer);
    textures::AssetsTextures assetsTextures = textures::initAssets(sdlSettings.renderer);

    // Preparations
    logic::generateAIs(AIs, AIOrder, level);

    while(running) {
        // Get mouse state
        SDL_GetMouseState(&sdlSettings.mouseX, &sdlSettings.mouseY);

        // Do events
        while(SDL_PollEvent(&event) != 0) {
            sdlSettings.event = event;
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }

            if(event.type == SDL_MOUSEBUTTONDOWN) player::Shoot(sdlSettings, bullet);
        }

        // Logic
        player::UpdateBullet(bullet);
        entityRects.bulletRect = {bullet.x - bulletSize / 2, bullet.y - bulletSize / 2, bulletSize, bulletSize};
        bulletTouching = logic::checkBulletTouching(entityRects);
        if(bulletTouching != 0) bullet.y = 4000;

        if(bulletTouching != 0) logic::damageAI(AIs, bulletTouching, 50);
        std::cout << AIs[0].health << " " << AIs[1].health << " " << AIs[2].health << std::endl;

        // Clear screen
        SDL_SetRenderDrawColor(sdlSettings.renderer, 0, 0, 0, 0);
        SDL_RenderClear(sdlSettings.renderer);

        // Draw stuff
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.bulletRect, assetsTextures.bulletTexture);
        draw::DrawEntities(sdlSettings, AIs, AIOrder, entityTextures, entityRects);

        // Show stuff
        SDL_RenderPresent(sdlSettings.renderer);
        SDL_Delay(1000 / fps);
    }

    return 0;
}