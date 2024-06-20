//
// Created by lrfri on 04.06.2024.
//

#include "Enemy.h"
#include "../gameplay.h"
#include "Enemy1.h"


//timer to have the enemies pause between steps instead of running nonstop
//(re-)start a timer
void Enemy::StartTimer(Timer *timer, float pausetime) {
    if (timer != nullptr) { //timer has to be more than 0
        timer->Pausetime = pausetime;
    }
}

void Enemy::UpdateTimer(Timer *timer) {
    if (timer != nullptr && timer->Pausetime > 0) {
        timer->Pausetime -= GetFrameTime(); //subtracts current frame from the timer (if timer isn't already at 0)
    }
}

bool Enemy::TimerDone(Timer *timer) {
    if (timer != nullptr) {
        return timer->Pausetime <= 0;//returns true when the timer is done
    }else {return false;}
}

void Enemy::update() {

}


Enemy::Enemy(gameplay *scene) {

}


void Enemy::getEnemyData() {

}

void Enemy::getEnemyPosition() {

}
