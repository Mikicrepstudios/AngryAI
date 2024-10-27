#include <iostream>

#include "SDL2/SDL.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "draw.h"
#include "player.h"
#include "settings.h"
#include "textures.h"

int main(int argc, char* argv[]) {
    // Important vars
    bool running = true;
    int fps = 60;

    // Settings
    int bulletSize = 50;

    // Structs
    settings::SDL_Settings sdlSettings = {};
    settings::Bullet bullet = {};

    // SDL stuff
    sdlSettings.window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sdlSettings.width, sdlSettings.height, 0);
    sdlSettings.renderer = SDL_CreateRenderer(sdlSettings.window, -1, 0);
    SDL_Event event = {};

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    IMG_Init(IMG_INIT_PNG);

    // Textures
    textures::EntityTextures entityTextures = textures::initEntity(sdlSettings.renderer);

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

        // Clear screen
        SDL_SetRenderDrawColor(sdlSettings.renderer, 0, 0, 0, 0);
        SDL_RenderClear(sdlSettings.renderer);

        // Draw stuff
        draw::DrawRect(sdlSettings.renderer, {bullet.x - bulletSize / 2, bullet.y - bulletSize / 2, bulletSize, bulletSize}, 255, 255, 255);
        draw::DrawEntities(sdlSettings, entityTextures);

        // Show stuff
        SDL_RenderPresent(sdlSettings.renderer);
        SDL_Delay(1000 / fps);
    }

    return 0;
}