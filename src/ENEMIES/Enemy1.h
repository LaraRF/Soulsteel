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
    //Vector2 position;
    //gameplay *_scene;

};


#endif //RAYLIBSTARTER_ENEMY1_H
