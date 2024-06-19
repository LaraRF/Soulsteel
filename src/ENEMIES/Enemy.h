//
// Created by lrfri on 04.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#include "../gameplay.h"
#include "raylib.h"
#include "../scene.h"
#include "raymath.h"
#include "../enemymodus.h"
#include <iostream>

class gameplay;

class Enemy {
protected:
    std::string enemyName;
    float enemyHP;
    float enemyDamage;
    bool enemyTypeMelee;
    bool enemyTypeRanged;
    bool enemyTypeArmed;
    float stopleft;
    float stopdown;
    float stopright;
    float stopup;

public:
    Enemy() {
    }

    virtual void getEnemyData();

    virtual void getEnemyPosition() ;


    virtual void draw() = 0;
    virtual void update();


    //movement
    float stepsize = 1.0f;
    gameplay *_scene;

    //enums
    direction direction = left;
    controltype controltype = path;

    //enemy map interaction > same as in maincharacter.h?
    Enemy(gameplay *scene);

    //function to change between enemy number

    //position enemy1
    Vector2 position;
    //Vector2 position = {11 * 32, 32 * 5}; //room1 map
    //Vector2 position = {14 * 32, 32 * 10}; //old map
    float size = 16;

    //Textures
    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
    Texture2D enemyTexture2 = assestmanagergraphics::getTexture("characters/enemies/enemy_2");

    //Timer stuff
    struct Timer {
        float Pausetime = 2.0f;
    };

    static void StartTimer(Timer *timer, float pausetime);

    static void UpdateTimer(Timer *timer);

    static bool TimerDone(Timer *timer);

    float enemypause = 2.0f;
    Timer enemytimer = {0};
    //enemies *enemy1;
};



#endif //RAYLIBSTARTER_ENEMY_H
