//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_ROBOT_H
#define RAYLIBSTARTER_ROBOT_H

#include "raylib.h"
#include "gameobjects.h"
#include "../assestmanagergraphics.h"
#include "../maincharactermodus.h"
#include "../gameplay.h"

class gameplay;

class robot:public gameobjects {
private:
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");

public:
    void update() override;
    void draw() override;

    Vector2 position = {12*32, 8*32};
    float size = 12;

    maincharactermodus currentmode=soulmodus;

    robot();



};


#endif //RAYLIBSTARTER_ROBOT_H
