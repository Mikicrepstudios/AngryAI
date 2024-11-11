#include "mf/core.h"
#include "mf/graphics.h"

#include "rects.h"
#include "textures.h"

namespace draw {
    void DrawShields(core::MF_Window &window, rects::ShieldRects shieldRects, textures::SpecialsTextures specialsTextures, int shieldedAIOrder[3]) {
        if(shieldedAIOrder[0] == 1) draw::DrawTextureRect(window.renderer, shieldRects.topShield, specialsTextures.gptSpecial);
        if(shieldedAIOrder[1] == 1) draw::DrawTextureRect(window.renderer, shieldRects.middleShield, specialsTextures.gptSpecial);
        if(shieldedAIOrder[2] == 1) draw::DrawTextureRect(window.renderer, shieldRects.bottomShield, specialsTextures.gptSpecial);
    }
}