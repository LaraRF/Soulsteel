//
// Created by sadeh on 13.06.2024.
//

#include "Enemy2.h"

void Enemy2::getEnemyData() {
    Enemy2(nullptr);
}

void Enemy2::getEnemyPosition() {
    stopleft = 16.0f * 32.0f + 16.0f;
    stopdown = 12 * 32 + 16;
    stopright = 14 * 32 - 16;
    stopup = 8 * 32 + 16;

}
void Enemy2::draw() {
    DrawTexture(enemyTexture2, position.x, position.y, WHITE);
}

Enemy2::~Enemy2() {

}
