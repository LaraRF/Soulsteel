//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY1_H
#define RAYLIBSTARTER_ENEMY1_H
#include "Enemy.h"


class Enemy1: public Enemy{
public:
    Enemy1(gameplay *scene);
    void update() override;
    void draw() override;
    void throwBomb();

    ~Enemy1();


private:
    bool isThrowing;
    Vector2 bombPosition;
    float bombAnimationTimer;

    Texture2D getCurrentTexture() override;

    Texture2D idleTexture;
    Texture2D walkTexture;
    Texture2D attackTexture;
    Texture2D throwTexture;
    Texture2D bombTexture;

    //void updateAnimation(float deltaTime) override;
    //void drawAnimation() override;

    void loadAnimations() override;
    void updateBombThrow();
    void drawBombThrow();
};


#endif //RAYLIBSTARTER_ENEMY1_H
