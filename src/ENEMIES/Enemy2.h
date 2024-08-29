//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY2_H
#define RAYLIBSTARTER_ENEMY2_H
#include "Enemy.h"

class Enemy2: public Enemy {
public:
    Enemy2(gameplay *scene);
    void update() override;
    void draw() override;

    ~Enemy2();

private:
    void loadAnimations() override;
    Texture2D getCurrentTexture() override;
    bool isAttacking;
};


#endif //RAYLIBSTARTER_ENEMY2_H
