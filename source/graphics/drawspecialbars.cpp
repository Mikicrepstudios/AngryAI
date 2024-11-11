#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

#include "data.h"
#include "rects.h"

namespace draw {
    void DrawSpecialBars(core::MF_Window &window, data::Player player, data::AI AIs[3], rects::EntityRects entityRects) {
        // Backgrounds
        SDL_Rect pBarRect = {entityRects.playerRect.x, entityRects.playerRect.y + 135, entityRects.playerRect.w, 10};

        SDL_Rect tBarRect = {entityRects.topEnemyRect.x, entityRects.topEnemyRect.y + 175, entityRects.topEnemyRect.w, 10};
        SDL_Rect mBarRect = {entityRects.middleEnemyRect.x, entityRects.middleEnemyRect.y + 175, entityRects.middleEnemyRect.w, 10};
        SDL_Rect bBarRect = {entityRects.bottomEnemyRect.x, entityRects.bottomEnemyRect.y + 165, entityRects.bottomEnemyRect.w, 10};

        draw::DrawRect(window.renderer, pBarRect, colors::general::gray);

        if(AIs[0].health != 0) draw::DrawRect(window.renderer, tBarRect, colors::general::gray);
        if(AIs[1].health != 0) draw::DrawRect(window.renderer, mBarRect, colors::general::gray);
        if(AIs[2].health != 0) draw::DrawRect(window.renderer, bBarRect, colors::general::gray);


        // Actual bar
        SDL_Rect pFillRect = {pBarRect.x, pBarRect.y, static_cast<int>(pBarRect.w * (static_cast<float>(player.curCharge) / player.maxCharge)), pBarRect.h};

        SDL_Rect tFillRect = {tBarRect.x, tBarRect.y, static_cast<int>(tBarRect.w * (static_cast<float>(AIs[0].curCharge) / AIs[0].maxCharge)), tBarRect.h};
        SDL_Rect mFillRect = {mBarRect.x, mBarRect.y, static_cast<int>(mBarRect.w * (static_cast<float>(AIs[1].curCharge) / AIs[1].maxCharge)), mBarRect.h};
        SDL_Rect bFillRect = {bBarRect.x, bBarRect.y, static_cast<int>(bBarRect.w * (static_cast<float>(AIs[2].curCharge) / AIs[2].maxCharge)), bBarRect.h};

        draw::DrawRect(window.renderer, pFillRect, colors::general::aqua);

        if(AIs[0].health != 0) draw::DrawRect(window.renderer, tFillRect, colors::general::aqua);
        if(AIs[1].health != 0) draw::DrawRect(window.renderer, mFillRect, colors::general::aqua);
        if(AIs[2].health != 0) draw::DrawRect(window.renderer, bFillRect, colors::general::aqua);
    }
}