//
// Created by sadeh on 13.06.2024.
//

#include "Enemy1.h"


void Enemy1::getEnemyData() {
    Enemy1(nullptr,{position.x, position.y});
}

void Enemy1::getEnemyPosition() {
    //Vector2 position = {11 * 32, 32 * 5};
    stopleft = 6.0f * 32.0f - 16.0f;
    stopdown = 6 * 32 + 16;
    stopright = 6 * 32 - 16;
    stopup = 6 * 32 - 16;

}
void Enemy1::draw() {
    DrawTexture(enemyTexture1, position.x, position.y, WHITE);
}
void Enemy1::update() {
    //movement with timer for the current enemy
    if (controltype == path || controltype == random) {
        switch (direction) {
            case left:
                position.x = position.x - stepsize;
                StartTimer(&enemytimer, enemypause);
                UpdateTimer(&enemytimer);
                if (TimerDone(&enemytimer)) {
                    while (position.x >= stopleft) {
                        position.x = position.x - stepsize;
                        StartTimer(&enemytimer, enemypause);
                        UpdateTimer(&enemytimer);
                    }
                }
                if (position.x == stopleft) {
                    direction = down;
                }
                break;
            case down:
                position.y = position.y + stepsize;
                StartTimer(&enemytimer, enemypause);
                UpdateTimer(&enemytimer);
                if (TimerDone(&enemytimer)) {
                    while (position.y <= stopdown) {
                        position.y = position.y + stepsize;
                        StartTimer(&enemytimer, enemypause);
                        UpdateTimer(&enemytimer);
                    }
                }
                if (position.y == stopdown) {
                    direction = right;
                }
                break;
            case right:
                position.x = position.x + stepsize;
                StartTimer(&enemytimer, enemypause);
                UpdateTimer(&enemytimer);
                if (TimerDone(&enemytimer)) {
                    while (position.x <= stopright) {
                        position.x = position.x + stepsize;
                        StartTimer(&enemytimer, enemypause);
                        UpdateTimer(&enemytimer);
                    }
                }
                if (position.x == stopright) {
                    direction = up;
                }
                break;
            case up:
                position.y = position.y - stepsize;
                StartTimer(&enemytimer, enemypause);
                UpdateTimer(&enemytimer);
                if (TimerDone(&enemytimer)) {
                    while (position.y >= stopup) {
                        position.y = position.y - stepsize;
                        StartTimer(&enemytimer, enemypause);
                        UpdateTimer(&enemytimer);
                    }
                }
                if (position.y == stopup) {
                    direction = left;
                }
                break;
        }
    }
    //end movement code

    /* for (int i = 0; _scene->touchesWall(position, size) && i < 4; i++) {
         Rectangle touchedWall = _scene->getTouchedWall(position, size);
         Vector2 touchPoint = Vector2Clamp(position, {touchedWall.x, touchedWall.y},
                                           {touchedWall.x + touchedWall.width,
                                            touchedWall.y + touchedWall.height});
         Vector2 pushForce = Vector2Subtract(position, touchPoint);
         float overlapDistance = size - Vector2Length(pushForce);
         if (overlapDistance <= 0) {
             break;
         }
         pushForce = Vector2Normalize(pushForce);
         pushForce = Vector2Scale(pushForce, overlapDistance);
         position = Vector2Add(position, pushForce);

         if (controltype == path) {
             switch (direction) {
                 case left:
                     direction = down;
                     break;
                 case down:
                     direction = right;
                     break;
                 case right:
                     direction = up;
                     break;
                 case up:
                     direction = left;
                     break;
             }
         }

     }
 }*/
}
Enemy1::~Enemy1() {
}