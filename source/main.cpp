#include "SDL2/SDL.h"

int main() {
    // Important vars
    bool running = true;
    int fps = 60;

    // SDL stuff
    SDL_Window* window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event = {};

    while(running) {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Show stuff
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / fps);
    }

    return 0;
}