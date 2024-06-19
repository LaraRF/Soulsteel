//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_ROBOT_H
#define RAYLIBSTARTER_ROBOT_H

#include "gameobjects.h"
#include "../assestmanagergraphics.h"
#include "../maincharactermodus.h"

class robot:public gameobjects {
private:
    Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");

public:
    void update() override;
    void draw() override;

    maincharactermodus currentmode =soulmodus;



    float stepsize=4;

    //looking direction
    enum lookingdirection{
        north, south, east, west
    };
    lookingdirection lookingdirection =south;

    Vector2 position={11*32, 5*32};
    robot(gameplay*scene, Vector2 position){
        size=12;
    };

    ~robot();
};


#endif //RAYLIBSTARTER_ROBOT_H
