#include "SDL2/SDL.h"
#include <SDL_ttf.h>

#include "draw.h"
#include "logic.h"
#include "settings.h"

namespace game {
    void titleScreen(settings::SDL_Settings sdlSettings) {
        SDL_Event titleEvent = {};

        SDL_Rect titleRect = {sdlSettings.width / 2 - 500 / 2, 0, 500, 200};
        SDL_Rect descRect = {sdlSettings.width / 2 - 500, sdlSettings.height / 2 + 100, 1000, 50};
        SDL_Rect playRect = {sdlSettings.width / 2 - 400, sdlSettings.height / 2 - 100, 800, 200};

        SDL_Rect devRect = {0, sdlSettings.height - 200, 300, 100};
        SDL_Rect musicRect = {sdlSettings.width - 300, sdlSettings.height - 200, 300, 100};

        SDL_Rect copyrightRect = {sdlSettings.width / 2 - 500, sdlSettings.height - 100, 1000, 100};

        bool title = true;
        while(title) {
            while(SDL_PollEvent(&titleEvent) != 0) {
                if(titleEvent.type == SDL_MOUSEBUTTONDOWN) title = false;
            }

            SDL_SetRenderDrawColor(sdlSettings.renderer, 0, 0, 0, 255);
            SDL_RenderClear(sdlSettings.renderer);

            draw::DrawText(sdlSettings.renderer, sdlSettings.font, titleRect, "Angry AI", sdlSettings.textColor);
            draw::DrawText(sdlSettings.renderer, sdlSettings.font, devRect, "Dev: Mikicrep", sdlSettings.textColor);
            draw::DrawText(sdlSettings.renderer, sdlSettings.font, musicRect, "Music: hipersalam", sdlSettings.textColor);

            draw::DrawRect(sdlSettings.renderer, descRect, 100, 100, 100);
            draw::DrawRect(sdlSettings.renderer, playRect, 100, 100, 100);
            draw::DrawText(sdlSettings.renderer, sdlSettings.font, descRect, "Read game description before playing", sdlSettings.textColor);
            draw::DrawText(sdlSettings.renderer, sdlSettings.font, playRect, "Press any mouse button to play", sdlSettings.textColor);

            draw::DrawText(sdlSettings.renderer, sdlSettings.font, copyrightRect, "Copyright Mikicrep Studios 2024", sdlSettings.textColor);

            SDL_RenderPresent(sdlSettings.renderer);
            SDL_Delay(1000 / 60);
        }
    }
}