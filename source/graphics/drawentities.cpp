#include "SDL2/SDL.h"
#include <SDL_image.h>

#include "draw.h"
#include "settings.h"
#include "rects.h"
#include "textures.h"

namespace draw {
    void DrawEntities(settings::SDL_Settings sdlSettings, textures::EntityTextures &entityTextures, rects::EntityRects entityRects) {
        // Draw player
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.playerRect, entityTextures.playerTexture);

        // Draw enemies
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.topEnemyRect, entityTextures.gptTexture);
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.middleEnemyRect, entityTextures.copilotTexture);
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.bottomEnemyRect, entityTextures.geminiTexture);
    }
}