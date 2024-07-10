//
// Created by sadeh on 28.06.2024.
//

#ifndef RAYLIBSTARTER_HEALTHMANAGER_H
#define RAYLIBSTARTER_HEALTHMANAGER_H


class HealthManager {
public:
    HealthManager(float maxHealth);

    float getCurrentHealth() const;
    void takeDamage(float damage);
    bool isAlive() const;
    void updateHealth();
    void resetHealth();
    virtual void isDead() = 0;

protected:
    float health;
    float maxHealth;
};


#endif //RAYLIBSTARTER_HEALTHMANAGER_H
