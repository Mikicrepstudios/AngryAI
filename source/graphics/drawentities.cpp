#include "SDL2/SDL.h"
#include <SDL_image.h>

#include "draw.h"
#include "settings.h"

namespace draw {
    void DrawEntities(settings::SDL_Settings sdlSettings) {
        // Player rect
        SDL_Rect playerRect = {25, sdlSettings.height - 150, 125, 125};
        SDL_Surface* playerSurface = IMG_Load("assets/player.png");
        SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(sdlSettings.renderer, playerSurface);
        SDL_FreeSurface(playerSurface);

        // Enemies
        SDL_Rect entityTopRect = {sdlSettings.width - 175, 25, 150, 150};
        SDL_Rect entityMiddleRect = {sdlSettings.width - 175, sdlSettings.height / 2 - 75, 150, 150};
        SDL_Rect entityBottomRect = {sdlSettings.width - 175, sdlSettings.height - 175, 150, 150};

        // Draw player
        draw::DrawTextureRect(sdlSettings.renderer, playerRect, playerTexture);

        // Draw enemies
        draw::DrawRect(sdlSettings.renderer, entityTopRect, 0, 212, 85);
        draw::DrawRect(sdlSettings.renderer, entityMiddleRect, 0, 86, 191);
        draw::DrawRect(sdlSettings.renderer, entityBottomRect, 89, 23, 255);
    }
}