#include "SDL2/SDL.h"

#include "draw.h"
#include "settings.h"

int main(int argc, char* argv[]) {
    // Important vars
    bool running = true;
    int fps = 60;

    // Structs
    settings::SDL_Settings sdlSettings = {};

    // SDL stuff
    sdlSettings.window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sdlSettings.width, sdlSettings.height, 0);
    sdlSettings.renderer = SDL_CreateRenderer(sdlSettings.window, -1, 0);
    SDL_Event event = {};

    

    while(running) {
        while(SDL_PollEvent(&event) != 0) {
            sdlSettings.event = event;
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(sdlSettings.renderer, 0, 0, 0, 0);
        SDL_RenderClear(sdlSettings.renderer);

        // Draw stuff
        draw::DrawEntities(sdlSettings);

        // Show stuff
        SDL_RenderPresent(sdlSettings.renderer);
        SDL_Delay(1000 / fps);
    }

    return 0;
}