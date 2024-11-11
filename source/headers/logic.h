#pragma once

#include "SDL2/SDL.h"

#include "mf/core.h"

#include "data.h"
#include "rects.h"
#include "textures.h"

namespace logic {
    int checkForNewLvl(data::AI AIs[3], int &level);
    void generateLevel(data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int level, int &timeM, int &timeS, int &frame);

    int checkBulletTouching(rects::EntityRects entityRects, rects::ShieldRects shieldRects);

    void damageAI(data::Player &player, data::AI AIs[3], int target, int minDamage, int maxDamage, settings::Bullet &bullet, int shieldedAIOrder[3], int &turn);
    void specialDamageAI(core::MF_Window &window, data::Player &player, data::AI AIs[3], rects::EntityRects entityRects, bool &isAttackedAI, int &attackedAI);
    void enemyAttack(core::MF_Window &window, data::Player &player, data::AI AIs[3], int AIOrder[3], int shieldedAIOrder[3], int &turn, textures::DamageTextures damageTextures, textures::SpecialsTextures specialsTextures);
}