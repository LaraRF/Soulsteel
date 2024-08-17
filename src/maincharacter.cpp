//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"
#include "scene.h"

int maincharacter::attackPower = 2;

void maincharacter::update() {

    maincharacterwalking();

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
            souldustcanbeused();

            break;
        case robotmodus:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = soulmodus;
            }


            //bomb throwing

            //space for more robot function
            break;
    }
//collisions
    collisionwall();
    collisionenemies();
    collisionbars();
    collisionabyss();
    updateLastSafePosition();
}

void maincharacter::maincharacterwalking() {
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
}

void maincharacter::collisionwall() {
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
}

void maincharacter::collisionenemies() {
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
}

void maincharacter::collisionbars() {
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

void maincharacter::collisionabyss() {
    if (_scene->touchesAbyss(position, size)) {
        if (currentmodus == robotmodus || (currentmodus == soulmodus && !souldashactivated)) {
            // Robot or non-dashing soul falls into abyss, soul using dash is fine
            health--; // Lose one heart
            felldown=true;
            position = lastSafePosition; // Reset position

            //falling animation or something here

        }
    }
    else {
        updateLastSafePosition();
        felldown=false;
    }
}

void maincharacter::souldash() {
    Vector2 newPosition = position;
    switch (lookingdirection) {
        case north:
            newPosition.y -= stepsizesouldash;
            break;
        case east:
            newPosition.x += stepsizesouldash;
            break;
        case south:
            newPosition.y += stepsizesouldash;
            break;
        case west:
            newPosition.x -= stepsizesouldash;
            break;
    }

    // Check if the new position is valid (not inside a wall)
    for (int i = 0; i <= stepsizesouldash; i++) {
        Vector2 checkPosition = Vector2Lerp(position, newPosition, (float)i / stepsizesouldash);
        if (_scene->touchesWall(checkPosition, size)) {
            // If we hit a wall, stop at the previous valid position
            newPosition = Vector2Lerp(position, newPosition, (float)(i-1) / stepsizesouldash);
            break;
        }
    }

    position = newPosition;
}

bool maincharacter::souldustcanbeused() const {
    return _scene->isAdjacentToFirebowl(position);
}

void maincharacter::souldust(){
    if (souldustcanbeused() && IsKeyPressed(KEY_L)) {
        auto [bowlX, bowlY] = _scene->getNearestFirebowlTile(position);
        if (bowlX != -1 && bowlY != -1 && !_scene->isFirebowlActivated(bowlX, bowlY)) {
            _scene->activateFirebowl(bowlX, bowlY);
        }
    }
}

void maincharacter::updateLastSafePosition() {
    if (!_scene->touchesAbyss(position, size)) {
        lastSafePosition = position;
    }
}

void maincharacter::draw() {
    if(felldown){
        DrawText("You fell into the abyss. You lost one life.", 10*15, 7*15, 20, RED);
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

    if (souldustcanbeused()) {
        DrawText("Press L to use Soul Dust", position.x - 50, position.y - 40, 10, YELLOW);
    }

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
