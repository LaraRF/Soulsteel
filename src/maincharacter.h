//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"
#include "languagesettings.h"
#include "maincharactermodus.h"
#include "difficultysettings.h"
#include <iostream>
#include "assestmanagergraphics.h"
class maincharacter {
private:
    Texture2D characterSoulTexture = assestmanagergraphics::getTexture("characters/soul/Soul_front");
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/soul/Soul_front");

public:
    void update(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel);
    void draw(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel);

    //lets the character start in the middle of the screen (almost, to match the tiles)
    Vector2 characterposition={(float)416, (float)224 };

    //movement
    bool souldashactivated =false;
    int souldash=0;
    float stepsize =8.0f;
    float stepzisesouldash =24;

    //sprite animation
    //Texture2D soulanimated =LoadTexture("assets/graphics/soulsprite.png");
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
