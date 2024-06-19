//
// Created by lrfri on 19.06.2024.
//

#include "robot.h"

void robot::update() {

}

void robot::draw() {
    DrawTexture(characterRobotTexture, position.x, position.y, WHITE);
}

robot::~robot() {}