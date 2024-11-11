#include "mf/core.h"

#include "rects.h"

namespace rects {
    EntityRects initEntity(core::MF_Window window) {
        EntityRects rects = {};

        rects.playerRect = {25, window.height - 150, 125, 125};

        rects.topEnemyRect = {window.width - 175, 25, 150, 150};
        rects.middleEnemyRect = {window.width - 175, window.height / 2 - 75, 150, 150};
        rects.bottomEnemyRect = {window.width - 175, window.height - 175, 150, 150};

        return rects;
    }

    ShieldRects initShield(core::MF_Window window) {
        ShieldRects rects = {};

        rects.topShield = {window.width - 270, -5, 90, 220};
        rects.middleShield = {window.width - 270, window.height / 2 - 105, 90, 220};
        rects.bottomShield = {window.width - 270, window.height - 205, 90, 220};

        return rects;
    }
}