#include "SDL2/SDL.h"

#include "draw.h"
#include "rects.h"
#include "settings.h"
#include "textures.h"

namespace draw {
    void DrawShields(settings::SDL_Settings sdlSettings, rects::ShieldRects shieldRects, textures::SpecialsTextures specialsTextures, int shieldedAIOrder[3]) {
        if(shieldedAIOrder[0] == 1) draw::DrawTextureRect(sdlSettings.renderer, shieldRects.topShield, specialsTextures.gptSpecial);
        if(shieldedAIOrder[1] == 1) draw::DrawTextureRect(sdlSettings.renderer, shieldRects.middleShield, specialsTextures.gptSpecial);
        if(shieldedAIOrder[2] == 1) draw::DrawTextureRect(sdlSettings.renderer, shieldRects.bottomShield, specialsTextures.gptSpecial);
    }
}