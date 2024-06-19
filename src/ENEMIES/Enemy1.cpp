//
// Created by sadeh on 13.06.2024.
//

#include "Enemy1.h"


void Enemy1::getEnemyData() {
    Enemy1(nullptr);
}

void Enemy1::getEnemyPosition() {
    //Vector2 position = {11 * 32, 32 * 5};
    stopleft = 12.0f * 32.0f + 16.0f;
    stopdown = 10 * 32 + 16;
    stopright = 11 * 32 - 16;
    stopup = 6 * 32 - 16;

}
void Enemy1::draw() {
    DrawTexture(enemyTexture1, position.x, position.y, WHITE);
}

Enemy1::~Enemy1() {

}



