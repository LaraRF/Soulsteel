//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"
#include "languagesettings.h"
#include "maincharactermodus.h"
#include <iostream>
class maincharacter {

public:
    void update(languagestates &languagestates, maincharactermodus &maincharactermodus);
    void draw(languagestates &languagestates, maincharactermodus &maincharactermodus);

    //lets the character start in the middle of the screen
    Vector2 characterposition={(float)960/2, (float)540/2 };

    //movement
    bool souldashactivated =false;
    int souldash=0;
    float stepsize =5.0f;
    float stepzisesouldash =20;
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
