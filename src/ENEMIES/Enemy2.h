//
// Created by sadeh on 13.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY2_H
#define RAYLIBSTARTER_ENEMY2_H
#include "Enemy.h"

class Enemy2: public Enemy {
public:
    Enemy2(gameplay *scene);

    void draw() override;

    ~Enemy2();

private:
    //Vector2 position;
    //gameplay *_scene;

};


#endif //RAYLIBSTARTER_ENEMY2_H
