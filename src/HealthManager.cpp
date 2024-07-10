//
// Created by sadeh on 28.06.2024.
//

#include "HealthManager.h"
#include <iostream>

HealthManager::HealthManager(float maxHealth) : health(maxHealth), maxHealth(maxHealth) {}

float HealthManager::getCurrentHealth() const {
    return health;
}

void HealthManager::takeDamage(float damage) { //int damage no void
    health -= damage;
    if (health <= 0) {
        health = 0;
        isDead();
    }

}

bool HealthManager::isAlive() const {
    return health > 0;
}

void HealthManager::updateHealth() {
    if (health < 0)
        health = 0;
    if (health > maxHealth)
        health = maxHealth;
}

void HealthManager::resetHealth() {
    health = maxHealth;
}

