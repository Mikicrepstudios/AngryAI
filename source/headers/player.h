#pragma once

#include "settings.h"

namespace player {
    extern void Shoot(settings::SDL_Settings sdlSettings, settings::Bullet &bullet);
    extern void UpdateBullet(settings::Bullet &bullet);
}

