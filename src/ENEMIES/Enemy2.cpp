//
// Created by sadeh on 13.06.2024.
//

#include "Enemy2.h"

void Enemy2::getEnemyData() {
    Enemy2(nullptr, {position.x, position.y});
}

void Enemy2::getEnemyPosition() {
    stopleft = 2.0f * 32.0f + 16.0f;
    stopdown = 4 * 32 + 16;
    stopright = 6 * 32 - 16;
    stopup = 8 * 32 + 16;

}
void Enemy2::update() {

}
void Enemy2::draw() {
    DrawTexture(enemyTexture2, position.x, position.y, WHITE);
}

Enemy2::~Enemy2() {


    }