//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_BOMBS_H
#define RAYLIBSTARTER_BOMBS_H

#include "raylib.h"
#include "gameobjects.h"
#include "../assestmanagergraphics.h"

class bombs : public gameobjects {
public:
    void update() override;

    void draw() override;

    Texture2D bomb_thrown = assestmanagergraphics::getTexture("item/bomb_thrown");
    Texture2D bomb_exploding = assestmanagergraphics::getTexture("item/bomb_exploding");
};


#endif //RAYLIBSTARTER_BOMBS_H
