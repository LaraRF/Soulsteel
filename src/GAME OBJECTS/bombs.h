//
// Created by lrfri on 19.06.2024.
//

#ifndef RAYLIBSTARTER_BOMBS_H
#define RAYLIBSTARTER_BOMBS_H

#include "raylib.h"
#include "gameobjects.h"
#include "../assestmanagergraphics.h"

class bombs : public gameobjects {
public:
    bombs(gameplay* scene, Vector2 position);
    void update() override;

    void draw() override;

    enum BombState {
        thrown,
        exploding,
        finished
    };
    BombState state;

private:
    float stateTimer;
    static const float thrown_duration;
    static const float exploding_duration;
    static const float explosion_radius;
    static const int explosiion_damage;

    Texture2D bomb_thrown = assestmanagergraphics::getTexture("item/bomb_thrown");
    Texture2D bomb_exploding = assestmanagergraphics::getTexture("item/bomb_exploding");

    void applyDamage();
};


#endif //RAYLIBSTARTER_BOMBS_H
