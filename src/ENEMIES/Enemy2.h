//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY2_H
#define RAYLIBSTARTER_ENEMY2_H
#include "Enemy.h"

class Enemy2: public Enemy {
public:
    Enemy2(gameplay *scene) {

        enemyHP = 0.0f;
        enemyDamage = 0.0f;
        enemyTypeMelee = true;
    }

    void getEnemyData() override;

};


#endif //RAYLIBSTARTER_ENEMY2_H
