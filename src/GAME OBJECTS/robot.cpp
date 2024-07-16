//
// Created by lrfri on 19.06.2024.
//

#include "robot.h"
#include "../maincharacter.h"

void robot::update() {

    switch (currentmodus) {
        case soulmodus:
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = robotmodus;
            }
            break;
        case robotmodus:
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = soulmodus;
            }
            break;
    }
/*
    if (currentmode == robotmodus) {
        if (IsKeyDown(KEY_S)) {
            position.y = position.y + stepsize;
            lookingdirection = south;
        }
        if (IsKeyDown(KEY_W)) {
            position.y = position.y - stepsize;
            lookingdirection = north;
        }
        if (IsKeyDown(KEY_A)) {
            position.x = position.x - stepsize;
            lookingdirection = west;
        }
        if (IsKeyDown(KEY_D)) {
            position.x = position.x + stepsize;
            lookingdirection = east;
        }//end movement code
    }

    /*for (int i = 0; _scene->touchesWall(position, size) && i < 4; i++) {
        Rectangle touchedWall = _scene->getTouchedWall(position, size);
        Vector2 touchPoint = Vector2Clamp(position, {touchedWall.x, touchedWall.y},
                                          {touchedWall.x + touchedWall.width, touchedWall.y + touchedWall.height});
        Vector2 pushForce = Vector2Subtract(position, touchPoint);
        float overlapDistance = size - Vector2Length(pushForce);
        if (overlapDistance <= 0) {
            break;
        }
        pushForce = Vector2Normalize(pushForce);
        pushForce = Vector2Scale(pushForce, overlapDistance);
        position = Vector2Add(position, pushForce);
    }*/

}

void robot::draw() {
    if (currentmodus == robotmodus) {
        //DrawTexture(characterRobotTexture, position.x - 16, position.y - 32, WHITE);
        //DrawCircle(position.x, position.y, size, GRAY);
    }
    if (currentmodus == soulmodus) {
        //DrawCircle(position.x, position.y, size, BLACK);
        DrawTexture(robotFront, position.x-20, position.y-15, WHITE);
    }

}

void robot::deleteRobot() {
    UnloadTexture(robotFront);
}

robot::robot(gameplay *scene) {

}

robot::~robot() {}

