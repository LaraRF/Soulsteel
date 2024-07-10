//
// Created by sadeh on 24.06.2024.
//

#include "Enemy3.h"

Enemy3::Enemy3(gameplay *scene)
        : Enemy(3, 3, false, false, true,
                7.0f * 32.0f - 16.0f, 9 * 32 + 16, 9 * 32 - 16, 7 * 32 + 16) {}

void Enemy3::draw() {
    DrawTexture(enemyTexture3, position.x, position.y, WHITE);
}

Enemy3::~Enemy3() {
}