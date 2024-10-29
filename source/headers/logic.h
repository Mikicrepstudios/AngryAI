#pragma once

#include "SDL2/SDL.h"

#include "data.h"
#include "rects.h"
#include "settings.h"
#include "textures.h"

namespace logic {
    extern int generateRandomNumber(int min, int max);
    extern bool areRectsTouching(const SDL_Rect& rect1, const SDL_Rect& rect2);

    extern int checkForNewLvl(data::AI AIs[3], int &level);
    extern void generateLevel(data::Player &player, data::AI AIs[3], int AIOrder[3], int level);

    extern int checkBulletTouching(rects::EntityRects entityRects);

    extern void damageAI(data::Player &player, data::AI AIs[3], int target, int minDamage, int maxDamage);
    extern void enemyAttack(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], int AIOrder[3], int &turn, textures::DamageTextures damageTextures);
}