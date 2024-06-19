//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_BOMBS_H
#define RAYLIBSTARTER_BOMBS_H

#include "raylib.h"
#include "gameobjects.h"

class bombs:public gameobjects {
public:
    void update() override;
    void draw() override;

};


#endif //RAYLIBSTARTER_BOMBS_H
