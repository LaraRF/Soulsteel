//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY1_H
#define RAYLIBSTARTER_ENEMY1_H
#include "Enemy.h"


class Enemy1: public Enemy{
public:
Enemy1(gameplay *scene) {

    //enemyName = "enemyNameSample";
    enemyHP = 0.0f;
    enemyDamage = 0.0f;
    enemyTypeMelee = true;
    //enemyTypeRanged = false;
    //enemyTypeArmed = false;
    //movement


}

    void getEnemyData() override;

        /*/movement
        stopleft = 5* 32;
        stopdown = 10 * 32 + 16;
        stopright = 11 * 32 - 16;
        stopup = 6 * 32 + 16;
        //enemies::getEnemyData(); //endlosschleife?*/


};


#endif //RAYLIBSTARTER_ENEMY1_H
