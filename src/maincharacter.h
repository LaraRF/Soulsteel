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

class gameplay;

class maincharacter {
private:
    Texture2D characterSoulTexture = assestmanagergraphics::getTexture("characters/soul/Idle_Animation_front");
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");

public:
    void update();
    void draw();

    //maincharacter();
    //lets the character start in the middle of the screen (almost, to match the tiles)

    //movement
    bool souldashactivated =false;
    int souldash=0;
    float stepsize =4.0f;
    float stepzisesouldash =11.5;
    gameplay* _scene;

    //sprite animation
    //Texture2D soulanimated =LoadTexture("assets/graphics/soulsprite.png");

    //Character map interaction stuff
    maincharacter(gameplay *scene);
    Vector2 position = {12*32, 8*32};
    float size = 12;

    maincharactermodus currentmode=soulmodus;

    //looking direction
    enum lookingdirection{
        north, south, east, west
    };
    lookingdirection lookingdirection =south;

    //bomb throwing
    Texture2D bomb = assestmanagergraphics::getTexture("item/bomb");
    Texture2D bomb_activated = assestmanagergraphics::getTexture("item/bomb_activated");
    Texture2D bomb_exploded = assestmanagergraphics::getTexture("item/bomb_exploded");
    bool throwbomb =false;
    int throwingposx =0;
    int throwingposy=0;
    bool bombhasbeenplaced =false;

    //souldust
    Texture2D souldust = assestmanagergraphics::getTexture("item/souldust");
    bool souldustactivated1 =false;
    bool souldustactivated2 =false;


};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
