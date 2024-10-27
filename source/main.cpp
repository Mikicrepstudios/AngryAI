#include "SDL2/SDL.h"

int main() {
    bool running = true;
    int fps = 60;

    SDL_Window* window = SDL_CreateWindow("Angry AI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    while(running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / fps);
    }

    return 0;
}