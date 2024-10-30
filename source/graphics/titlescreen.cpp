#include "SDL2/SDL.h"
#include <SDL_ttf.h>

#include "draw.h"
#include "settings.h"

namespace game {
    void titleScreen(settings::SDL_Settings sdlSettings) {
        SDL_Event titleEvent = {};
        

        SDL_Rect titleRect = {sdlSettings.width / 2 - 500 / 2, 0, 500, 200};

        SDL_Rect playRect = {sdlSettings.width / 2 - 100, sdlSettings.height / 2 - 100, 200, 200};

        bool title = true;
        while(title) {
            draw::DrawText(sdlSettings.renderer, sdlSettings.font, titleRect, "Angry AI", sdlSettings.textColor);

            draw::DrawButton(sdlSettings.renderer, playRect, 3, 182, 252, sdlSettings.mouseX, sdlSettings.mouseY);
        }
    }
}