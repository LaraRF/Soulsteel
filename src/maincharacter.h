//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"
#include <vector>
#include "raymath.h"
#include "maincharactermodus.h"
#include <iostream>
#include "assestmanagergraphics.h"
#include "gameplay.h"
#include "Utils.h"
#include "ENEMIES/Enemy.h"

class gameplay;
class Enemy;

class maincharacter {

public:
    void update();
    void draw();
    void maincharacterwalking();
    void drawrobot();
    void drawsoul();
    void souldash();
    void souldust();
    void collisionwall();
    void collisionenemies();
    void collisionbars();
    void collisionabyss();

    //health & Damage
    int health = 10;
    static int attackPower;

    //code for idle animation
    static const int FRAME_COUNT = 8;
    static const float FRAME_DURATION;
    Rectangle frameRec;
    int currentFrame;
    float frameCounter;

    //enum for character direction
    enum Direction {
        FRONT,
        BACK,
        LEFT,
        RIGHT
    };
    Direction currentDirection;

    void updateAnimation(float deltaTime);




    int getHealth(const maincharacter& maincharacter);
    void calculateDamage(maincharacter& maincharacter, int damage);

    //attack
    void setAttackPower(int attack);
    void attack(Enemy* target);


    //movement
    int stepsize =4;
    int stepsizesouldash =65;
    bool souldashactivated=false;
    gameplay* _scene;

    //sprite animation
    //Texture2D soulanimated =LoadTexture("assets/graphics/soulsprite.png");

    //Character map interaction stuff
    maincharacter(gameplay *scene);
    maincharactermodus currentmodus =soulmodus;
    Vector2 position = {12*32, 8*32};
    float size = 12;

    //looking direction
    enum lookingdirection{
        north, south, east, west
    };
    lookingdirection lookingdirection =south;

    //Collision
    Rectangle getCollisionRectangle() const;

    //souldust
    /*
    Texture2D souldust = assestmanagergraphics::getTexture("item/souldust");
    bool souldustactivated1 =false;
    bool souldustactivated2 =false;
     */
    bool felldown=false;

protected:
    bool checkCollision(const Wall& wall);

private:
    Texture2D characterSoulTexture = assestmanagergraphics::getTexture("characters/soul/Idle_Animation_front");
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");
    Vector2 lastSafePosition;
    void updateLastSafePosition();
    bool souldustcanbeused() const;
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
