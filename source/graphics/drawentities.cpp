#include "draw.h"
#include "settings.h"

namespace draw {
    void DrawEntities(settings::SDL_Settings sdlSettings) {
        SDL_Rect playerRect = {25, sdlSettings.height - 125, 100, 100};

        draw::DrawRect(sdlSettings.renderer, playerRect, 255, 255, 255);
    }
}