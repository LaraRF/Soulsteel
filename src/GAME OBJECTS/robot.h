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
    //Texture2D characterRobotTexture = assestmanagergraphics::getTexture("characters/robot/Character_-_Robot_-_Idle_Front_-_animated");
    Texture2D robotFront = assestmanagergraphics::getTexture("characters/robot/Robot_front");
public:
    void update() override;
    void draw() override;

    void deleteRobot();


    float stepsize=4;

    //looking direction
    enum lookingdirection{
        north, south, east, west
    };
    lookingdirection lookingdirection =south;

    Vector2 position={11*32, 5*32};
    robot(gameplay*scene){
        size=12;
    };
    maincharactermodus currentmodus =soulmodus;

    gameplay* _scene;

    ~robot();
};


#endif //RAYLIBSTARTER_ROBOT_H
