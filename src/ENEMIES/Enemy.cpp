//
// Created by lrfri on 04.06.2024.
//

#include "Enemy.h"
#include "../gameplay.h"
#include "Enemy1.h"
#include "raymath.h"
#include "../Wall.h"

int Enemy::attackPower = 1;

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
}

bool Enemy::checkCollision(const Wall &wall) { //Oli-> looks prettier than in Utils
    return Collision::checkCollision(*this, wall);
}

Rectangle Enemy::getCollisionRectangle() const{
    return Rectangle();
}


int Enemy::getHealth(const Enemy &enemy) {
    return enemy.health;
}

void Enemy::takeDamage(Enemy &enemy, int damage) {
    enemy.health -= damage;
    if (enemy.health < 0) {
        enemy.health = 0;
    }
}
//attack
void Enemy::setAttackPower (int damage) {
    int attackPower = damage;
}

void Enemy::attack(maincharacter* target) {
    target->health -= maincharacter::attackPower;
}
