//
// Created by sadeh on 08.09.2024.
//

#include "HealthManager.h"
#include <algorithm>

HealthManager::HealthManager(int maxHealth) : m_maxHealth(maxHealth), m_currentHealth(maxHealth) {}

void HealthManager::takeDamage(int amount) {
    m_currentHealth = std::max(0, m_currentHealth - amount);
}

void HealthManager::heal(int amount) {
    m_currentHealth = std::min(m_maxHealth, m_currentHealth + amount);
}

bool HealthManager::isAlive() const {
    return m_currentHealth > 0;
}

float HealthManager::getHealthPercentage() const {
    return static_cast<float>(m_currentHealth) / m_maxHealth;
}

int HealthManager::getCurrentHealth() const {
    return m_currentHealth;
}

int HealthManager::getMaxHealth() const {
    return m_maxHealth;
}