//
// Created by sadeh on 13.06.2024.
//

#include "Enemy1.h"
#include <iostream>

Enemy1::Enemy1(gameplay *scene)
        : Enemy(scene,1, 1, true, false, false,
                12 * 32 + 16, 10 * 32 - 16, 11 * 32 - 16, 6 * 32 + 16) {}

void Enemy1::draw() {
    DrawTexture(enemyTexture1, position.x, position.y, WHITE);
}

Enemy1::~Enemy1() {
}


