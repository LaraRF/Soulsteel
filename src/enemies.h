//
// Created by lrfri on 04.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMIES_H
#define RAYLIBSTARTER_ENEMIES_H
#include "gameplay.h"
#include "raylib.h"
#include "scene.h"

class gameplay;

class enemies {
public:
    float damage =0;
    void draw(); //method to draw enemy texture in base class
    void update();
    //movement
    float stepsize = 1.0f;
    gameplay* _scene;

    //enemy map interaction > same as in maincharacter.h?
    enemies(gameplay *scene);
    Vector2 position = {124, 32 * 7};
    float size = 16;

    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
    //Texture2D enemyTexture2 = assestmanagergraphics::getTexture("characters/enemies/enemy_2");
};


#endif //RAYLIBSTARTER_ENEMIES_H
