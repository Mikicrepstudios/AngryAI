#pragma once

#include "mf/core.h"

#include "settings.h"

namespace player {
    void Shoot(core::MF_Window &window, settings::Bullet &bullet);
    void UpdateBullet(settings::Bullet &bullet);
}

