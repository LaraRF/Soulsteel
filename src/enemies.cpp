//
// Created by lrfri on 04.06.2024.
//

#include "enemies.h"


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

void enemies::update() {

    /* Timer += Timer->GetTimeElapsed();
     int Random = (rand() % 4);
     if (Timer >= 2.0f)*/

    //movement with timer for the current enemy
    StartTimer(&enemytimer, enemypause);
    UpdateTimer(&enemytimer);
    switch (direction) {
        case left:
            position.x = position.x - stepsize;
            StartTimer(&enemytimer, enemypause);
            UpdateTimer(&enemytimer);
            if(TimerDone(&enemytimer)) {
                while (position.x >= 10 * 32 - 16) {
                    position.x = position.x - stepsize;
                    StartTimer(&enemytimer, enemypause);
                    UpdateTimer(&enemytimer);
                }
            }
                if(position.x==10*32-16){
                    direction = down;
                }
            break;
        case down:
            position.y = position.y + stepsize;
            StartTimer(&enemytimer, enemypause);
            UpdateTimer(&enemytimer);
            if(TimerDone(&enemytimer)) {
                while(position.y <= (12 * 32+16)) {
                    position.y = position.y + stepsize;
                    StartTimer(&enemytimer, enemypause);
                    UpdateTimer(&enemytimer);
                }
            }
            if(position.y == (12 * 32+16)){
            direction = right;
            }
            break;
        case right:
            position.x = position.x + stepsize;
            StartTimer(&enemytimer, enemypause);
            UpdateTimer(&enemytimer);
            if(TimerDone(&enemytimer)) {
                while(position.x <= (14 * 32-16)) {
                    position.x = position.x + stepsize;
                    StartTimer(&enemytimer, enemypause);
                    UpdateTimer(&enemytimer);
                }
            }
            if(position.x==(14 * 32-16)) {
                direction = up;
            }
            break;
        case up:
            position.y = position.y - stepsize;
            StartTimer(&enemytimer, enemypause);
            UpdateTimer(&enemytimer);
            if(TimerDone(&enemytimer)) {
                while(position.y >= (10 * 32-16)) {
                    position.y = position.y - stepsize;
                    StartTimer(&enemytimer, enemypause);
                    UpdateTimer(&enemytimer);
                }
            }
            if(position.y==(10 * 32-16)) {
                direction = left;
            }
            break;
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
        if(controltype==1) {
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


}

enemies::enemies(gameplay *scene) : _scene(scene) {

}

