//
// Created by lrfri on 04.06.2024.
//

#include "enemies.h"
#include "gameplayroom1.h"



//timer to have the enemies pause between steps instead of running nonstop
//(re-)start a timer
void enemies::StartTimer(Timer *timer, float pausetime) {
    if (timer != nullptr) { //timer has to be more than 0
        timer->Pausetime = pausetime;
    }
}

void enemies::UpdateTimer(Timer *timer) {
    if (timer != nullptr && timer->Pausetime > 0) {
        timer->Pausetime -= GetFrameTime(); //subtracts current frame from the timer (if timer isn't already at 0)
    }
}

bool enemies::TimerDone(Timer *timer) {
    if (timer != nullptr) {
        return timer->Pausetime <= 0;//returns true when the timer is done
    }else {return false;}
}

void enemies::getEnemyData() {

    if (enemyTypeNormal = true) {

        enemy1*getEnemyData();
    }
   // else if (enemyTypeRanged = true) {
    //    enemy2*getEnemyData();


    //if (enemyTypeX = true) {


    //enemy1::getEnemyData(); ich möchte auf die Daten von enemy1 zugreifen
    //wenn enemy 1 dann enemy.getEnemydata

}


void enemies::update() {

    /* Timer += Timer->GetTimeElapsed();
     int Random = (rand() % 4);
     if (Timer >= 2.0f)*/

    //movement with timer for the current enemy
    if(controltype==path||controltype==random) {
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

    for (int i = 0; _scene->touchesWall(position, size) && i < 4; i++) {
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

        if(controltype==random) {
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
}

void enemies::draw() {

    DrawTexture(enemyTexture1, position.x, position.y, WHITE);
    //DrawCircle(position.x, position.y, size, RED);
    DrawTexture(enemyTexture2, position.x-50, position.y,WHITE);


}

enemies::enemies(gameplayroom1 *scene): _scene(scene) {

}



