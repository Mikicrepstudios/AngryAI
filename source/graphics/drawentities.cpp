#include "SDL2/SDL.h"
#include <SDL_image.h>

#include "data.h"
#include "draw.h"
#include "settings.h"
#include "rects.h"
#include "textures.h"

retrerwaw r// break please
namespace draw {
    void DrawEntities(settings::SDL_Settings sdlSettings, data::AI AIs[3], int AIOrder[3], textures::EntityTextures &entityTextures, rects::EntityRects entityRects) {
        // Draw player
        draw::DrawTextureRect(sdlSettings.renderer, entityRects.playerRect, entityTextures.playerTexture);

        // Draw enemies
        SDL_Rect curRect = {};
        for(int x = 0; x <= 2; x++) {
            if(x == 0) curRect = entityRects.topEnemyRect;
            else if(x == 1) curRect = entityRects.middleEnemyRect;
            else if(x == 2) curRect = entityRects.bottomEnemyRect;

            if(AIs[x].health != 0) {
                if(AIOrder[x] == 1) draw::DrawTextureRect(sdlSettings.renderer, curRect, entityTextures.gptTexture);
                else if(AIOrder[x] == 2) draw::DrawTextureRect(sdlSettings.renderer, curRect, entityTextures.copilotTexture);
                else if(AIOrder[x] == 3) draw::DrawTextureRect(sdlSettings.renderer, curRect, entityTextures.geminiTexture);
            }
        }
    }
}