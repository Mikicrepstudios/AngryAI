#include "draw.h"
#include "settings.h"

namespace draw {
    void DrawEntities(settings::SDL_Settings sdlSettings) {
        // Player rect
        SDL_Rect playerRect = {25, sdlSettings.height - 125, 100, 100};

        // Enemies
        SDL_Rect entityTopRect = {sdlSettings.width - 125, 25, 100, 100};
        SDL_Rect entityMiddleRect = {sdlSettings.width - 125, sdlSettings.height / 2 - 50, 100, 100};
        SDL_Rect entityBottomRect = {sdlSettings.width - 125, sdlSettings.height - 125, 100, 100};

        // Draw player
        draw::DrawRect(sdlSettings.renderer, playerRect, 255, 255, 255);

        // Draw enemies
        draw::DrawRect(sdlSettings.renderer, entityTopRect, 0, 212, 85);
        draw::DrawRect(sdlSettings.renderer, entityMiddleRect, 0, 86, 191);
        draw::DrawRect(sdlSettings.renderer, entityBottomRect, 89, 23, 255);
    }
}