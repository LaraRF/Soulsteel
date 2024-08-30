//
// Created by lrfri on 04.06.2024.
//

#include "Enemy.h"
#include "../gameplay.h"
#include "Enemy1.h"
#include "raymath.h"
#include "../Wall.h"

int Enemy::attackPower = 1;
const int Enemy::MAX_HEALTH;


Enemy::Enemy(gameplay*scene, int hp, int damage, bool melee, bool ranged, bool armed,
             float left, float down, float right, float up)
        : _scene(scene), health(hp), enemyDamage(damage), enemyTypeMelee(melee), enemyTypeRanged(ranged), enemyTypeArmed(armed),
          stopleft(left), stopdown(down), stopright(right), stopup(up), stepsize(1.0f), controltype(Path),
          direction(static_cast<Direction>(Left)), m_health(hp) {
    this->health = hp; //initialization of health
    setAnimation("idle"); // Sets default animation
}

void Enemy::update() {

        if (!isAlive()) {
            // Handle enemy death (e.g., remove from game, play death animation, etc.)
            return;
        }
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
    updateAnimation();
    static constexpr int FRAME_COUNT = 8; // Add this line, adjust the value as needed
    static constexpr float FRAME_DURATION = 0.1f; // Add this line, adjust the value as needed

    float animationTimer;
    int currentFrame;
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

void Enemy::calculateDamage(Enemy& enemy, int damage) {
    enemy.takeDamage(damage);
}

int Enemy::getHealth(const Enemy& enemy) {
    return enemy.m_health;
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

void Enemy::updateAnimation() {
    animationTimer += GetFrameTime();
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0;
        currentFrame = (currentFrame + 1) % FRAME_COUNT;
    }
}

void Enemy::draw() {
    drawAnimation();
}

Texture2D Enemy::loadTexture(const std::string& animationName, const std::string& direction) {
    std::string textureName = "enemies_" + std::to_string(id) + "_" + animationName + "_" + direction;
    return assestmanagergraphics::getCharacterTexture("enemies", textureName);
}

void Enemy::drawAnimation() {
    if (animations.find(currentAnimationKey) != animations.end()) {
        const AnimationInfo& anim = animations[currentAnimationKey];
        DrawTextureRec(anim.texture,
                       Rectangle{static_cast<float>(currentFrame * anim.texture.width / anim.frameCount), 0.0f,
                                 static_cast<float>(anim.texture.width / anim.frameCount),
                                 static_cast<float>(anim.texture.height)},
                       Vector2{position.x - static_cast<float>(anim.texture.width) / (2.0f * anim.frameCount),
                               position.y - static_cast<float>(anim.texture.height) / 2.0f},
                       WHITE);
    }
}

void Enemy::setAnimation(const std::string& animationKey) {
    if (animations.find(animationKey) != animations.end() && animationKey != currentAnimationKey) {
        currentAnimationKey = animationKey;
        animationTimer = 0.0f;
        currentFrame = 0;
    }
}

//*NEW CODE*
void Enemy::takeDamage(int amount) {
    m_health = std::max(0, m_health - amount);
}

void Enemy::heal(int amount) {
    m_health = std::min(MAX_HEALTH, m_health + amount);
}

bool Enemy::isAlive() const {
    return m_health > 0;
}

float Enemy::getHealthPercentage() const {
    return static_cast<float>(m_health) / MAX_HEALTH;
}
