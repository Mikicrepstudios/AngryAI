#include "SDL2/SDL.h"

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

namespace game {
    void titleScreen(core::MF_Window &window) {
        SDL_Event titleEvent = {};

        SDL_Rect titleRect = {window.width / 2 - 500 / 2, 0, 500, 200};
        SDL_Rect descRect = {window.width / 2 - 500, window.height / 2 + 100, 1000, 50};
        SDL_Rect playRect = {window.width / 2 - 400, window.height / 2 - 100, 800, 200};

        SDL_Rect devRect = {0, window.height - 200, 300, 100};
        SDL_Rect musicRect = {window.width - 300, window.height - 200, 300, 100};

        SDL_Rect copyrightRect = {window.width / 2 - 500, window.height - 100, 1000, 100};

        bool title = true;
        while(title) {
            while(SDL_PollEvent(&titleEvent) != 0) {
                if(titleEvent.type == SDL_MOUSEBUTTONDOWN) title = false;
            }

            SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
            SDL_RenderClear(window.renderer);

            draw::DrawText(window.renderer, window.font, titleRect, "Angry AI", colors::text::whiteTextColor);
            draw::DrawText(window.renderer, window.font, devRect, "Dev: Mikicrep", colors::text::whiteTextColor);
            draw::DrawText(window.renderer, window.font, musicRect, "Music: hipersalam", colors::text::whiteTextColor);

            draw::DrawRect(window.renderer, descRect, colors::general::gray);
            draw::DrawRect(window.renderer, playRect, colors::general::gray);
            draw::DrawText(window.renderer, window.font, descRect, "Read game description before playing", colors::text::whiteTextColor);
            draw::DrawText(window.renderer, window.font, playRect, "Press any mouse button to play", colors::text::whiteTextColor);

            draw::DrawText(window.renderer, window.font, copyrightRect, "Copyright Mikicrep Studios 2024", colors::text::whiteTextColor);

            SDL_RenderPresent(window.renderer);
            SDL_Delay(1000 / 60);
        }
    }
}