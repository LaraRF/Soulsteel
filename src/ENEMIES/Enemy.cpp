//
// Created by lrfri on 04.06.2024.
//

#include "Enemy.h"
#include "../gameplay.h"
#include "Enemy1.h"
#include "raymath.h"


Enemy::Enemy(float hp, int damage, bool melee, bool ranged, bool armed,
             float left, float down, float right, float up)
        : enemyDamage(damage), enemyTypeMelee(melee), enemyTypeRanged(ranged), enemyTypeArmed(armed),
          stopleft(left), stopdown(down), stopright(right), stopup(up), stepsize(1.0f), controltype(Path),
          direction(Left) {
}

void Enemy::update() {
    if (controltype == Path) {
        moveOnPath();
    } else if (controltype == Random) {
        moveRandomly();
    }
}

int Enemy::getCurrentHealth() {

    health -= damage;
    if (health <= 0) {
        health = 0;
    }
    if (health < 0) {
        health = 0;
        if (health > maxHealth) {
            health = maxHealth;
        }
        return health;
    }
}

int Enemy::calculateDamage() {


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
    Delta = Vector2Subtract(target,position);

    if (Vector2Length(Delta) > stepsize){
        Delta = Vector2Scale(Vector2Normalize(Delta),stepsize);
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