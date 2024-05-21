//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"
#include "languagesettings.h"
#include "maincharactermodus.h"

class maincharacter {

public:
    void update(languagestates &languagestates, maincharactermodus &maincharactermodus);
    void draw(languagestates &languagestates, maincharactermodus &maincharactermodus);

    Vector2 characterposition={(float)960/2, (float)540/2 };
};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
