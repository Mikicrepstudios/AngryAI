#include <iostream>
#include <cmath>
#include "settings.h"

namespace player {
    void Shoot(settings::SDL_Settings sdlSettings, settings::Bullet &bullet) {
        SDL_Rect playerRect = {25, sdlSettings.height - 150, 125, 125};

        // Calculate player's center position
        int playerCenterX = playerRect.x + playerRect.w / 2;
        int playerCenterY = playerRect.y + playerRect.h / 2;

        // Set bullet initial position to player's center
        bullet.x = playerCenterX;
        bullet.y = playerCenterY;

        // Calculate direction from player's center to mouse position
        float directionX = static_cast<float>(sdlSettings.mouseX) - playerCenterX;
        float directionY = static_cast<float>(sdlSettings.mouseY) - playerCenterY;

        // Calculate distance
        float distance = sqrt(directionX * directionX + directionY * directionY);

        // Normalize the direction vector
        if (distance != 0) {
            directionX /= distance; // Normalize X
            directionY /= distance; // Normalize Y
        }

        // Set bullet velocity based on distance
        float baseSpeed = 5.0f;
        float speed = baseSpeed + distance / 10.0f; // Increase speed based on distance
        if(speed > 45) speed = 45.0f; // If too fast then slow down

        // Finnaly set velocity
        bullet.velX = directionX * speed;
        bullet.velY = directionY * speed;
    }
}
