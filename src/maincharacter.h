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
#include "gameplayroom1.h"

class gameplayroom1;

class maincharacter {
private:
    Texture2D characterSoulTexture = assestmanagergraphics::getTexture("characters/soul/Soul_front");
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Robot_front");

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
    gameplayroom1* _scene;

    //sprite animation
    //Texture2D soulanimated =LoadTexture("assets/graphics/soulsprite.png");

    //Character map interaction stuff
    maincharacter(gameplayroom1 *scene);
    Vector2 position = {124, 32 * 7};
    float size = 16;

    maincharactermodus currentmode=soul;
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
