//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY1_H
#define RAYLIBSTARTER_ENEMY1_H
#include "Enemy.h"


class Enemy1: public Enemy{
public:
Enemy1(gameplay *scene) {

    enemyHP = 0.0f;
    enemyDamage = 0.0f;
    enemyTypeMelee = true;
}

    Vector2 position;
    void getEnemyData() override;
    void getEnemyPosition() override;
    void draw() override;
    ~Enemy1();
};


#endif //RAYLIBSTARTER_ENEMY1_H
