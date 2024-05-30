//
// Created by lrfri on 29.05.2024.
//

#ifndef RAYLIBSTARTER_SCENE_H
#define RAYLIBSTARTER_SCENE_H

#include <vector>
#include "raylib.h"

class scene {
public:
    virtual void update() = 0;
    virtual scene* evaluateSceneChange();
    virtual void draw() = 0;
    virtual void drawDebug() = 0;
};


#endif //RAYLIBSTARTER_SCENE_H
