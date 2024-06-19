//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_ROBOT_H
#define RAYLIBSTARTER_ROBOT_H

#include "gameobjects.h"
#include "../assestmanagergraphics.h"


class robot:public gameobjects {
private:
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");

public:
    void update() override;
    void draw() override;

    robot();
};


#endif //RAYLIBSTARTER_ROBOT_H
