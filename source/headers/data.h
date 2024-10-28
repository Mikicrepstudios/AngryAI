#pragma once

namespace data {
    struct Player {
        int maxHP = 1000;
        int health = 0;

        int minDamage = 40;
        int maxDamage = 60;

        int curCharge = 0;
    };

    struct AI {
        int type = 0;
        int health = 0;

        int damage = 0;
        int missChance = 0;

        int maxCharge = 0;
        int curCharge = 0;
    };
}