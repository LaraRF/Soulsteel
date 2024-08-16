//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"
#include "scene.h"

int maincharacter::attackPower = 2;

void maincharacter::update() {


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
    }


    //allows you to switch between soul and robot functions
    switch (currentmodus) {
        case soulmodus:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = robotmodus;
            }
            //souldash
            if (IsKeyPressed(KEY_I)) {
                souldashactivated=true;
                souldash();
            }
            else{
                souldashactivated=false;
            }
            //soul dust

            break;
        case robotmodus:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = soulmodus;
            }


            //bomb throwing
            /*if(IsKeyPressed(KEY_B)){
                if(!bombhasbeenplaced){
                throwbomb=true;
                throwingposx=position.x;
                throwingposy=position.y;
                }
                if(bombhasbeenplaced){

                }
            }*/

            //space for more robot function
            break;
    }
//COLLISION WALL
    for (int i = 0; _scene->touchesWall(position, size) && i < 4; i++) {
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
    }
//COLISSION WITH ENEMY

    const std::vector<Enemy *> &enemies = _scene->getEnemies();

    for (int i = 0; i < enemies.size(); i++) {
        if (Collision::checkCollision(*this, *enemies[i])) {
            Rectangle enemyRect = enemies[i]->getCollisionRectangle();
            for (int j = 0; j < 4; j++) {
                Vector2 touchPoint = Vector2Clamp(position, {enemyRect.x, enemyRect.y},
                                                  {enemyRect.x + enemyRect.width, enemyRect.y + enemyRect.height});
                Vector2 pushForce = Vector2Subtract(position, touchPoint);
                float overlapDistance = size - Vector2Length(pushForce);
                if (overlapDistance <= 0) {
                    break;
                }
                pushForce = Vector2Normalize(pushForce);
                pushForce = Vector2Scale(pushForce, overlapDistance);
                position = Vector2Add(position, pushForce);
            }
        }
    }


    if (!souldashactivated) {
        for (int i = 0; _scene->touchesBars(position, size) && i < 4; i++) {
            Rectangle touchedBars = _scene->getTouchedBars(position, size);
            Vector2 touchPoint = Vector2Clamp(position, {touchedBars.x, touchedBars.y},
                                              {touchedBars.x + touchedBars.width, touchedBars.y + touchedBars.height});
            Vector2 pushForce = Vector2Subtract(position, touchPoint);
            float overlapDistance = size - Vector2Length(pushForce);
            if (overlapDistance <= 0) {
                break;
            }
            pushForce = Vector2Normalize(pushForce);
            pushForce = Vector2Scale(pushForce, overlapDistance);
            position = Vector2Add(position, pushForce);
        }
    }
}

void maincharacter::souldash() {
    switch (lookingdirection) {
        case north:
            position.y = position.y - stepsizesouldash;
            break;
        case east:
            position.x = position.x + stepsizesouldash;
            break;
        case south:
            position.y = position.y + stepsizesouldash;
            break;
        case west:
            position.x = position.x - stepsizesouldash;
            break;
    }
}

void maincharacter::drawsoul() {


    DrawCircle(position.x, position.y, size, PINK);
    DrawTexture(characterSoulTexture, position.x - 16, position.y - 24, WHITE);
    /*if (souldashactivated) {
        DrawText("Souldash activated", 10, 10, 10, WHITE);
    } else if (!souldashactivated) {
        DrawText("Souldash deactivated", 10, 10, 10, WHITE);
    }*/

}


void maincharacter::drawrobot() {

    //DrawCircle(position.x, position.y, size,GRAY);
    DrawTexture(characterRobotTexture, position.x - 16, position.y - 32, WHITE);

}

maincharacter::maincharacter(gameplay *scene) : _scene(scene) {

}

Rectangle maincharacter::getCollisionRectangle() const {
    return Rectangle{position.x - size / 2, position.y - size / 2, size, size};
}

//attack
void maincharacter::attack(Enemy *target) {
    target->health -= Enemy::attackPower;

}

int getHealth(const maincharacter &maincharacter) {
    return maincharacter.health;
}

void calculateDamage(maincharacter &maincharacter, int damage) {
    maincharacter.health -= damage;
    if (maincharacter.health < 0) {
        maincharacter.health = 0;
    }
}

void setAttackPower(int attack) {
    int attackPower = attack;
}
