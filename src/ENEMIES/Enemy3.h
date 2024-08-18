//
// Created by sadeh on 24.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY3_H
#define RAYLIBSTARTER_ENEMY3_H
#include "Enemy.h"


class Enemy3: public Enemy {
public:
    Enemy3(gameplay *scene);

    void draw() override;

    ~Enemy3();

private:
    Texture2D enemyTexture3 = assestmanagergraphics::getTexture("characters/enemies/enemy_3");
};


#endif //RAYLIBSTARTER_ENEMY3_H
