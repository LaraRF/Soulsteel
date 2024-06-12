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
protected:
    //general enemy info
    std::string enemyName;
    float enemyHP;
    bool enemyTypeNormal;
    bool enemyTypeRanged;
    bool enemyTypeWeaponized;
    //int enemyHits;

    //movement
    float stopleft = 5* 32-16;
    float stopdown = 9 * 32 + 16;
    float stopright = 10 * 32 - 16;
    float stopup = 4 * 32 + 16;
    //attack
    float enemyDamage;

public:

    void getEnemyData();
   // void getEnemyType();
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
    Vector2 position = {11 * 32, 32 * 5}; //room1 map
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

// child classes
class enemy1: public enemies {
    public:
        void getEnemyData(){
            //general enemy info            maybe enum for enemy type (normal, ranged, weaponized)???
            enemyName = "Normal Enemy";
            enemyHP = 2.0f;
            enemyDamage = 0.5;
            enemyTypeNormal = true;

            //movement
            stopleft = 5* 32;
            stopdown = 10 * 32 + 16;
            stopright = 11 * 32 - 16;
            stopup = 6 * 32 + 16;
            //enemies::getEnemyData(); //endlosschleife?
        }
    };

class enemy2: public enemies {
public:
    void getEnemyData(){
        //general enemy info            maybe enum for enemy type (normal, ranged, weaponized)???
        enemyName = "Range Enemy";
        enemyHP = 3.0f;
        enemyDamage = 0.5;
        enemyTypeRanged = true;

        //movement
        /*stopleft = 20 * 32 - 16;
        stopdown = 24 * 32 + 16;
        stopright = 26 * 32 - 16;
        stopup = 28 * 32 + 16;*/
        //enemies::getEnemyData(); //endlosschleife?
    }
};

#endif //RAYLIBSTARTER_ENEMIES_H
