//
// Created by lrfri on 04.06.2024.
//

#include "Enemy.h"
#include "../gameplay.h"
#include "Enemy1.h"
#include "raymath.h"
#include "../Wall.h"


Enemy::Enemy(gameplay*scene, int hp, int damage, bool melee, bool ranged, bool armed,
             float left, float down, float right, float up)
        : _scene(scene), health(hp), enemyDamage(damage), enemyTypeMelee(melee), enemyTypeRanged(ranged), enemyTypeArmed(armed),
          stopleft(left), stopdown(down), stopright(right), stopup(up), stepsize(1.0f), controltype(Path),
          direction(Left) {
    this->health = hp; //initialization of health
}

void Enemy::update() {
    if (controltype == Path) {
        moveOnPath();
    } else if (controltype == Random) {
        moveRandomly();
    }
    //Collision Wall
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

    /*Wall aWall;
    if (checkCollision(aWall)) {
        if (Enemy::controltype == Path) {
            Enemy::controltype = Random; // Change to random movement upon collision
        } else {
            // Reverses direction
            if (Enemy::direction == Left) {
                Enemy::direction = Right;
            } else if (Enemy::direction == Right) {
                Enemy::direction = Left;
            } else if (Enemy::direction == Up) {
                Enemy::direction = Down;
            } else if (Enemy::direction == Down) {
                Enemy::direction = Up;
        }
        }
    }*/
}

void Enemy::calculatePathAsRectangle() {
    path.clear();
    path.push_back({stopleft, stopup});
    path.push_back({stopright, stopup});
    path.push_back({stopright, stopdown});
    path.push_back({stopleft, stopdown});
}

void Enemy::moveOnPath() {

    if (currentPathIndex >= path.size()) {
        currentPathIndex = 0;
    }
    Vector2 Delta{};
    Vector2 target = path[currentPathIndex];
    Delta = Vector2Subtract(target, position);

    if (Vector2Length(Delta) > stepsize) {
        Delta = Vector2Scale(Vector2Normalize(Delta), stepsize);
    }
    position = Vector2Add(position, Delta);

    // if statement for checking if the enemy reached current target
    if (Vector2Distance(position, target) <= stepsize * 2) {
        currentPathIndex++;
    }
}

void Enemy::moveRandomly() {

    //mit getrandom von raylib

    /*if (currentPathIndex >= path.size()) {
        currentPathIndex = 0;
    }
    Vector2 target = path[currentPathIndex];
    if (position.x < target.x) {
        position.x += stepsize;
    } else if (position.x > target.x) {
        position.x -= stepsize;
    }

    if (position.y < target.y) {
        position.y += stepsize;
    } else if (position.y > target.y) {
        position.y -= stepsize;
    }


    // if statement for checking if the enemy reached current target
    if (Vector2Distance(position, target) <= stepsize * 2) {
        currentPathIndex++;
    }*/

/*switch (direction) {
    case Left:

        break;
    case Down:
        position.y += stepsize;
        if (position.y >= stopdown) {
            direction = Right;
        }
        break;
    case Right:
        position.x += stepsize;
        if (position.x >= stopright) {
            direction = Up;
        }
        break;
    case Up:
        position.y -= stepsize;
        if (position.y <= stopup) {
            direction = Left;
        }
        break;
}/*/
}

bool Enemy::checkCollision(const Wall &wall) { //Oli-> sieht so hübscher aus wie in Utils
    return Collision::checkCollision(*this, wall);
}

Rectangle Enemy::getCollisionRectangle() const{
    return Rectangle();
}


int getHealth(const Enemy &enemy) {
    return enemy.health;
}

void takeDamage(Enemy &enemy, int damage) {
    enemy.health -= damage;
    if (enemy.health < 0) {
        enemy.health = 0;
    }
}