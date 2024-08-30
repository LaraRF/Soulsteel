//
// Created by lrfri on 04.06.2024.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#include "../gameplay.h"
#include "raylib.h"
#include "../scene.h"
#include "raymath.h"
#include "../enemymodus.h"
#include <iostream>
#include "../Enums.h"
#include "../Utils.h"

enum ControlType {
    Path,
    Random
};

enum ControlRandom {
    RandomStart,
    RandomWalk,
    RandomStop,
};

class gameplay;
class Wall;

class Enemy{

public:
    Enemy(gameplay*scene,int hp, int damage, bool melee, bool ranged, bool armed,
          float left, float down, float right, float up);

    //position
    float stopleft;
    float stopdown;
    float stopright;
    float stopup;
    Vector2 position{}; //current position of enemy

    int id = 0;

    //health
    int health;
    int getHealth(const Enemy& enemy);
    void calculateDamage(Enemy& enemy, int damage);

    //attack
    static int attackPower;
    void setAttackPower(int damage);
    void attack(maincharacter* target);

    virtual void update();
    virtual void draw() = 0;

    void calculatePathAsRectangle();

    void setAnimation(const std::string& animationKey);

    virtual void drawAnimation();

    ControlType controltype;

    gameplay *_scene;

    Enemy(gameplay *scene);

    virtual ~Enemy() = default; //virtual destructor for proper cleanup

    std::vector<Vector2> path; // stores the path the enemy will follow

    //Collision check
    bool checkCollision(const Wall &wall);

    Rectangle getCollisionRectangle() const;

    //*NEW CODE*
    static const int MAX_HEALTH = 10;
    void takeDamage(int amount);
    void heal(int amount);
    bool isAlive() const;
    float getHealthPercentage() const;

    int m_health = MAX_HEALTH;


protected:
    //animation enemy
    enum class AnimationState { IDLE, WALK, ATTACK, SPECIAL};
    enum class Direction { Left, Right, Up, Down };

    AnimationState currentAnimationState;
    float animationTimer;
    int currentFrame;
    Direction facingDirection;
    std::string currentAnimation;
    Direction facing;

    static constexpr int FRAME_COUNT = 8; // Add this line, adjust the value as needed
    static constexpr float FRAME_DURATION = 0.1f; // Add this line, adjust the value as needed


    struct AnimationInfo {
        int frameCount;
        float duration;
        Texture2D texture;
    };

    std::map<std::string, AnimationInfo> animations;
    std::string currentAnimationKey;


    virtual void loadAnimations() = 0;


    // New method to handle animations

    virtual void updateAnimation();
    virtual Texture2D getCurrentTexture() = 0;

    // Texture loading helper
    Texture2D loadTexture(const std::string& animationName, const std::string& direction);


    int enemyHP{};
    int enemyDamage{};
    bool enemyTypeMelee{};
    bool enemyTypeRanged{};
    bool enemyTypeArmed{};

    //health
    int maxHealth{};
    int damage{};

    // position and direction
    Direction direction{};
    ControlRandom controlrandom;

    float stepsize = 2;
    float size = 12;
    int currentPathIndex = 0;

    //methods for movement: path or random
    virtual void moveOnPath();
    virtual void moveRandomly();

    void takeDamage(Enemy &enemy, int damage);
};



#endif //RAYLIBSTARTER_ENEMY_H
