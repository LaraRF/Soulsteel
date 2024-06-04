//
// Created by lrfri on 04.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMIES_H
#define RAYLIBSTARTER_ENEMIES_H
#include "gameplay.h"
#include "raylib.h"
#include "scene.h"
#include "raymath.h"

class gameplay;

class enemies {
public:
    float damage = 0;

    void draw(); //method to draw enemy texture in base class
    void update();

    //movement
    float stepsize = 1.0f;
    gameplay *_scene;

    //enemy map interaction > same as in maincharacter.h?
    enemies(gameplay *scene);

    Vector2 position = {14 * 32, 32 * 10};
    float size = 16;

    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
    //Texture2D enemyTexture2 = assestmanagergraphics::getTexture("characters/enemies/enemy_2");

    enum direction {
        left, right, up, down
    };
    direction direction = left;
/*
    struct Timer{float Pausetime=2.0f;};
    static void StartTimer(Timer *timer,float pausetime);
    static void UpdateTimer(Timer*timer);
    static bool TimerDone(Timer*timer);
    float enemypause =2.0f;
    Timer enemytimer={0};*/

};
#endif //RAYLIBSTARTER_ENEMIES_H
