//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"
#include <vector>
#include "raymath.h"
#include "languagesettings.h"
#include "maincharactermodus.h"
#include "difficultysettings.h"
#include <iostream>
#include "assestmanagergraphics.h"
#include "gameplay.h"

class gameplay;

class maincharacter {
private:
    Texture2D characterSoulTexture = assestmanagergraphics::getTexture("characters/soul/Soul_front");
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/soul/Soul_front");

public:
    void update(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel);
    void draw(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel);

    //maincharacter();
    //lets the character start in the middle of the screen (almost, to match the tiles)

    //movement
    bool souldashactivated =false;
    int souldash=0;
    float stepsize =8.0f;
    float stepzisesouldash =24;
    gameplay* _scene;

    //sprite animation
    //Texture2D soulanimated =LoadTexture("assets/graphics/soulsprite.png");

    //Character map interaction stuff
    maincharacter(gameplay *scene);
    Vector2 position = {32 * 7, 32 * 7};
    float size = 16;
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
