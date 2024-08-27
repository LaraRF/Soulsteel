//
// Created by lrfri on 19.06.2024.
//

#include "bombs.h"
#include "../gameplay.h"

const float bombs::thrown_duration = 0.5f;
const float bombs::exploding_duration = 0.5f;
const float bombs::explosion_radius = 64.0f;
const int bombs::explosiion_damage = 2;

bombs::bombs(gameplay* scene, Vector2 position) : gameobjects(scene) {
    this->position = position;
    state = thrown;
    stateTimer = 0;
}

void bombs::update() {
    stateTimer += GetFrameTime();

    switch (state) {
        case thrown:
            if (stateTimer >= thrown_duration) {
                state = exploding;
                stateTimer = 0;
            }
            break;
        case exploding:
            if (stateTimer >= exploding_duration) {
                applyDamage();
                state = finished;
            }
            break;
        case finished:
            // The bomb will be deleted in the gameplay class
            break;
    }
}

void bombs::draw() {
    switch (state) {
        case thrown:
            DrawTexture(bomb_thrown, position.x - bomb_thrown.width / 2, position.y - bomb_thrown.height / 2, WHITE);
            break;
        case exploding:
            DrawTexture(bomb_exploding, position.x - bomb_exploding.width / 2, position.y - bomb_exploding.height / 2, WHITE);
            break;
        case finished:
            // Don't draw anything
            break;
    }
}
void bombs::applyDamage() {
    // Placeholder function for applying damage
    // TODO: Implement damage application to characters and enemies within explosion_radius
    // Implement this function later when damage system exists
}