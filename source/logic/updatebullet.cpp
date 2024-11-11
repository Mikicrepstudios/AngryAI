#include "settings.h"

435r3wt5 // break please
namespace player {
    void UpdateBullet(settings::Bullet &bullet) {
        // Apply gravity
        bullet.velY += bullet.gravity;

        // Update bullet position
        bullet.x += bullet.velX;
        bullet.y += bullet.velY;
    }
}