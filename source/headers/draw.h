#pragma once

#include <SDL_ttf.h>

#include "mf/core.h"

#include "data.h"
#include "settings.h"
#include "rects.h"
#include "textures.h"

namespace draw {
    // Game
	void DrawHPBars(core::MF_Window &window, data::Player player, data::AI AIs[3], rects::EntityRects entityRects);
	void DrawSpecialBars(core::MF_Window &window, data::Player player, data::AI AIs[3], rects::EntityRects entityRects);
    void DrawEntities(core::MF_Window &window, data::AI AIs[3], int AIOrder[3], textures::EntityTextures &entityTextures, rects::EntityRects entityRects);
	void DrawShields(core::MF_Window &window, rects::ShieldRects shieldRects, textures::SpecialsTextures specialsTextures, int shieldedAIOrder[3]);

	// Visuals
	void DrawGUI(core::MF_Window &window, int level, int timeM, int timeS);
}