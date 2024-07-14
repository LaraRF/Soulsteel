//
// Created by sadeh on 13.06.2024.
//

#include "Enemy2.h"

Enemy2::Enemy2(gameplay *scene)
        : Enemy(scene,2, 2, false, true, false,
                6.0f * 32.0f - 16.0f, 8 * 32 + 16, 8 * 32 - 16, 6 * 32 + 16) {
}

void Enemy2::draw() {
    DrawTexture(enemyTexture2, position.x, position.y, WHITE);
}

Enemy2::~Enemy2() {
    }