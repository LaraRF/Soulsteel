//
// Created by lrfri on 19.06.2024.
//

#include "robot.h"
#include "../gameplay.h"

void robot::update() {

}

void robot::draw() {
    DrawCircle(position.x, position.y, size,GRAY);
    DrawTexture(characterRobotTexture, position.x-16, position.y-24, WHITE);
}

robot::robot() {

}
