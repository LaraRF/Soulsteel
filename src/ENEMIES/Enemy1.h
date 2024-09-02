//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY1_H
#define RAYLIBSTARTER_ENEMY1_H
#include "Enemy.h"


class Enemy1: public Enemy{
public:
    Enemy1(gameplay *scene);

    void draw() override;

    ~Enemy1();
private:
    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
};


#endif //RAYLIBSTARTER_ENEMY1_H
