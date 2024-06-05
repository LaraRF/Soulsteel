//
// Created by lrfri on 04.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMIES_H
#define RAYLIBSTARTER_ENEMIES_H

#include "gameplay.h"
#include "raylib.h"
#include "scene.h"
#include "raymath.h"
#include "enemymodus.h"
#include <iostream>

class gameplay;

class enemies {
public:
    float damage = 0;

    void draw(); //method to draw enemy texture in base class
    void update();

    //movement
    float stepsize = 1.0f;
    gameplay *_scene;

    //enums
    direction direction = left;
    controltype controltype = path;

    //enemy map interaction > same as in maincharacter.h?
    enemies(gameplay *scene);

    //function to change between enemy number

    //position enemy1
    Vector2 positionStart_enemy1 = {14 * 32, 32 * 10};
    Vector2 position = {14 * 32, 32 * 10};
    float size = 16;

    float stopleft = 10 * 32 - 16;
    float stopdown = 12 * 32 + 16;
    float stopright = 14 * 32 - 16;
    float stopup =10 * 32 - 16;

    //Textures
    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
    //Texture2D enemyTexture2 = assestmanagergraphics::getTexture("characters/enemies/enemy_2");

    //Timer stuff
    struct Timer {
        float Pausetime = 2.0f;
    };

    static void StartTimer(Timer *timer, float pausetime);

    static void UpdateTimer(Timer *timer);

    static bool TimerDone(Timer *timer);

    float enemypause = 2.0f;
    Timer enemytimer = {0};
    enemies *enemy1;
};

// child classes
class enemy1: public enemies {

};

#endif //RAYLIBSTARTER_ENEMIES_H
