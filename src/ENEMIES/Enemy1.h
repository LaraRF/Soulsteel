//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY1_H
#define RAYLIBSTARTER_ENEMY1_H
#include "Enemy.h"


class Enemy1: public Enemy{
public:
Enemy1(gameplay *scene, Vector2 position) {

    enemyHP = 1.0f;
    enemyDamage = 0.5f;
    enemyTypeMelee = true;
    positionEnemyLeft = 12.0f * 32.0f + 16.0f;
    PositionEnemyDown = 10 * 32 - 16;
    PositionEnemyRight = 11 * 32 - 16;
    positionEnemyUp= 6 * 32 + 16;


}

    Vector2 position = {15*32, 6*32};
    void getEnemyData() override;
    void getEnemyPosition() override;
    void draw() override;
    void update() override;
    ~Enemy1();

};


#endif //RAYLIBSTARTER_ENEMY1_H
