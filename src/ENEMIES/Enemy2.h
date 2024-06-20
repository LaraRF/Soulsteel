//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY2_H
#define RAYLIBSTARTER_ENEMY2_H
#include "Enemy.h"

class Enemy2: public Enemy {
public:
    Enemy2(gameplay *scene) {

        enemyHP = 1.0f;
        enemyDamage = 0.5f;
        enemyTypeRanged = true;
        stopleft = 6.0f * 32.0f - 16.0f;
        stopdown = 8 * 32 + 16;
        stopright = 8 * 32 - 16;
        stopup = 6 * 32 + 16;
    }

    Vector2 position = {20*32, 3*32};
    float stopPointLeft = {6.0f * 32.0f - 16.0f};
    void getEnemyData() override;
    void getEnemyPosition() override;
    void draw() override;
    void update() override;
    ~Enemy2();
};


#endif //RAYLIBSTARTER_ENEMY2_H
