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
    extern void generateLevel(data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int level, int &timeM, int &timeS, int &frame);

    extern int checkBulletTouching(rects::EntityRects entityRects, rects::ShieldRects shieldRects);

    extern void damageAI(data::Player &player, data::AI AIs[3], int target, int minDamage, int maxDamage, settings::Bullet &bullet, int shieldedAIOrder[3], int &turn);
    extern void specialDamageAI(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], rects::EntityRects entityRects, bool &isAttackedAI, int &attackedAI);
    extern void enemyAttack(settings::SDL_Settings &sdlSettings, data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int &turn, textures::DamageTextures damageTextures, textures::SpecialsTextures specialsTextures);
}