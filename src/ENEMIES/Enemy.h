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
    int health;

    virtual void update();
    virtual void draw() = 0;

    void calculatePathAsRectangle();

    int getHealth(const Enemy& enemy);
    void calculateDamage(Enemy& enemy, int damage);

    ControlType controltype;

    gameplay *_scene;

    Enemy(gameplay *scene);

    //Textures
    Texture2D enemyTexture1 = assestmanagergraphics::getTexture("characters/enemies/enemy_1");
    Texture2D enemyTexture2 = assestmanagergraphics::getTexture("characters/enemies/enemy_2");
    Texture2D enemyTexture3 = assestmanagergraphics::getTexture("characters/enemies/enemy_3");

    virtual ~Enemy() = default; //virtual destructor for proper cleanup

    std::vector<Vector2> path; // stores the path the enemy will follow

    //Collision check
    bool checkCollision(const Wall &wall);

    Rectangle getCollisionRectangle() const;


protected:
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

};



#endif //RAYLIBSTARTER_ENEMY_H
