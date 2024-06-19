//
// Created by lrfri on 19.06.2024.
//

#include "robot.h"

void robot::update() {

    switch(currentmode){
        case soulmodus:
            if(IsKeyPressed(KEY_SPACE)){
                currentmode=robotmodus;
            }
            break;
        case robotmodus:
            if(IsKeyPressed(KEY_SPACE)){
                currentmode=soulmodus;
            }
            break;
    }

if(currentmode==robotmodus){
    if (IsKeyDown(KEY_S)) {
        position.y = position.y + stepsize;
        lookingdirection=south;
    }
    if (IsKeyDown(KEY_W)) {
        position.y = position.y - stepsize;
        lookingdirection=north;
    }
    if (IsKeyDown(KEY_A)) {
        position.x = position.x - stepsize;
        lookingdirection=west;
    }
    if (IsKeyDown(KEY_D)) {
        position.x = position.x + stepsize;
        lookingdirection=east;
    }//end movement code
}
}

void robot::draw() {
    if(currentmode==robotmodus){
        DrawTexture(characterRobotTexture, position.x-16, position.y-32, WHITE);
        DrawCircle(position.x, position.y, size, GRAY);
    }
    if(currentmode==soulmodus){
        DrawCircle(position.x, position.y, size, BLACK);
    }

}

robot::~robot() {}