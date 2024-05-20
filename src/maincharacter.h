//
// Created by lrfri on 20.05.2024.
//

#ifndef RAYLIBSTARTER_MAINCHARACTER_H
#define RAYLIBSTARTER_MAINCHARACTER_H

#include "raylib.h"

class maincharacter {

public:
    void update();
    void draw();

    Vector2 characterposition={(float)960/2, (float)540/2 };
    Rectangle characterplaceholder;

};


#endif //RAYLIBSTARTER_MAINCHARACTER_H
